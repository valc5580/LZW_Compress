# LZW_Compress
After learning about the Lempel-Ziv-Welch compression method in school, I thought it would be fun to implement both the encoder and decoder. This is an "adaptive" compression algorithm that works especially well on text with repeated substrings.
For example, try inputting "yoyoyoyoyoyoyoyoyoyo" and you will see a lossless and very high compression rate. Also try inputting that when trying to decompress to confirm.
Compile in terminal using command "g++ -std=c++14 Dictionary.cc code.cc -o run"
