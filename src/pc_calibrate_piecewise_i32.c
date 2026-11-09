#include "pc_calibrate_piecewise_i32.h"
#include <stddef.h>
#include <stdint.h>

static uint64_t magnitude_delta(int32_t a, int32_t b)
{
    if (b >= a) return (uint64_t)((uint32_t)b - (uint32_t)a);
    return (uint64_t)((uint32_t)a - (uint32_t)b);
}

static int32_t interpolate(const rm_calibration_point_i32 *left,
                           const rm_calibration_point_i32 *right,
                           int32_t input)
{
    uint64_t dx = magnitude_delta(left->input, right->input);
    uint64_t t = magnitude_delta(left->input, input);
    int increasing = right->output >= left->output;
    uint64_t dy = increasing ? magnitude_delta(left->output, right->output)
                             : magnitude_delta(right->output, left->output);
    uint64_t product = t * dy;
    uint64_t q = product / dx;
    uint64_t rem = product % dx;
    int64_t base = (int64_t)left->output + (increasing ? (int64_t)q : -(int64_t)q);
    if (rem != 0u) {
        uint64_t twice = rem * 2u;
        if (increasing) {
            if (twice > dx || (twice == dx && base >= 0)) ++base;
        } else {
            if (twice > dx || (twice == dx && base <= 0)) --base;
        }
    }
    return (int32_t)base;
}

bool rm_calibrate_piecewise_i32(const rm_calibration_point_i32 *points,
                                 uint8_t count, int32_t input, int32_t *output)
{
    uint16_t i;
    int32_t result;
    if (points == NULL || output == NULL || count < 2u) return false;
    for (i = 1u; i < (uint16_t)count; ++i) {
        if (points[i - 1u].input >= points[i].input) return false;
    }
    if (input <= points[0].input) result = points[0].output;
    else if (input >= points[(uint16_t)count - 1u].input)
        result = points[(uint16_t)count - 1u].output;
    else {
        result = points[0].output;
        for (i = 0u; i + 1u < (uint16_t)count; ++i) {
            if (input == points[i].input) { result = points[i].output; break; }
            if (input < points[i + 1u].input) {
                result = interpolate(&points[i], &points[i + 1u], input);
                break;
            }
        }
    }
    *output = result;
    return true;
}
