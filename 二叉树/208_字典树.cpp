/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
*/

#include <iostream>
#include <string>

using namespace std;

// 其实字典树就是一个26叉树
class TrieNode{
public:
    //记录字符是否存在
    bool have;
    //保存结点出现的字符，26个指针，也就是26个子节点
    TrieNode* child[26];
    TrieNode(){
        for(int i = 0; i < 26; ++i){
            child[i] = 0;
        }
        have = false;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    // 从根节点开始查找，如果不存在就新建一个结点
    void insert(string word) {
        TrieNode* now = root;
        for(auto ch: word){
            int c = ch - 'a';
            if(now->child[c] == 0){
                now->child[c] = new TrieNode();
            }
            now = now->child[c];
        }
        now->have = true;
    }
    // 同样，是每层查找
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* now = root;
        for(auto ch: word){
            int c = ch - 'a';
            if(now->child[c] == 0){
                return false;
            }
            now = now->child[c];
        }
        return now && now->have;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* now = root;
        for(auto ch: prefix){
            int c = ch - 'a';
            if(now->child[c] == 0){
                return false;
            }
            now = now->child[c];
        }
        return now;
    }
    
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main()
{
    Trie trie;
    trie.insert("apple");
    bool res = trie.search("apple");   // 返回 true
    cout << res << endl;
    bool res1 = trie.search("app");     // 返回 false
    cout << res1  << endl;
    bool res2 = trie.startsWith("app"); // 返回 true
    cout << res2  << endl;
    trie.insert("app");   
    bool res3 = trie.search("app");     // 返回 true
    cout << res3  << endl;
}