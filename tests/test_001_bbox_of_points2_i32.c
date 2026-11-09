#include "pc_bbox_of_points2_i32.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
static uint32_t st=1950u;static uint32_t rnd(void){st^=st<<13;st^=st>>17;st^=st<<5;return st;}
static int32_t si(uint32_t u){int32_t v;memcpy(&v,&u,sizeof v);return v;}
int main(void){pc_point2_i32 p[64];pc_bbox2_i32 b={11,22,33,44};size_t n,i;unsigned t;assert(!pc_bbox_of_points2_i32(NULL,1,&b)&&b.min_x==11);assert(!pc_bbox_of_points2_i32(p,0,&b)&&b.min_x==11);assert(!pc_bbox_of_points2_i32(p,1,NULL));assert(!pc_bbox_of_points2_i32(NULL,0,NULL));for(t=0;t<100000;t++){n=1u+rnd()%64u;for(i=0;i<n;i++){p[i].x=si(rnd());p[i].y=si(rnd());}assert(pc_bbox_of_points2_i32(p,n,&b));int32_t lx=p[0].x,hx=p[0].x,ly=p[0].y,hy=p[0].y;for(i=1;i<n;i++){if(p[i].x<lx)lx=p[i].x;if(p[i].x>hx)hx=p[i].x;if(p[i].y<ly)ly=p[i].y;if(p[i].y>hy)hy=p[i].y;}assert(b.min_x==lx&&b.max_x==hx&&b.min_y==ly&&b.max_y==hy);}puts("PASS: 100000 seeded arrays (1..64 points), null/empty transactional cases");return 0;}

