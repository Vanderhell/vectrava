#include "pc_bbox_of_points2_i32.h"
bool pc_bbox_of_points2_i32(const pc_point2_i32 *points,size_t count,pc_bbox2_i32 *bounds){
 pc_bbox2_i32 r;size_t i;
 if(points==NULL||bounds==NULL||count==0u)return false;
 r.min_x=r.max_x=points[0].x;r.min_y=r.max_y=points[0].y;
 for(i=1u;i<count;++i){if(points[i].x<r.min_x)r.min_x=points[i].x;if(points[i].x>r.max_x)r.max_x=points[i].x;if(points[i].y<r.min_y)r.min_y=points[i].y;if(points[i].y>r.max_y)r.max_y=points[i].y;}
 *bounds=r;return true;
}

