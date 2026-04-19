struct trieNode{
    trieNode *child[26];
    bool isEnd;

    trieNode(){
        isEnd = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};


class Trie {
public:
    trieNode *root;
    Trie() {
        root = new trieNode;;
    }
    
    void insert(string word) {
        trieNode *node = root;
        for(char c:word){
            int idx = c-'a';
            if(node->child[idx] == NULL)
                node->child[idx] = new trieNode;
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        trieNode *node = root;
        for(char c:word){
            int idx = c-'a';
            if(node->child[idx] == NULL)
                return false;
            node = node->child[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        trieNode *node = root;
        for(char c:prefix){
            int idx = c-'a';
            if(node->child[idx]==NULL)
                return false;
            node = node->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */