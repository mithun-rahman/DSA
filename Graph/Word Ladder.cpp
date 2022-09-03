#include<bits/stdc++.h>

using namespace std;

class Solution {

    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> visit;
        for(int i = 0; i < wordList.size(); i++) {
            visit.insert(wordList[i]);
        }

        queue<string> q;
        q.push(beginWord);

        int level = 1;
        string temp;

        while(q.size()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                string top = q.front();
                q.pop();
                if(top == endWord) return level;
                for(int j = 0; j < top.size(); j++) {
                    for(int c = 'a'; c <= 'z'; c++) {
                        temp = top;
                        temp[j] = c;
                        if(visit.find(temp) != visit.end()) {
                            q.push(temp);
                            visit.erase(temp);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};

int main()
{
    string beginWord, endWord, temp;
    vector<string> wordList;
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log"};

    Solution ss;
    cout << ss.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
