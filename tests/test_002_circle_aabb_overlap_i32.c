#include "pc_circle_aabb_overlap_i32.h"
#include <assert.h>
#include <stdint.h>
static uint32_t state=UINT32_C(0xaabb1619);
static uint32_t rnd(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static int32_t sv(void){uint32_t u=rnd();if(u<=(uint32_t)INT32_MAX)return(int32_t)u;return(int32_t)(-(int32_t)(UINT32_MAX-u)-1);}
static uint64_t sqgap(int32_t p,int32_t lo,int32_t hi){int64_t d=0;if(p<lo)d=(int64_t)lo-p;else if(p>hi)d=(int64_t)p-hi;uint64_t m=(uint64_t)d;return m*m;}
static int oracle(int32_t cx,int32_t cy,uint32_t r,int32_t x0,int32_t y0,int32_t x1,int32_t y1){if(x0>x1||y0>y1)return 0;uint64_t b=(uint64_t)r*r,dx=sqgap(cx,x0,x1);return dx<=b&&sqgap(cy,y0,y1)<=b-dx;}
int main(void){
 for(int32_t x0=-2;x0<=2;++x0)for(int32_t x1=-2;x1<=2;++x1)for(int32_t y0=-2;y0<=2;++y0)for(int32_t y1=-2;y1<=2;++y1)for(int32_t cx=-3;cx<=3;++cx)for(int32_t cy=-3;cy<=3;++cy)for(uint32_t r=0;r<5;++r)assert(pc_circle_aabb_overlap_i32(cx,cy,r,x0,y0,x1,y1)==oracle(cx,cy,r,x0,y0,x1,y1));
 for(unsigned i=0;i<100000;++i){int32_t v[6];for(unsigned k=0;k<6;++k)v[k]=sv();uint32_t r=rnd();assert(pc_circle_aabb_overlap_i32(v[0],v[1],r,v[2],v[3],v[4],v[5])==oracle(v[0],v[1],r,v[2],v[3],v[4],v[5]));}
 return 0;
}
