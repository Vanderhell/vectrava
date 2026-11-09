#include "pc_rotation_matrix2_from_angle_q.h"
#include "pc_quat_from_axis_angle_q.h"
#include <limits.h>
#include <stddef.h>

#define ONE INT32_C(1073741824)

static int64_t round_shift_q30(int64_t value)
{
    uint64_t magnitude=value<0?(uint64_t)(-value):(uint64_t)value;
    uint64_t q=magnitude>>30;
    uint64_t r=magnitude&((UINT64_C(1)<<30)-1u);
    if(r>(UINT64_C(1)<<29)||(r==(UINT64_C(1)<<29)&&(q&1u)))++q;
    return value<0?-(int64_t)q:(int64_t)q;
}

static int32_t clamp_q30(int64_t value)
{
    if(value>ONE)return ONE;
    if(value< -ONE)return -ONE;
    return (int32_t)value;
}

bool pc_rotation_matrix2_from_angle_q(uint32_t angle,pc_matrix2_q *output)
{
    const int32_t z_axis[3]={0,0,ONE};
    int32_t q[4];
    pc_matrix2_q result;
    int64_t cos_q30,sin_q30;
    if(output==NULL)return false;
    if(!pc_quat_from_axis_angle_q(z_axis,angle,q))return false;
    cos_q30=round_shift_q30((int64_t)q[0]*q[0]-(int64_t)q[3]*q[3]);
    sin_q30=round_shift_q30(INT64_C(2)*(int64_t)q[0]*q[3]);
    result.element[0]=clamp_q30(cos_q30);
    result.element[1]=clamp_q30(-sin_q30);
    result.element[2]=clamp_q30(sin_q30);
    result.element[3]=clamp_q30(cos_q30);
    *output=result;
    return true;
}
