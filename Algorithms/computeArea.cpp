// https://leetcode.com/problems/rectangle-area/
/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as
shown in the figure.
*/

#include <algorithm>
#include <iostream>
using namespace std;

// Trap: overflow!!
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A) * (D-B);
        int area2 = (G-E) * (H-F);
        long sectLength = max(long(min(C,G)) - long(max(E,A)), 0L);  // Avoiding overflow!
        int sectWidth = max(long(min(D,H)) - long(max(B,F)), 0L);
        int area3 = sectLength * sectWidth;
        return area1 + area2 - area3;
    }
};

int main(){
    Solution s;
    cout << s.computeArea(-1500000001, 0, -1500000000, 1, 
            1500000000, 0, 1500000001, 1) << endl;
    return 0;
}
