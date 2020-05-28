class Trie {
    
private: 
    struct node {
        bool end = false;
        node* child[26]; 
    };
    
public:
    /** Initialize your data structure here. */
    node* root;
    Trie() {
        root = new node();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* curr = root;
        for (char c : word){
            if (curr->child[c-'a'] == NULL) 
                curr->child[c-'a'] = new node();
            curr = curr->child[c-'a'];
        }
        curr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* curr = root;
        for (char c : word){
            if (curr->child[c-'a'] == NULL)
                return false;
            curr = curr->child[c-'a'];
        }
        return curr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* curr = root;
        for (char c : prefix){
            if (curr->child[c-'a'] == NULL)
                return false;
            curr = curr->child[c-'a'];
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