#include "pc_sphere_aabb_overlap_i32.h"
#include <assert.h>
#include <stdint.h>
static uint32_t state=UINT32_C(0xaabb1719);
static uint32_t rnd(void){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
static int32_t sv(void){uint32_t u=rnd();if(u<=(uint32_t)INT32_MAX)return(int32_t)u;return(int32_t)(-(int32_t)(UINT32_MAX-u)-1);}
static uint64_t qgap(int32_t p,int32_t lo,int32_t hi){int64_t d=0;if(p<lo)d=(int64_t)lo-p;else if(p>hi)d=(int64_t)p-hi;uint64_t m=(uint64_t)d;return m*m;}
static int oracle(int32_t*c,uint32_t r,int32_t*lo,int32_t*hi){uint64_t budget=(uint64_t)r*r;for(unsigned i=0;i<3;++i){if(lo[i]>hi[i])return 0;uint64_t q=qgap(c[i],lo[i],hi[i]);if(q>budget)return 0;budget-=q;}return 1;}
int main(void){
 for(int32_t x0=-1;x0<=1;++x0)for(int32_t x1=-1;x1<=1;++x1)for(int32_t y0=-1;y0<=1;++y0)for(int32_t y1=-1;y1<=1;++y1)for(int32_t z0=-1;z0<=1;++z0)for(int32_t z1=-1;z1<=1;++z1)for(int32_t x=-2;x<=2;++x)for(int32_t y=-2;y<=2;++y)for(int32_t z=-2;z<=2;++z)for(uint32_t r=0;r<4;++r){int32_t lo[3]={x0,y0,z0},hi[3]={x1,y1,z1},c[3]={x,y,z};assert(pc_sphere_aabb_overlap_i32(x,y,z,r,x0,y0,z0,x1,y1,z1)==oracle(c,r,lo,hi));}
 for(unsigned n=0;n<100000;++n){int32_t v[9],c[3],lo[3],hi[3];for(unsigned i=0;i<9;++i)v[i]=sv();for(unsigned i=0;i<3;++i){c[i]=v[i];lo[i]=v[i+3];hi[i]=v[i+6];}uint32_t r=rnd();assert(pc_sphere_aabb_overlap_i32(c[0],c[1],c[2],r,lo[0],lo[1],lo[2],hi[0],hi[1],hi[2])==oracle(c,r,lo,hi));}
 return 0;
}
