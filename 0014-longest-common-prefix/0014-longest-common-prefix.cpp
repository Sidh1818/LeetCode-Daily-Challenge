struct trienode{
    trienode *child[26];
    bool isEnd;

    trienode(){
        isEnd = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

class trie{
    public:
        trienode *root;
        trie(){
            root = new trienode;
        }

        void insert(string word){
            trienode *node = root;
            for(char c:word){
                int idx = c-'a';
                if(node->child[idx] == NULL)
                    node->child[idx] = new trienode;
                node = node->child[idx];
            }
            node->isEnd = true;
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie t;
        for(int i=0;i<strs.size();i++){
            t.insert(strs[i]);
        }
        trienode* node = t.root;
        string ans = "";

        while(true){
            int cnt=0 ,idx=-1;
            for(int i=0;i<26;i++){
                if(node->child[i]){
                    cnt++;
                    idx = i;
                }
            }
            if(cnt!=1 || node->isEnd)
                break;
            ans+=(char)(idx+'a');
            node = node->child[idx];
        }
        return ans;
    }
};