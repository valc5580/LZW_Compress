#include "Dictionary.h"
#include <string>
using namespace std;


Node::Node(int code){
    this->code=code;
    for (int i=0; i<128; i++)
        this->children[i]=NULL; //new Node(0);
}

Trie::Trie(){
    root=new Node(0);
    for (int i=0; i<128; i++)
        root->children[i]=new Node(i);
    dnum=127; //max index in dictionary so far
}

void insertHelper (Node *current, string s, int dnum){
    if (s.length()==1){
        current->children[(int)s[0]]=new Node (dnum);
    }
    else{
        char c=s[0];
        s.erase(s.begin(),s.begin()+1);
        insertHelper (current->children[(int)c], s,dnum);
    }
}

void Trie::insert(string s){
    dnum++;
    insertHelper(root, s, dnum);
}

bool foundHelper (Node *current, string s){
    if ((s.length()>=1)&&(current->children[(int)s[0]]==NULL))
        return false;
    else if ((s.length()==1)&&(current->children[(int)s[0]]!=NULL))
        return true;
    else{
        char c=s[0];
        s.erase(s.begin(),s.begin()+1);
        return foundHelper(current->children[(int)c],s);
    }
}

bool Trie::found(string s){
    return foundHelper (root,s);
}

int indexHelper (Node *current, string s){
    if (s.length()==0)
        return current->code;
    else{
        char c= s[0];
        s.erase(s.begin(),s.begin()+1);
        return indexHelper (current->children[(int)c],s);
    }
        
}


int Trie::index(string s){
    return indexHelper (root, s);
}






