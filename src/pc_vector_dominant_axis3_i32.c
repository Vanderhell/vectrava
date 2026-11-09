#include "pc_vector_dominant_axis3_i32.h"
#include <stddef.h>
static uint32_t magnitude(int32_t x){return x<0?(uint32_t)(-(int64_t)x):(uint32_t)x;}
bool pc_vector_dominant_axis3_i32(const int32_t v[3],uint8_t *axis){uint32_t best;uint8_t index;unsigned i;if(v==NULL||axis==NULL)return false;best=magnitude(v[0]);index=0u;for(i=1u;i<3u;i++){uint32_t m=magnitude(v[i]);if(m>best){best=m;index=(uint8_t)i;}}*axis=index;return true;}
