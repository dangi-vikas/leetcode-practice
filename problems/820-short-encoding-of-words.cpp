class Trie {
public:
  struct Node {
    Node() : children(26, nullptr) {}
    vector<Node*> children;
  };

  Trie() : root_(new Node()) {}

  bool insert(const string &str) {
    Node *p = root_.get();
    bool isNewWord = false;
      
    for (int i=str.size()-1; i<str.size(); i--) {
      Node* &child = p->children[str[i] - 'a'];
        
      if (!child) {
        if (!isNewWord) isNewWord = true;
        child = new Node();
      }
        
      p = child;
    }
      
    return isNewWord;
  }
    
private:
    unique_ptr<Node> root_;
    
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        int sum = 0;
        
        sort(words.begin(), words.end(),
             [](const string &a, const string &b) {return a.size() > b.size();});
        
        for (string &word : words) {
            bool isNewWord = trie.insert(word);
            if (isNewWord) sum += word.size() + 1;
        }
        
        return sum;
    }
};