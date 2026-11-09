#include "pc_circle_aabb_overlap_i32.h"

static uint64_t square_gap(int32_t p,int32_t lo,int32_t hi)
{
    int64_t d=0;
    if(p<lo)d=(int64_t)lo-p;
    else if(p>hi)d=(int64_t)p-hi;
    {
        uint64_t m=(uint64_t)d;
        return m*m;
    }
}

bool pc_circle_aabb_overlap_i32(int32_t cx,int32_t cy,uint32_t radius,
                                int32_t min_x,int32_t min_y,int32_t max_x,int32_t max_y)
{
    uint64_t budget=(uint64_t)radius*radius;
    uint64_t q;
    if(min_x>max_x||min_y>max_y)return false;
    q=square_gap(cx,min_x,max_x);
    if(q>budget)return false;
    budget-=q;
    return square_gap(cy,min_y,max_y)<=budget;
}
