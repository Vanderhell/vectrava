#include "pc_vector_clamp_mag2_q.h"
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
static uint32_t next(uint32_t *s){*s=*s*UINT32_C(1664525)+UINT32_C(1013904223);return *s;}
static int16_t as_i16(uint32_t x){int32_t v=(int32_t)(x&UINT32_C(0xffff));if(v>=32768)v-=65536;return (int16_t)v;}
static int check(int16_t x,int16_t y,int16_t cap)
{
    int16_t in[2]={x,y},out[2]={123,456};uint64_t norm2=(uint64_t)((int32_t)x*x)+(uint64_t)((int32_t)y*y);long double radius=sqrtl((long double)norm2),den=ceill(radius),ideal_scale;int16_t ref[2];
    if(norm2<=(uint64_t)(uint16_t)cap*(uint16_t)cap){ref[0]=x;ref[1]=y;ideal_scale=1.0L;}
    else{ref[0]=(int16_t)(x<0?-(int32_t)((uint32_t)(-(int32_t)x)*(uint16_t)cap/(uint64_t)den):(int32_t)((uint32_t)x*(uint16_t)cap/(uint64_t)den));ref[1]=(int16_t)(y<0?-(int32_t)((uint32_t)(-(int32_t)y)*(uint16_t)cap/(uint64_t)den):(int32_t)((uint32_t)y*(uint16_t)cap/(uint64_t)den));ideal_scale=(long double)cap/radius;}
    if(!pc_vector_clamp_mag2_q(in,cap,out)||out[0]!=ref[0]||out[1]!=ref[1])return 0;
    if((int64_t)out[0]*out[0]+(int64_t)out[1]*out[1]>(int64_t)cap*cap)return 0;
    if(ideal_scale!=1.0L){long double dx=(long double)out[0]-x*ideal_scale,dy=(long double)out[1]-y*ideal_scale;if(hypotl(dx,dy)>3.0L)return 0;}
    return 1;
}
int main(void)
{
    static const int16_t edge[]={INT16_MIN,-32767,-1,0,1,32766,INT16_MAX};
    int16_t v[2]={9,8},out[2]={7,8};size_t i,j,k;uint32_t seed=UINT32_C(0x549A05),n;
    CHECK(!pc_vector_clamp_mag2_q(NULL,1,out));CHECK(!pc_vector_clamp_mag2_q(v,-1,out)&&out[0]==7&&out[1]==8);CHECK(!pc_vector_clamp_mag2_q(v,1,NULL));
    CHECK(pc_vector_clamp_mag2_q(v,13,out)&&out[0]==9&&out[1]==8);
    CHECK(pc_vector_clamp_mag2_q(v,0,out)&&out[0]==0&&out[1]==0);
    CHECK(check(INT16_MIN,INT16_MIN,INT16_MAX));CHECK(check(INT16_MAX,INT16_MAX,1));
    for(i=0;i<7u;++i)for(j=0;j<7u;++j)for(k=0;k<7u;++k)CHECK(check(edge[i],edge[j],edge[k]<0?0:edge[k]));
    for(i=0;i<4225u;++i)for(j=0;j<=32u;++j){int16_t x=(int16_t)((int32_t)(i/65u)-32),y=(int16_t)((int32_t)(i%65u)-32);CHECK(check(x,y,(int16_t)j));}
    for(i=0;i<2u;++i)for(j=0;j<65536u;++j){int16_t value=(int16_t)(int32_t)((int32_t)j-32768);CHECK(check(i==0u?value:12345,i==1u?value:-23456,(int16_t)(j%32768u)));}
    for(n=0;n<500000u;++n){int16_t x=as_i16(next(&seed)),y=as_i16(next(&seed)),cap=(int16_t)(next(&seed)&UINT32_C(0x7fff));CHECK(check(x,y,cap));}
    puts("boundaries, exhaustive reduced caps, full-component sweeps and seeded radius properties PASS");return 0;
}
