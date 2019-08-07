/* 
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。
转换需遵循如下规则：
1.每次转换只能改变一个字母。
2.转换过程中的中间单词必须是字典中的单词。

说明:
如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

示例 1:
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出: 5
解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。

示例 2:
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
输出: 0
解释: endWord "cog" 不在字典中，所以无法进行转换。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

/*
为了提到字典的查找效率，我们使用HashSet保存所有的单词。然后我们需要一个HashMap，来建立某条路径结尾单词和该路径长度之间的映射，
并把起始单词映射为1。既然是BFS，我们需要一个队列queue，把起始单词排入队列中，开始队列的循环，取出队首词，
然后对其每个位置上的字符，用26个字母进行替换，如果此时和结尾单词相同了，就可以返回取出词在哈希表中的值加一。
如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，并在哈希表中的值映射为之前取出词加一。如果循环完成则返回0，
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord))
            return 0;
        unordered_map<string, int> pathCnt{{{beginWord, 1}}};
        queue<string> q{{beginWord}};
        while(!q.empty()){
            string word = q.front();
            q.pop();
            for(int i = 0; i < word.size(); ++i){
                string newWord = word;
                for(char ch = 'a'; ch <= 'z'; ++ch){
                    newWord[i] = ch;
                    if(wordSet.count(newWord) && newWord == endWord)
                        return pathCnt[word] + 1;
                    if(wordSet.count(newWord) && !pathCnt.count(newWord)){
                        q.push(newWord);
                        pathCnt[newWord] = pathCnt[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
   return 0;
}
