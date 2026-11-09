#include "pc_quat_small_angle_update_q.h"
#include <stddef.h>
#include <stdint.h>
#define ONE INT32_C(1073741824)
#define CHECK(x) do{if(!(x))return __LINE__;}while(0)
int main(void){int32_t q[4]={ONE,0,0,0},g[3]={0,0,65536},o[4]={1,2,3,4};uint32_t s=1379u;
 CHECK(!pc_quat_small_angle_update_q(NULL,g,1,o));CHECK(!pc_quat_small_angle_update_q(q,NULL,1,o));CHECK(!pc_quat_small_angle_update_q(q,g,100001,o));
 g[2]=655361;CHECK(!pc_quat_small_angle_update_q(q,g,1000,o));CHECK(o[0]==1&&o[1]==2&&o[2]==3&&o[3]==4);g[2]=0;g[0]=655360;CHECK(pc_quat_small_angle_update_q(q,g,1000,o));g[0]=0;g[2]=65536;
 CHECK(pc_quat_small_angle_update_q(q,g,1000,o));CHECK(o[3]>536000&&o[3]<538000);
 {int32_t zero[4]={0,0,0,0};CHECK(!pc_quat_small_angle_update_q(zero,g,1000,o));CHECK(o[3]>536000&&o[3]<538000);}
 for(unsigned i=0;i<10000;i++){for(unsigned j=0;j<4;j++){s=s*1664525u+1013904223u;q[j]=(int32_t)s;}if(!(q[0]|q[1]|q[2]|q[3]))q[0]=1;for(unsigned j=0;j<3;j++){s=s*1664525u+1013904223u;g[j]=(int32_t)((int64_t)(s%131072001u)-65536000);}CHECK(pc_quat_small_angle_update_q(q,g,s%6u,o));}
 return 0;}
