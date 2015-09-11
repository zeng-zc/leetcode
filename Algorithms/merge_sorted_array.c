// https://leetcode.com/problems/merge-sorted-array/
/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal
 * to m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
 */

// 插入排序，另外要记住上次插入的位置
void merge(int* nums1, int m, int* nums2, int n) {
    int pre_pos=-1;  // 前一次插入的位置
    for(int i=0; i<n; i++){ // nums2 中的下标
        int j;
        for(j=pre_pos+1; j<m+i; j++){ // nums1 中的下标
            if(nums1[j] > nums2[i]){
                int tmp = nums1[j];
                nums1[j] = nums2[i];
                for(int k=m+i-1; k>j; k--)
                    nums1[k+1]=nums1[k];
                nums1[j+1]=tmp;
                break;
            }
        }
        nums1[j] = nums2[i];
        pre_pos=j;
    }
}
// 很好，一次通过本地编译和 leetcode。
// 关键是要思维清晰。


// 尝试用 mergesort的思想
// 先将 arr2 复制到 arr1 的后半部分，然后在两个部分合并
// 如果从l2 (后半部分)中取了一个元素，l1 的head 要填充到 l2 中去
void merge2(int* nums1, int m, int* nums2, int n) {
    nums1[m]=nums1[0]; // 先腾出一个位置
    int head1 = m, head2=0, end=m+1; // 下一个需要腾挪的元素放置在nums1 的end 下标处
    for(int i=0; i<m+n && head2<n; i++){
        if(i-head2 < m){ // 表明 l1 中的元素还没取完。
            // i：l1和l2一共已经放置就绪的元素个数；
            // head2：l2 中已经处理的元素。
            if(nums2[head2] < nums1[head1]){
                nums1[i]=nums2[head2];
                head2++;
            }else{
                nums1[i]=nums1[head1];
                head1++;
            }
            nums1[end++]=nums1[i+1];  // 腾位置
        }else
            nums1[i]=nums2[head2++]; // l1已空，直接从 l2 复制
    }
}
/*notes：
 * 这个版本写起来太累，太多的地方需要注意。
 * 一个容易犯错的地方是：for循环中的截止条件容易忽略 head2<n（即l2
 * 还没处理完）
 *另一个容易犯错的地方是，l1 已经空的情况没有单独拿出来讨论。
 *
 * 另外，这个代码在本地运行没问题，但在 Leetcode run time error.
 /


#include <stdio.h>
int main(){
    int arr1[10] = {1, 2, 3};
    int arr2[] = {2, 5, 6};
    int len1 = 3;
    int len2 = sizeof arr2/sizeof arr2[0];
    merge2(arr1, len1, arr2, len2);
    for(int i=0; i< len1+len2; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    return 0;
}
