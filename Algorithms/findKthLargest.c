// https://leetcode.com/problems/kth-largest-element-in-an-array/
/*
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#define left(i) 2*(i)+1
#define right(i) 2*(i)+2
void swap(int *nums, int i, int j){
    int tmp=nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
}

void max_heapify(int *nums, int numsSize, int i){
    int largest=i, l=left(i), r=right(i);
    if(l<numsSize && nums[l] > nums[i])
        largest = l;
    if(r<numsSize && nums[r] > nums[largest])
        largest = r;
    if(largest != i){
        swap(nums, i, largest);
        max_heapify(nums, numsSize, largest);
    }
}

void build_max_heap(int *nums, int numsSize){
    for(int i =numsSize/2; i>=0; i--){
        max_heapify(nums, numsSize, i);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    build_max_heap(nums, numsSize);
    for(int i=numsSize-1, count=0; i>0 && count < k-1; 
            count++, i--){
        swap(nums, i, 0);
        max_heapify(nums, --numsSize, 0);    
    }
    return nums[0];
}

// Accepted
// Classic heap sort.
