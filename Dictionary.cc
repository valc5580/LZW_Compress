

#include "Dictionary.h"


Node::Node(int code){
    this->code=code;
    for (int i=0; i<128; i++)
        this->children[i]=NULL; //new Node(0);
}

Trie::Trie(){
    root=new Node(0);
    for (int i=0; i<128; i++)
        root->children[i]=new Node(i);
    dnum=128;
}

void insertHelper (Node *current, string s, int dnum){
    if (s.length()==1){
        current->chidlren[(int)s[0]]=new Node (dnum);
    }
    else{
        s.erase(str.begin(),str.begin()+1);
        insertHelper (current->children[(int)s[0]], s,dnum)
    }
}

Trie:insert(string s){
    dnum++;
    insertHelper(root, s, dnum);
}

bool foundHelper (Node *current, string s){
    if ((s.length()>=1)&&(current->children[(int)s[0]]==NULL))
        return false;
    else if ((s.length()==1)&&(current->children[(int)s[0]]!=NULL))
        return true;
    else{
        s.erase(str.begin(),str.begin()+1);
        return foundHelper(current->children[(int)s[0]],s);
    }
    
             
}

Trie::found(string s){
    return foundHelper (root,s);
}

int indexHelper (Node *current, string s){
    if (s.length()==0)
        return current->code;
    else{
        s.erase(str.begin(),str.begin()+1);
        return indexHelper (current->children[(int)s[0]],s);
    }
        
}


Trie::index(string s){
    return indexHelper (root, s);
}






