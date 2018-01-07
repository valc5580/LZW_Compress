//

#ifndef Dictionary_h
#define Dictionary_h

//We will use 2 different dictionaries: a trie when encoding, and a dynamic array (vector) for decoding

#include <string>
using namespace std;
//A single node in the Trie represents a new substring built on by one more letter from its parent
//each node contains the dictionary key for the substring
class Node{
    public:
        int code;
        Node* children[128];
        Node (int code);
};


class Trie{
    Node * root;
    int dnum;//the current highest index in the dictionaryi
    public:
    Trie();
    void insert(string s); //inserts a new node every time with the string being represented by the path to get to the node
    bool found(string s);//returns a bool indicating whether or not the string was found in the dictionary
    int index(string s);//returns the key of that substring in the dictionary (represented as a node in trie
};








#endif
