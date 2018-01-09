#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "Dictionary.h"

using namespace std;

//Vector of source text
vector<int> source;

//Vector of encoded data
vector<int> encoded;

void printVector (vector <int> v){
    for (int i=0; i<v.size()-1; i++)
        cout<<v[i]<<" ";
    cout<<v[v.size()-1]<<endl;
}

//Compression Ratio Calculator  =  Size of coded in bits / Size of source text
double CompCalc (int cNum, int sNum){
    return ((double)cNum*7)/((double)sNum*8)*100;
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
    cout<<"Enter text (ascii) below to code and compress:"<<endl;
    while (cin.get(c)){
        if (c>127){
            cout<<"\nYou entered a character not in the 128 ascii characters."<<endl;
            return 0;
        }
        s=s+c;
        numOfChars++;
        source.push_back((int)c);
    }
    
    cout<<"Converting each character to int (index in ascii table) we get:"<<endl;
    for (int i=0; i<source.size(); i++){
        cout<<source[i]<<" ";
    }
    cout<<endl;
    encode (s);
    cout<<"The encoded data is:"<<endl;
    printVector(encoded);
    cout<<"The compression on this text is: "<<CompCalc(encoded.size(),numOfChars)<<"%"<<endl;
    
}



