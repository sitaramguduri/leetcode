// Last updated: 02/08/2025, 18:49:18
struct Node{
    Node* lists[26];
    bool flag = false;
    bool containsKey(char ch){
        return lists[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        lists[ch - 'a'] = node;
    }
    Node* get(char ch){
        return lists[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
    Node* root;
    bool searchHelper(string& word, int index, Node* node){
        if(!node){
            return false;
        }
        if (index == word.size()){
            return node->isEnd();
        }
        char ch = word[index];
        if(ch == '.'){
            for(int i = 0; i<26; i++){
                if(node->lists[i] && searchHelper(word,index+1,node->lists[i])){
                    return true;
                }
            }
            return false;
        }else{
            if(!node->containsKey(ch)){
                return false;
            }
            return searchHelper(word,index+1,node->get(ch));
        }
    }
    public: 
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        return searchHelper(word,0,root);
    }
};
class WordDictionary {
    Trie trie;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */