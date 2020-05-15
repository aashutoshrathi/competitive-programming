class Trie {
public:
    
    struct Node {
        unordered_map<char, Node*> children; // store all children nodes
        bool isCorona; // checks if this is the end
    };
    
    Node* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        iterationHelper(word, true);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* it = iterationHelper(word);
        return it && it->isCorona;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return !!iterationHelper(prefix);
    }
    
    
    /** One Helper to rule them all */
    Node* iterationHelper(string str, bool toInsert = false) {
        Node* it = root;
        for(char c: str) {
            if(it->children.find(c) == it->children.end()) {
                if(toInsert) {
                    it->children[c] = new Node();
                } else {
                    return NULL;
                }
            }
            it = it->children[c];
        }
        if(toInsert) {
            it->isCorona = true;
        }
        return it;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */