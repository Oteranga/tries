#include <fstream>
#include <iostream>
#include "tries.hpp"

using namespace std;
using namespace tries;

vector<string> lectura(){
    vector<string> words;

    fstream file;

    file.open("texto.txt",ios::in);

    char ch;
    string str = "";

    while(file>>ch){
        file>>ch;
        if(ch != ' ' || ch != '.' || ch != ',')
            str += ch;
        else{
            words.push_back(str);
            str = "";
        }     
    }

    file.close();

    return words;
}

int main() {
    Tries trie;

    //trie.insert("hola");
    //trie.insert("ola"); 
    
    vector<string> text;

    text = lectura();

    for(int i = 0; i < text.size(); i++){
        trie.insert(text[i]);
    }
    
    return 0;
}
