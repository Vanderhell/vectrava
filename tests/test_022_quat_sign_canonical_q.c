#include "pc_quat_sign_canonical_q.h"
#include <stddef.h>
#include <stdint.h>
#define ONE INT32_C(1073741824)
#define CHECK(x) do{if(!(x))return __LINE__;}while(0)
int main(void){int32_t q[4]={ONE,0,0,0},n[4],o[4]={7,8,9,10};uint32_t s=1375u;
 CHECK(!pc_quat_sign_canonical_q(NULL,o));CHECK(!pc_quat_sign_canonical_q(q,NULL));
 q[0]=q[1]=q[2]=q[3]=0;CHECK(!pc_quat_sign_canonical_q(q,o));CHECK(o[0]==7&&o[1]==8&&o[2]==9&&o[3]==10);
 q[0]=ONE+1;CHECK(!pc_quat_sign_canonical_q(q,o));CHECK(o[0]==7&&o[1]==8&&o[2]==9&&o[3]==10);
 q[0]=0;q[1]=-ONE;CHECK(pc_quat_sign_canonical_q(q,o));CHECK(o[1]==ONE);
 CHECK(pc_quat_sign_canonical_q(q,q));CHECK(q[1]==ONE);
 for(unsigned i=0;i<10000;i++){for(unsigned j=0;j<4;j++){s=s*1664525u+1013904223u;q[j]=(int32_t)((int64_t)(s%2147483649u)-ONE);}if(!(q[0]|q[1]|q[2]|q[3]))q[2]=1;CHECK(pc_quat_sign_canonical_q(q,o));for(unsigned j=0;j<4;j++)n[j]=-q[j];CHECK(pc_quat_sign_canonical_q(n,n));for(unsigned j=0;j<4;j++)CHECK(o[j]==n[j]);CHECK(pc_quat_sign_canonical_q(o,o));for(unsigned j=0;j<4;j++)CHECK(o[j]==n[j]);}
 return 0;}
