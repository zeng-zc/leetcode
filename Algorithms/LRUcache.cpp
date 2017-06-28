// https://leetcode.com/problems/lru-cache/#/description
//  使用纯 STL 实现

// passed! 
#include <list>
#include <memory>
#include <map>
#include <iterator>

struct Node {
    Node(int k, int v): key(k), value(v){} 
    int key;
    int value;
}; 
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    int get(int key) {
        auto found = hashmap.find(key);
        if (found == hashmap.end()) {
            return -1;
        } else {
            auto it = found->second;
            auto ptr = *it;
            auto ret = ptr->value;
            cache.erase(it);
            cache.push_front(std::move(ptr)); // 插到头部
            found->second = cache.begin(); // 更新hashmap中的值
            return ret;
        }
    }

    void put(int key, int value) {
        auto found = hashmap.find(key);
        if (found == hashmap.end()) {
            auto ptr = std::make_shared<Node>(key, value);
            if (hashmap.size() < capacity_) {
                cache.push_front(ptr);
                hashmap.insert(std::make_pair(key, cache.begin()));
            } else { // cache is full
                hashmap.erase(cache.back()->key); // std::map 可以按照key来erase
                cache.pop_back();
                cache.push_front(ptr);
                hashmap.insert(std::make_pair(key, cache.begin()));
            }
        } else { // 已经存在这个元素了
            auto ptr = *(found->second);
            ptr->value = value;
            cache.erase(found->second);
            cache.push_front(ptr);
            found->second = cache.begin();
        }
    }

private:
    std::list<std::shared_ptr<Node>> cache;
    std::map<int, decltype(cache.begin())> hashmap; // 根据key找cache中的位置
    // std::map 的 value_type 会自动去掉引用属性。另外，cache.begin() 的类型为 iterator, 也不带引用属性
    // 注意std::list 中的迭代器不会因为插入、删除而失效（除了被删除的那个迭代器本身）
    int capacity_;
};
