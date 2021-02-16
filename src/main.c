#include "subarray.h"
#include <stdio.h>

int main(){
    int a[5] = {1, 2, 5, 10, -4};
    int *result = find_maximun_subarray(a, 0, *(&a+1)-a-1);
    printf("low_idx: %d, high_idx: %d, max_sum: %d\n", result[0], result[1], result[2]);
    return 0;
}