#include "subarray.h"

void find_max_cross_subarray(int* array, int low, int mid, int high, int *return_ary){
    // mid to low
    int max_left_sum = INT_MIN;
    int max_left_idx = 0;
    int sum = 0;
    for(int idx = mid; idx >= low; idx--){
        sum += array[idx];
        if(sum > max_left_sum){
            max_left_sum = sum;
            max_left_idx = idx;
        }
    }
    // mid+1 to high
    int max_right_sum = INT_MIN;
    int max_right_idx = 0;
    sum = 0;
    for(int idx = mid+1; idx <= high; idx++){
        sum += array[idx];
        if(sum > max_right_sum){
            max_right_sum = sum;
            max_right_idx = idx;
        }
    }
    return_ary[0] = max_left_idx;
    return_ary[1] = max_right_idx;
    return_ary[2] = max_right_sum + max_left_sum;
}

int* find_maximun_subarray(int* array, int low, int high){
    int *return_result = (int*)calloc(3, sizeof(int));
    if(low == high){
        return_result[0] = low;
        return_result[1] = high;
        return_result[2] = array[low];
    }
    else{
        int mid = (low + high) / 2;
        int right[3] = {0};
        int left[3] = {0};
        int cross[3] = {0};
        int *left_tmp = find_maximun_subarray(array, low, mid);
        memcpy(left, left_tmp, sizeof(int)*3);
        free(left_tmp);
        int *right_tmp = find_maximun_subarray(array, mid+1, high);
        memcpy(right, right_tmp, sizeof(int)*3);
        free(right_tmp);
        find_max_cross_subarray(array, low, mid, high, cross);
        // compare
        if(left[2] > right[2] && left[2] > cross[2])
            memcpy(return_result, left, sizeof(int)*3);
        else if(right[2] > left[2] && right[2] > cross[2])
            memcpy(return_result, right, sizeof(int)*3);
        else
            memcpy(return_result, cross, sizeof(int)*3);
    }
    return return_result;
}