// https://leetcode.com/problems/binary-tree-level-order-traversal/

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

// 使用队列来保存节点
// 由于每一层的结果要放在一个 vector 中，
// 用两个队列（parent 和 child）
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> parent;
        queue<TreeNode *> child;
        vector<vector<int>> vvi;
        vector<int> buff; // 临时存放当前层的值
        if(root == nullptr)
            return vvi;
        parent.push(root);
        while(true){
            buff.clear();
            while(!parent.empty()){
                auto front = parent.front(); // 下一个要出列的元素为 front 成员！
                parent.pop();
                if(front->left)
                    child.push(front->left);
                if(front->right)
                    child.push(front->right);
                buff.push_back(front->val);
            }
            vvi.push_back(buff);
            if(child.empty())
                break;
            swap(parent, child);
        }
        return vvi;
    }

/*notes:
 * 容易犯的错误：
 * （1）对于queue，下一个要出列的元素是front，而不是back！
 *     因为每次新加元素都是push_back，所以最老的元素在front。
 * (2)空指针入列。空指针也是用一个指针变量来存储，当然占一个位置。
 *    为了避免bug，养成习惯在入列前要检查指针是否为空。
 */

    // 优化的版本，用两个指针来操作两个队列，避免了两个
    // 队列之间的拷贝
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> parent;
        queue<TreeNode *> child;
        vector<vector<int>> vvi;
        vector<int> buff; // 临时存放当前层的值
        auto *ptr_parent = &parent;
        auto *ptr_child = &child;
        if(root == nullptr)
            return vvi;
        ptr_parent->push(root);
        while(true){
            buff.clear();
            while(!ptr_parent->empty()){
                auto front = ptr_parent->front();
                ptr_parent->pop();
                if(front->left)
                    ptr_child->push(front->left);
                if(front->right)
                    ptr_child->push(front->right);
                buff.push_back(front->val);
            }
            if(!buff.empty())
                vvi.push_back(buff);
            if(ptr_child->empty())
                break;
            // 交换两个指针
            auto tmp=ptr_parent;
            ptr_parent = ptr_child;
            ptr_child = tmp;
        }
        return vvi;
    }
};
// 两个版本均已通过 leetcode。
// 容易犯的一个愚蠢的错误是在交换两个指针时写成了这样：
//      ptr_parent = &child;
//      ptr_child = &parent;
//（仅仅在循环第一次执行后是这样的）
