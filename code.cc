#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "Dictionary.h"

using namespace std;

//Vector of encoded data
vector<int> encoded;

void printVector (vector <int> v){
    for (int i=0; i<v.size()-1; i++)
        cout<<v[i]<<" ";
    cout<<v[v.size()-1]<<endl;
}

//Compression Ratio Calculator  =  Size of coded * log (size of coded alphabet (just 0 or 1) /  Size of source * log (size of source alphabet)         * 100
///  (Number of items in vector * assume 12 bits per number * log 2 ) /  ( Number of Characters*(7 bits per character) * log (assume 128 possible characters) )         * 100
double CompCalc (int cSize, int cAlph, int sSize, int sAlph){
    return (cSize * log(cAlph))/(sSize * log (sAlph))*100;
}

//LZW Algorithm
void encode(string s){
    Trie dict;
    string w = "";
    string K;
    
    while (s.length()>0){
        
        K = s[0]; //next symbol from S
        if (dict.found(w+K)){
            w=w+K;
        }
        else{
            encoded.push_back(dict.index(w));
            dict.insert(w+K);
            w=K;
        }
        s.erase(s.begin(),s.begin()+1);
    }
    encoded.push_back(dict.index(w));
}
  


int main(){
    char c;
    string s="";
    int numOfChars= 0;
    while (cin.get(c)){
        s=s+c;
        numOfChars++;
    }
    encode (s);
    cout<<"The encoded data is:"<<endl;
    printVector(encoded);
    cout<<"The compression on this text is: "<<CompCalc(encoded.size()*12, 2, numOfChars*7, 128)<<"%"<<endl;
    
}



