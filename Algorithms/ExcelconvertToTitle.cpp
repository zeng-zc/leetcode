// 这个C++ 版本为什么不对？？？
#include <string>
using namespace std;
class Solution {
    public:
        string convertToTitle(int n) {
            string str;
            do{
                str.insert(0, (char)n%26+('A'-1));
                n = n/26;
            }while(n != 0);
            return str;
        }
};

int main(){
    Solution s;
    cout << s.convertToTitle(28) << endl;
    cout << s.convertToTitle(2) << endl;
}
