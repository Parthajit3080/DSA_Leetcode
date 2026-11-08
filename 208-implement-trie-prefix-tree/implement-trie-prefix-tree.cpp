class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        for(int i = 0; i < 26; i++)
            links[i] = nullptr;

        flag = false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(char c : word){
            int index=c-'a';
            if(!node->links[index])
                node->links[index]=new Node();

            node=node->links[index];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node *node=root;
        for(char c : word){
            int index=c-'a';
            if(!node->links[index])
                return false;

            node=node->links[index];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(char c : prefix){
            int index=c-'a';
            if(!node->links[index])
                return false;
            node=node->links[index];
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