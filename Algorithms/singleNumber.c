int singleNumber(int* nums, int numsSize) {
    int res=nums[0];
    for(int i=1; i<numsSize; i++)
        res ^= nums[i]; 
    return res;
}

#include <stdio.h>
int main(){
    int a[]={1,2,3,4,5,1,2,3,5,0,0,10, 10};
    printf("%d\n", singleNumber(a, sizeof a/ sizeof a[0]));
    return 0;
}
