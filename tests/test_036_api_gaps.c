#include "pc_affine2_apply_q.h"
#include "pc_bearing2_q.h"
#include "pc_calibrate_piecewise_i32.h"
#include "pc_checked_add_i64.h"
#include "pc_distance_to_stop_q.h"
#include "pc_homogeneous2_apply_q.h"
#include "pc_piecewise_segment_index_i32.h"
#include "pc_q_hypot3.h"
#include "pc_ring_distance_forward_u32.h"
#include "pc_segment_progress_q.h"
#include "pc_tof_distance_from_time_q.h"
#include "pc_tof_time_from_distance_q.h"
#include "pc_trajectory_segment_select_u32.h"
#include "pc_translate_point2_i32.h"
#include "pc_waypoint_distance2_i32.h"
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t rng_state = UINT32_C(0x73A4B91D);
static uint32_t rng(void) {
    rng_state ^= rng_state << 13; rng_state ^= rng_state >> 17;
    rng_state ^= rng_state << 5; return rng_state;
}
static int32_t signed32(uint32_t x) {
    return x <= INT32_MAX ? (int32_t)x : (int32_t)((int64_t)x - INT64_C(4294967296));
}
static uint64_t round_even(long double x) {
    long double q = floorl(x), r = x-q;
    uint64_t n=(uint64_t)q;
    if (r>0.5L || (r==0.5L && (n&1u))) ++n;
    return n;
}
static uint32_t phase_error(uint32_t a,uint32_t b) {
    uint32_t d=a-b; return d < (uint32_t)(0u-d) ? d : (uint32_t)(0u-d);
}
int main(void) {
    int64_t i64=7; uint64_t u64=7; int32_t i32=7, pair[2]={9,10}, out3[3]={7,8,9};
    uint32_t u32=7; size_t si=99; uint8_t u8=99;
    pc_matrix2_q m={{65536,0,0,65536}};
    pc_calibration_point_i32 cp[3]={{0,0},{10,15},{20,20}};
    const uint32_t knots[]={0,10,20};
    const int32_t identity3[]={65536,0,0,0,65536,0,0,0,65536};
    unsigned n;
    uint32_t max_bearing_error = 0u;

    assert(pc_checked_add_i64(INT64_MAX,0,&i64) && i64==INT64_MAX);
    i64=7; assert(!pc_checked_add_i64(INT64_MAX,1,&i64) && i64==7);
    assert(pc_translate_point2_i32(-5,8,3,-2,&pair[0],&pair[1]) && pair[0]==-2 && pair[1]==6);
    pair[0]=9; pair[1]=10; assert(!pc_translate_point2_i32(INT32_MAX,0,1,0,&pair[0],&pair[1]) && pair[0]==9 && pair[1]==10);
    assert(pc_waypoint_distance2_i32(INT32_MIN,INT32_MIN,INT32_MAX,INT32_MAX,&u64)==0 && u64==7);
    assert(pc_waypoint_distance2_i32(0,0,3,4,&u64) && u64==25);
    assert(pc_distance_to_stop_q(-3*65536,65536,&u64) && u64==UINT64_C(9)*32768);
    u64=7; assert(!pc_distance_to_stop_q(1,0,&u64) && u64==7);
    assert(pc_affine2_apply_q(&m,(int32_t[2]){12,-8},(int32_t[2]){3,4},16,out3) && out3[0]==15 && out3[1]==-4);
    assert(pc_homogeneous2_apply_q(identity3,(int32_t[3]){12,-8,65536},16,out3) && out3[0]==12 && out3[1]==-8 && out3[2]==65536);
    assert(pc_calibrate_piecewise_i32(cp,3,5,&i32) && i32==8);
    assert(pc_calibrate_piecewise_i32(cp,3,30,&i32) && i32==20);
    assert(pc_piecewise_segment_index_i32(cp,3,10,&u8) && u8==1);
    assert(pc_ring_distance_forward_u32(UINT32_MAX-1u,1u,UINT32_MAX,&u32) && u32==2u);
    assert(pc_segment_progress_q(0,0,100,0,50,20,&u32) && u32==32768u);
    assert(pc_trajectory_segment_select_u32(knots,3,10,&si) && si==1u);
    assert(pc_tof_distance_from_time_q(1000,343000,&u64) && u64==171500u);
    assert(pc_tof_time_from_distance_q(171500,343000,&u64) && u64==1000u);
    assert(pc_q_hypot3(3,4,12,&i32) && i32==13);
    i32=7; assert(!pc_q_hypot3(INT32_MIN,INT32_MIN,INT32_MIN,&i32) && i32==7);

    /* All eight axis-aligned bearings, including wrap at one full turn. */
    {
        const int32_t xy[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
        const uint32_t expected[8]={0u,UINT32_C(0x20000000),UINT32_C(0x40000000),UINT32_C(0x60000000),UINT32_C(0x80000000),UINT32_C(0xA0000000),UINT32_C(0xC0000000),UINT32_C(0xE0000000)};
        for(n=0;n<8;n++){assert(pc_bearing2_q(0,0,xy[n][0],xy[n][1],&u32));assert(phase_error(u32,expected[n])<=8u);}
        assert(pc_bearing2_q(INT32_MIN,0,INT32_MAX,0,&u32) && u32==0u);
        assert(pc_bearing2_q(INT32_MAX,0,INT32_MIN,0,&u32) && u32==UINT32_C(0x80000000));
        assert(pc_bearing2_q(0,INT32_MIN,0,INT32_MAX,&u32) && phase_error(u32,UINT32_C(0x40000000))<=24u);
        assert(pc_bearing2_q(INT32_MIN,INT32_MAX,INT32_MIN,INT32_MAX,&u32) && u32==0u);
    }
    /* Independent long-double references across the full int32 coordinate box. */
    for(n=0;n<100000u;n++) {
        int32_t ox=signed32(rng()), oy=signed32(rng());
        int32_t tx=signed32(rng()), ty=signed32(rng());
        int32_t x=signed32(rng()), y=signed32(rng()), z=signed32(rng());
        uint32_t got;
        int64_t dx=(int64_t)tx-ox, dy=(int64_t)ty-oy;
        uint32_t error;
        if(dx==0 && dy==0) { tx = tx == INT32_MAX ? tx-1 : tx+1; dx=(int64_t)tx-ox; }
        assert(pc_bearing2_q(ox,oy,tx,ty,&got));
        {
            long double turns=atan2l((long double)dy,(long double)dx)/(2.0L*acosl(-1.0L));
            if(turns<0.0L)turns+=1.0L;
            uint32_t ref=(uint32_t)(uint64_t)floorl(turns*4294967296.0L+0.5L);
            error=phase_error(got,ref);
            if(error>max_bearing_error)max_bearing_error=error;
            assert(error<=24u);
        }
        {
            long double norm=sqrtl((long double)x*x+(long double)y*y+(long double)z*z);
            uint64_t ref=round_even(norm);
            if(ref<=INT32_MAX) {assert(pc_q_hypot3(x,y,z,&i32));assert((uint64_t)i32==ref);}
            else {i32=7;assert(!pc_q_hypot3(x,y,z,&i32)&&i32==7);}
        }
    }
    printf("PASS: 15 previously untested APIs; 100000 full-range bearing/norm differentials; max bearing error=%u Q0.32 codes\n",max_bearing_error);
    return 0;
}
