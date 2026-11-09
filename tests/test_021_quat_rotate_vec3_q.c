#include "pc_quat_rotate_vec3_q.h"
#include <stddef.h>
#include <stdint.h>
#define ONE INT32_C(1073741824)
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void) {
    int32_t q[4]={ONE,0,0,0},v[3]={ONE,0,0},o[3]={7,8,9}; uint32_t s=1372u;
    CHECK(!pc_quat_rotate_vec3_q(NULL,v,o)); CHECK(!pc_quat_rotate_vec3_q(q,NULL,o));
    CHECK(!pc_quat_rotate_vec3_q(q,v,NULL)); CHECK(pc_quat_rotate_vec3_q(q,v,o));
    CHECK(o[0]==ONE&&o[1]==0&&o[2]==0);
    q[0]=q[1]=q[2]=q[3]=0; CHECK(!pc_quat_rotate_vec3_q(q,v,o));
    CHECK(o[0]==ONE&&o[1]==0&&o[2]==0);
    q[0]=ONE; v[0]=ONE+1; CHECK(!pc_quat_rotate_vec3_q(q,v,o));
    v[0]=ONE; q[0]=0;q[3]=ONE;v[1]=0;
    CHECK(pc_quat_rotate_vec3_q(q,v,o)); CHECK(o[0]==-ONE&&o[1]==0&&o[2]==0);
    for(unsigned i=0;i<10000;i++) { int32_t a[4],b[3],r[3],an[4],rn[3]; uint64_t before=0,after=0;
        for(unsigned j=0;j<4;j++){s=s*1664525u+1013904223u;a[j]=(int32_t)s;}
        if(!(a[0]|a[1]|a[2]|a[3]))a[0]=1;
        for(unsigned j=0;j<3;j++){s=s*1664525u+1013904223u;b[j]=(int32_t)((int64_t)(s%2147483649u)-ONE);}
        CHECK(pc_quat_rotate_vec3_q(a,b,r));
        for(unsigned j=0;j<3;j++){int64_t x=b[j],y=r[j];before+=(uint64_t)(x*x);after+=(uint64_t)(y*y);}
        CHECK(before>after ? before-after < (UINT64_C(1)<<35) : after-before < (UINT64_C(1)<<35));
        for(unsigned j=0;j<4;j++) an[j]=(int32_t)(-(int64_t)a[j]);
        CHECK(pc_quat_rotate_vec3_q(an,b,rn));
        for(unsigned j=0;j<3;j++){int64_t d=(int64_t)r[j]-rn[j];CHECK(d>=-4&&d<=4);}
    }
    return 0;
}

