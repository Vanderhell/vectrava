#include "pc_rotation_matrix2_from_angle_q.h"
#include <stddef.h>
#include <stdint.h>
#define ONE INT32_C(1073741824)
#define CHECK(c) do{if(!(c))return __LINE__;}while(0)
int main(void){pc_matrix2_q m={{71,72,73,74}};uint32_t seed=1394;
 CHECK(!pc_rotation_matrix2_from_angle_q(0,NULL));
 CHECK(pc_rotation_matrix2_from_angle_q(0,&m));CHECK(m.element[0]==ONE&&m.element[1]==0&&m.element[2]==0&&m.element[3]==ONE);
 CHECK(pc_rotation_matrix2_from_angle_q(UINT32_C(0x40000000),&m));CHECK(m.element[0]>=-16&&m.element[0]<=16&&m.element[1]>=-ONE&&m.element[1]<=-ONE+2&&m.element[2]<=ONE&&m.element[2]>=ONE-2&&m.element[3]>=-16&&m.element[3]<=16);
 CHECK(pc_rotation_matrix2_from_angle_q(UINT32_C(0x80000000),&m));CHECK(m.element[0]<=-ONE+16&&m.element[0]>=-ONE&&m.element[1]>=-16&&m.element[1]<=16&&m.element[2]>=-16&&m.element[2]<=16&&m.element[3]==m.element[0]);
 CHECK(pc_rotation_matrix2_from_angle_q(UINT32_C(0xc0000000),&m));CHECK(m.element[0]>=-16&&m.element[0]<=16&&m.element[1]>=ONE-2&&m.element[1]<=ONE&&m.element[2]>=-ONE&&m.element[2]<=-ONE+2&&m.element[3]>=-16&&m.element[3]<=16);
 for(unsigned i=0;i<10000;i++){pc_matrix2_q inv;seed=seed*UINT32_C(1664525)+UINT32_C(1013904223);CHECK(pc_rotation_matrix2_from_angle_q(seed,&m));CHECK(m.element[0]==m.element[3]&&m.element[1]==-m.element[2]);for(unsigned j=0;j<4;j++)CHECK(m.element[j]>=-ONE&&m.element[j]<=ONE);int64_t n=(int64_t)m.element[0]*m.element[0]+(int64_t)m.element[2]*m.element[2];CHECK(n>=(INT64_C(1)<<60)-(INT64_C(1)<<36)&&n<=(INT64_C(1)<<60)+(INT64_C(1)<<36));CHECK(pc_rotation_matrix2_from_angle_q(0u-seed,&inv));CHECK((int64_t)inv.element[0]-m.element[0]>=-64&&(int64_t)inv.element[0]-m.element[0]<=64);CHECK((int64_t)inv.element[1]-m.element[2]>=-64&&(int64_t)inv.element[1]-m.element[2]<=64);CHECK((int64_t)inv.element[2]-m.element[1]>=-64&&(int64_t)inv.element[2]-m.element[1]<=64);CHECK((int64_t)inv.element[3]-m.element[3]>=-64&&(int64_t)inv.element[3]-m.element[3]<=64);}
 return 0;}
