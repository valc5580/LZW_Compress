#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>

#include "Dictionary.h"

using namespace std;

//Vector of source text
vector<int> source;

//Vector of encoded data
vector<int> encoded;

//vector of inputted compressed text
vector<int> compress;

//dictionary for decoding
vector<string> dict2;

//vector of decoded text
vector <string> decoded;

void printVector (vector <int> v){
    for (int i=0; i<v.size()-1; i++)
        cout<<v[i]<<" ";
    cout<<v[v.size()-1]<<endl;
}
void printVector (vector <string> v){
    for (int i=0; i<v.size()-1; i++)
        cout<<v[i];
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

void decode (){
    for (int i=0; i< 128; i++){
        string s;
        s.push_back((char)i);
        dict2.push_back(s);
    }
    int idx=128;
    int code=compress[0];
    compress.erase(compress.begin(),compress.begin()+1);
    string s=dict2[code];
    decoded.push_back(s);
    while(compress.size()!=0){
        string sPrev=s;
        code=compress[0];
        compress.erase(compress.begin(),compress.begin()+1);
        if (code==idx)
            s=sPrev+sPrev[0];
        else
            s=dict2[code];
        decoded.push_back(s);
        dict2.push_back(sPrev+s[0]);
        idx=idx+1;
    }
}


int main(){
    cout<<"Enter 'compress' or 'decompress' and click enter:";
    string input;
    getline(cin,input);
    if (input=="compress"){
        char c;
        string s="";
        string input;
        int numOfChars= 0;
        cout<<"Enter text (ascii) below to code and compress:"<<endl;
        getline(cin,input);
        istringstream ss {input};
        while (ss>>c){
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
        return 1;
    }
    else if (input=="decompress"){
        int i;
        cout<<"Enter the compressed code in the form of integers seperated by spaces below:"<<endl;
        string s;
        getline(cin,s);
        istringstream ss{s};
        while(ss>>i){
            compress.push_back(i);
        }
        decode();
        cout<<"The decoded text is:"<<endl;
        printVector(decoded);
        cout<<endl;
        return 1;
    }
    else{
        cout<<"Invalid input, I said enter either 'compress' or 'decompress'."<<endl;
        return 0;
    }
}



