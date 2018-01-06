#include <iostream>
#include <string>
#include <vector>

#include "Dictionary.h"

using namespace std;


int dnum=128;


//LZW Algorithm
void encode(string s){
    Trie dict;
    string w = "";
    string K;
    while (s.length()>0){
        K = s[0]; //next symbol from S
        if (dict.found(w+K))
            w=w+K;
        else{
            cout<<dict.index(w)<<" ";
            dict.insert(w+K);
            w=K;
        }
    }
    cout<<dict.index(w)<<endl;
}
  


int main(){
    char c;
    string s="";
    while (cin.get(c)){
        s=s+c;
    }
    encode (s,dict);
}



