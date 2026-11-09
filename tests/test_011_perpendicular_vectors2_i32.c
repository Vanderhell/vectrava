#include "pc_perpendicular_vectors2_i32.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
static uint32_t st=1957u;static uint32_t rng(void){st^=st<<13;st^=st>>17;st^=st<<5;return st;}
static int32_t si(uint32_t x){int32_t r;__builtin_memcpy(&r,&x,sizeof r);return r;}
static int ref(int32_t ax,int32_t ay,int32_t bx,int32_t by){return (__int128)ax*bx+(__int128)ay*by==0;}
int main(void){int32_t v[25][2];int i,j;unsigned t;for(i=0;i<25;i++){v[i][0]=i/5-2;v[i][1]=i%5-2;}for(i=0;i<25;i++)for(j=0;j<25;j++)assert(pc_perpendicular_vectors2_i32(v[i][0],v[i][1],v[j][0],v[j][1])==ref(v[i][0],v[i][1],v[j][0],v[j][1]));for(t=0;t<100000;t++){int32_t a=si(rng()),b=si(rng()),c=si(rng()),d=si(rng());assert(pc_perpendicular_vectors2_i32(a,b,c,d)==ref(a,b,c,d));}assert(pc_perpendicular_vectors2_i32(INT32_MIN,INT32_MIN,INT32_MIN,INT32_MAX)==0);assert(pc_perpendicular_vectors2_i32(INT32_MIN,INT32_MIN,INT32_MAX,INT32_MIN)==0);assert(pc_perpendicular_vectors2_i32(0,0,INT32_MIN,INT32_MAX));puts("PASS: 625 exhaustive pairs + 100000 seeded full-int32 vectors");return 0;}
