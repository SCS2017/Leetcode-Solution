/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。
当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:
你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:
LRUCache cache = new LRUCache( 2 (缓存容量) );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*/

#include <bits/stdc++.h>

using namespace std;

/*
这道题让我们实现一个LRU缓存器，LRU是Least Recently Used的简写，就是最近最少使用的意思。那么这个缓存器主要有两个成员函数，
get和put，其中get函数是通过输入key来获得value，如果成功获得后，这对(key, value)升至缓存器中最常用的位置（顶部），
如果key不存在，则返回-1。而put函数是插入一对新的(key, value)，如果原缓存器中有该key，则需要先删除掉原有的，
将新的插入到缓存器的顶部。如果不存在，则直接插入到顶部。若加入新的值后缓存器超过了容量，则需要删掉一个最不常用的值，
也就是底部的值。具体实现时我们需要三个私有变量，cap, l和m，其中cap是缓存器的容量大小，l是保存缓存器内容的列表，
m是HashMap，保存关键值key和缓存器各项的迭代器之间映射，方便我们以O(1)的时间内找到目标项。

然后我们再来看get和put如何实现，get相对简单些，我们在HashMap中查找给定的key，若不存在直接返回-1。如果存在则将此项移到顶部，
这里我们使用C++ STL中的函数splice，专门移动链表中的一个或若干个结点到某个特定的位置，
这里我们就只移动key对应的迭代器到列表的开头，然后返回value。这里再解释一下为啥HashMap不用更新，
因为HashMap的建立的是关键值key和缓存列表中的迭代器之间的映射，get函数是查询函数，如果关键值key不在HashMap，
那么不需要更新。如果在，我们需要更新的是该key-value键值对儿对在缓存列表中的位置，
而HashMap中还是这个key跟键值对儿的迭代器之间的映射，并不需要更新什么。
*/

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end())
            return -1;
        //移动当前key对应的链表的结点到链表的头部
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    // 如果key已存在，算被使用一次
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end())
            l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if(l.size() > cap){
            int key = l.back().first;
            m.erase(key);
            l.pop_back();
        }
    }
    // 如果key已存在，则使用value替换原先已经存在的值，不算被使用
    void put(int key, int value){
        // key已经存在的话，只更新值
        if(m.count(key))
            m[key]->second = value;
        else{
            l.push_front(make_pair(key, value));
            m[key] = l.begin();
            if(l.size() > cap){
                int key = l.back().first;
                m.erase(key);
                l.pop_back();
            }
        }
    }
private:
    int cap;
    list<pair<int, int> > l;
    unordered_map<int, list<pair<int, int>>::iterator > m;
};


int main(){
    
    return 0;
}
