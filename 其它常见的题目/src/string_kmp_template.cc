#include <string>
#include <vector>
#include <iostream>
using namespace std;

int kmp(string& text,string &pattern){
    /*
        A B A B C A B A B A
        0,0,1,2,0,1,2,3,4 3
    */
    int n = pattern.length();
    vector<int> lps(n,0); // the length of common prefix and suffix
    int len = 0;
    for(int i=1;i<n;){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len - 1 >= 0){
                len = lps[len - 1];
            } else {
                len = 0;
                lps[i] = 0;
                i++;
            }
        }
    }
    int i = 0; // point to text
    int j = 0; // point to pattern
    for(;i < text.length();){
        if(text[i] == pattern[j]){
            i++;
            j++;
        } else {
            if(j - 1 >= 0){
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if(j == pattern.length()){
            // find 
            return i - pattern.length();
        }
    }
    return -1;
}

int main(){
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    std::cout << kmp(text,pattern) << std::endl;
    return 0;
}