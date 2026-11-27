#include <vectrava/geometry/perpendicular_vectors2_i32.h>
#include <assert.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
static uint32_t st=1957u;static uint32_t rng(void){st^=st<<13;st^=st>>17;st^=st<<5;return st;}
static int32_t si(uint32_t x){int64_t v=x;if(v>INT32_MAX)v-=INT64_C(4294967296);return (int32_t)v;}
static uint64_t mag64(int64_t x){return (uint64_t)(x<0?-x:x);}
static int ref(int32_t ax,int32_t ay,int32_t bx,int32_t by){int64_t p=(int64_t)ax*bx,q=(int64_t)ay*by;if(p==0)return q==0;if(q==0)return 0;return ((p<0)!=(q<0))&&mag64(p)==mag64(q);}
int main(void){int32_t v[25][2];int i,j;unsigned t;for(i=0;i<25;i++){v[i][0]=i/5-2;v[i][1]=i%5-2;}for(i=0;i<25;i++)for(j=0;j<25;j++)assert(vectrava_perpendicular_vectors2_i32(v[i][0],v[i][1],v[j][0],v[j][1])==ref(v[i][0],v[i][1],v[j][0],v[j][1]));for(t=0;t<100000;t++){int32_t a=si(rng()),b=si(rng()),c=si(rng()),d=si(rng());assert(vectrava_perpendicular_vectors2_i32(a,b,c,d)==ref(a,b,c,d));}assert(vectrava_perpendicular_vectors2_i32(INT32_MIN,INT32_MIN,INT32_MIN,INT32_MAX)==0);assert(vectrava_perpendicular_vectors2_i32(INT32_MIN,INT32_MIN,INT32_MAX,INT32_MIN)==0);assert(vectrava_perpendicular_vectors2_i32(0,0,INT32_MIN,INT32_MAX));puts("PASS: 625 exhaustive pairs + 100000 seeded full-int32 vectors");return 0;}
