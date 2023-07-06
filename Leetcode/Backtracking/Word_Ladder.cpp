
class Solution {
public:
    unordered_set<string> visited;
    
    int diff(string&a, string& b) {
        int ret = 0;
        for(int i = 0; i < a.size(); i++) 
        {
            if(a[i] != b[i])
                ret++;
        }
        return ret;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord)
            return 0;
        
        queue<pair<string, int>> q;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if(wordSet.find(endWord)==wordSet.end())return 0;
        
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        while(!q.empty()) 
        {
            auto it = q.front();
            q.pop();
            
            if(it.first == endWord)
                return it.second;
            
            string currentWord = it.first;
            int currentLevel = it.second;
            
            for(int i = 0; i < currentWord.size(); i++) {
                char originalChar = currentWord[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    currentWord[i] = c;
                    
                    if(currentWord == endWord)
                        return currentLevel + 1;
                    
                    if(wordSet.find(currentWord) != wordSet.end() && visited.find(currentWord) == visited.end()) {
                        visited.insert(currentWord);
                        q.push({currentWord, currentLevel + 1});
                    }
                }
                currentWord[i] = originalChar;
            }
        }
        
        return 0;
    }
};
