#include <vectrava/geometry/checked_add_i64.h>
#include <stdint.h>
int main(void) { int64_t sum = 0; return vectrava_checked_add_i64(20, 22, &sum) && sum == 42 ? 0 : 1; }
