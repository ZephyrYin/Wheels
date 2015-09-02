//
//  main.cpp
//  prefixTree
//
//  Created by Xinyi Yin on 8/26/15.
//  Copyright (c) 2015 Xinyi Yin. All rights reserved.
//

#include <iostream>

using namespace std;

class TrieNode {
    
public:
    int count;
    TrieNode *children[26];
    // Initialize your data structure here.
    TrieNode() {
        count = 0;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    
    TrieNode *createNode(){
        TrieNode *node = new TrieNode();
        node->count=0;
        for(int i=0;i<26;i++)
            node->children[i]=NULL;
        return node;
    }
    void insert(string word) {
        TrieNode *p = root;
        for(auto &w:word){
            if(p->children[w-'a'] == NULL){
                p->children[w-'a'] = createNode();
            }
            p = p->children[w-'a'];
        }
        p->count++;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for(auto &w:word){
            if(p==NULL)
                return false;
            p = p->children[w-'a'];
        }
        return (p!=NULL)&&(p->count>0);
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(auto &w:prefix){
            if(p==NULL)
                return false;
            p = p->children[w-'a'];
        }
        
        return (p!=NULL);
    }
    
private:
    TrieNode* root;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Trie t;
    cout<<t.startsWith("a");
    return 0;
}
