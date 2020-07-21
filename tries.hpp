//
//  tries.h
//  tries
//
//  Created by Alejandro  Otero on 7/19/20.
//  Copyright © 2020 Alejandro  Otero. All rights reserved.
//

#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace tries {

class node{
public:
    map<char, node*> children;
    bool isComplete;
    
    node():isComplete(false){}
};

class Tries{
private:
    typedef node Node;
    Node* root;

    bool remove_word(Node*& leaf, char* word){
        if(leaf == nullptr)
            return false;
        
        if(*word){
            if(leaf != nullptr && leaf->children.find(*word) != leaf->children.end() && 
            remove_word(leaf->children[*word],word + 1) && leaf->isComplete == false){
                if(hasChildren() == false){
                    delete leaf;
                    leaf = nullptr;
                    return true;
                }
                else
                    return false;
            }
        }

        if(*word == '\0' && leaf->isComplete){
            if(hasChildren() == false){
                delete leaf;
                leaf = nullptr;
                return true;
            }else
            {
                leaf->isComplete = false;
                return false;
            }
            
        }
        return false;
    }

    vector<string> prefix(string pre, vector<string> vec){

    }
    
public:
    Tries():root(nullptr){}
    
    void insert(string word){
        if(root == nullptr)
            Node* new_node = new Node();
        
        Node* temp = root;

        for(int i = 0; i < word.length(); i++){
            char ch = word[i];

            if(temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new Node();

            temp = temp->children[ch];   
        }

        temp->isComplete = true;
    }

    bool hasChildren(){
        for(auto& it : root->children)
            if(it.second != nullptr)
                return true;
        return false;
    }
    
    vector<string> search_by_prefix(string pre){
        vector<string> vec;

        vec = prefix(pre, vec);        
    }
    
    void remove(char *word){
        if(root == nullptr)
            return;
        
        Node* temp = root;

        remove_word(temp, word);
    }
    
    bool search_word(string word){
        if(root == nullptr)
            return false;

        Node* temp = root;

        for(int i = 0; i < word.length(); i++){
            temp = temp->children[word[i]];

            if(temp == nullptr)
                return false;
        }

        return true;
    }
    
    void print(){
        if(root == nullptr)
            return;
        
        Node* temp = root;

        string word = "";

        for(auto it : temp->children){
            word += it.first;
            if(it.second->isComplete == true){
                cout<<word<<endl;
                word = "";
            }
        }
    }
    
    
    ~Tries(){}
};

}
