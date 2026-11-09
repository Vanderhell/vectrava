#include "pc_perpendicular_vectors2_i32.h"
typedef struct {uint64_t magnitude;int sign;} term;
static term multiply(int32_t a,int32_t b){uint64_t ma=(uint64_t)(a<0?-(int64_t)a:a),mb=(uint64_t)(b<0?-(int64_t)b:b);term t;t.magnitude=ma*mb;t.sign=(a==0||b==0)?0:((a<0)==(b<0)?1:-1);return t;}
bool pc_perpendicular_vectors2_i32(int32_t ax,int32_t ay,int32_t bx,int32_t by){term x=multiply(ax,bx),y=multiply(ay,by);if(x.sign==0)return y.sign==0;if(y.sign==0)return false;if(x.sign==y.sign)return false;return x.magnitude==y.magnitude;}

