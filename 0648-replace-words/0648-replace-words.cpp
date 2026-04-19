struct trienode{
    trienode *child[26];
    bool isend;
    trienode(){
        isend = false;
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
            node->isend = true;
        }

        string prefix(string word){
            trienode *node = root;
            string pr;

            for(auto c:word){
                int idx = c-'a';
                if(!node->child[idx])
                    return word;
                
                pr+=c;
                node = node->child[idx];

                if(node->isend)
                    return pr;
            }
            return word;
        }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie t;
        for(int i=0;i<dictionary.size();i++){
            t.insert(dictionary[i]);
        }

        string ans = "";
        trienode *node = t.root;

        stringstream ss(sentence);
        string word;

        while(ss >> word){
            string newStr = t.prefix(word);
            ans+=newStr+" ";
        }

        ans.pop_back();
        return ans;

    }
};