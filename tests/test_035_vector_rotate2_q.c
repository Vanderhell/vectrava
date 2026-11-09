#include "pc_vector_rotate2_q.h"
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
static uint32_t next(uint32_t *s){*s=*s*UINT32_C(1664525)+UINT32_C(1013904223);return *s;}
static int16_t as_i16(uint32_t x){int32_t v=(int32_t)(x&UINT32_C(0xffff));if(v>=32768)v-=65536;return (int16_t)v;}
static int16_t sat_round(long double x){long double m=fabsl(x),f=floorl(m);uint64_t q=(uint64_t)f;if(m-f>0.5L||(m-f==0.5L&&(q&1u)))++q;if(x<0)return q>=32768u?INT16_MIN:(int16_t)-(int32_t)q;return q>=32767u?INT16_MAX:(int16_t)q;}
static int check(int16_t x,int16_t y,uint32_t phase,uint32_t *maxe)
{
    int16_t in[2]={x,y},out[2];long double angle=(long double)phase*(2.0L*acosl(-1.0L)/4294967296.0L);int16_t ref[2];int32_t d;unsigned i;
    ref[0]=sat_round((long double)x*cosl(angle)-(long double)y*sinl(angle));ref[1]=sat_round((long double)x*sinl(angle)+(long double)y*cosl(angle));
    if(!pc_vector_rotate2_q(in,phase,out))return 0;
    for(i=0;i<2u;++i){d=(int32_t)out[i]-ref[i];if(d<0)d=-d;if((uint32_t)d>*maxe)*maxe=(uint32_t)d;if(d>2)return 0;}
    {long double ideal_x=(long double)x*cosl(angle)-(long double)y*sinl(angle),ideal_y=(long double)x*sinl(angle)+(long double)y*cosl(angle);
        if(fabsl(ideal_x)<=32767.0L&&fabsl(ideal_y)<=32767.0L&&fabsl(hypotl((long double)out[0],(long double)out[1])-hypotl((long double)x,(long double)y))>3.0L)return 0;}
    return 1;
}
int main(void)
{
    static const int16_t edge[]={INT16_MIN,-1,0,1,INT16_MAX};
    static const uint32_t phases[]={0u,1u,UINT32_C(0x1fffffff),UINT32_C(0x20000000),UINT32_C(0x3fffffff),UINT32_C(0x40000000),UINT32_C(0x40000001),UINT32_C(0x7fffffff),UINT32_C(0x80000000),UINT32_C(0xbfffffff),UINT32_C(0xc0000000),UINT32_C(0xffffffff)};
    int16_t in[2]={12,-34},out[2]={7,8};uint32_t maxe=0,seed=UINT32_C(0x551A05),n;size_t i,j,p;
    CHECK(!pc_vector_rotate2_q(NULL,0u,out)&&out[0]==7&&out[1]==8);CHECK(!pc_vector_rotate2_q(in,0u,NULL));
    CHECK(pc_vector_rotate2_q(in,0u,out)&&out[0]==12&&out[1]==-34);
    for(i=0;i<5u;++i)for(j=0;j<5u;++j)for(p=0;p<sizeof phases/sizeof phases[0];++p)CHECK(check(edge[i],edge[j],phases[p],&maxe));
    for(i=0;i<1089u;++i){int16_t x=(int16_t)((int32_t)(i/33u)-16),y=(int16_t)((int32_t)(i%33u)-16);for(p=0;p<256u;++p)CHECK(check(x,y,(uint32_t)((uint64_t)p*UINT64_C(0x01000000)),&maxe));}
    for(n=0;n<500000u;++n)CHECK(check(as_i16(next(&seed)),as_i16(next(&seed)),next(&seed),&maxe));
    printf("maximum_component_error_q15=%u\n",maxe);return maxe<=2u?0:1;
}
