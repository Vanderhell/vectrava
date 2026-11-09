#include "pc_vector_cross3_i32.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
__extension__ typedef __int128 int128_t;
static uint32_t next(uint32_t *s){*s=*s*UINT32_C(1664525)+UINT32_C(1013904223);return *s;}
static int32_t as_i32(uint32_t x){int64_t v=x;if(v>INT32_MAX)v-=INT64_C(4294967296);return (int32_t)v;}
static int check(const int32_t a[3],const int32_t b[3])
{
    int64_t c[3],d[3]; unsigned i;
    int128_t exact[3];
    exact[0]=(int128_t)a[1]*b[2]-(int128_t)a[2]*b[1];
    exact[1]=(int128_t)a[2]*b[0]-(int128_t)a[0]*b[2];
    exact[2]=(int128_t)a[0]*b[1]-(int128_t)a[1]*b[0];
    if(!pc_vector_cross3_i32(a,b,c)||!pc_vector_cross3_i32(b,a,d))return 0;
    for(i=0;i<3u;++i)if((int128_t)c[i]!=exact[i]||d[i]!=-c[i])return 0;
    if((int128_t)c[0]*a[0]+(int128_t)c[1]*a[1]+(int128_t)c[2]*a[2]!=0)return 0;
    if((int128_t)c[0]*b[0]+(int128_t)c[1]*b[1]+(int128_t)c[2]*b[2]!=0)return 0;
    return 1;
}
int main(void)
{
    static const int32_t edge[]={INT32_MIN,INT32_MIN+1,-1,0,1,INT32_MAX-1,INT32_MAX};
    int32_t a[3]={0,0,0},b[3]={0,0,0}; int64_t out[3]={9,8,7}; uint32_t seed=UINT32_C(0x545C055),n; size_t i,j,k,l,m,r;
    CHECK(!pc_vector_cross3_i32(NULL,b,out)&&out[0]==9&&out[1]==8&&out[2]==7);
    CHECK(!pc_vector_cross3_i32(a,NULL,out)&&out[0]==9&&out[1]==8&&out[2]==7);
    CHECK(!pc_vector_cross3_i32(a,b,NULL));
    for(i=0;i<7u;++i)for(j=0;j<7u;++j)for(k=0;k<7u;++k)for(l=0;l<7u;++l)for(m=0;m<7u;++m)for(r=0;r<7u;++r){a[0]=edge[i];a[1]=edge[j];a[2]=edge[k];b[0]=edge[l];b[1]=edge[m];b[2]=edge[r];CHECK(check(a,b));}
    for(i=0;i<1331u;++i)for(j=0;j<1331u;++j){a[0]=(int32_t)(i/121u)-5;a[1]=(int32_t)((i/11u)%11u)-5;a[2]=(int32_t)(i%11u)-5;b[0]=(int32_t)(j/121u)-5;b[1]=(int32_t)((j/11u)%11u)-5;b[2]=(int32_t)(j%11u)-5;CHECK(check(a,b));}
    for(n=0;n<500000u;++n){for(i=0;i<3u;++i){a[i]=as_i32(next(&seed));b[i]=as_i32(next(&seed));}CHECK(check(a,b));}
    puts("endpoint, exhaustive reduced, seeded, antisymmetry and orthogonality PASS");return 0;
}
