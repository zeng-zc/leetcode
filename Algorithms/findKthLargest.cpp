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

#include <vector>
#include <iostream>
#include <queue>  // for std::make_heap
using namespace std;

// heap 的大小只需要为 k 就行了，不用对整个数组建立heap
// 维护一个大小为 k 的小根堆
// 使用标准库里面的 make_heap

class Solution {
public:
    int findKthLargest(vector<int>& vec, int k) {
        auto beg = vec.begin();
        auto heap_end = std::next(beg, std::min((size_t)k, vec.size()));
        std::make_heap(beg, heap_end, std::greater<int>()); // 构造小根堆
        for (int i=k; i<vec.size(); ++i) {
            if (vec[i] > vec.front()) {
                std::swap(vec.front(), vec[i]);
                std::make_heap(beg, heap_end, std::greater<int>());
            }
        }
        return vec.front();
    }
};


// 使用 quicksort 的 partition 思想
// O(N) 的效率，最优的方法
class Solution2 {
public:
    int findKthLargest(vector<int>& vec, int k) {
        int pos =  partition(vec, 0, vec.size()-1, k);
        return vec[pos];
    }

    // 找到一个划分点正好是第 k 大的，即大于这个元素的有 k-1 个元素
    // 返回划分点的位置
    int partition(vector<int>&vec, int first, int last, int k) {
        /*
        if (last == first && k == 1)
            return first;
        if (last < first || last > vec.size()-1 || first < 0)
            return -1;
            */ 
        // 边界不用特殊处理。只要外部第一次调用时参数是合法的，后续每次调用参数都是合法的
        int target = (first+last)/2; // 随便找个主元
        std::swap(vec[first], vec[target]);
        int boundary = first; // 小元素部分的最后一个下标
        for (int i=first+1; i<=last; ++i) {
            if (vec[i] < vec[first]) { // 比主元小则交换到前面去
                std::swap(vec[i], vec[++boundary]);
            }
        }
        std::swap(vec[first], vec[boundary]);
        int size1 = boundary-first+1;
        int size2 = last-boundary; // 大于主元的个数
        if (size2 == k-1)
            return boundary;
        else if (size2 > k-1) {
            return partition(vec, boundary+1, last, k);
        } else {
            return partition(vec, first, boundary-1, k-(size2+1));
        }
    }
};
// accepted! beats 65%

int main() {
    std::vector<int> vec{1, 2, 3, 4,7, 5, 8, 10, 6, 9};
    Solution2 s;
    std::cout << s.findKthLargest(vec, 4) << '\n';
    return 0;
}
