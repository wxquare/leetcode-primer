#include <string>
#include <vector>
#include <iostream>
using namespace std;

int kmp(string text,string pattern){
    int n = pattern.length();
    vector<int> lps(n,0);
    int len = 0;
    for(int i=1;i<n;){
        if(pattern[i] == pattern[len]){
            lps[i] = len + 1;
            i++;
        } else {
            if(len != 0){
                len = lps[len-1];
            } else {
                i++;
            }
        }  
    }
    int i=0;
    int j = 0;
    while(i < text.length() && j < pattern.length()){
        if(text[i] == pattern[j]){
            i++;
            j++;
        } else {
            if(j != 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    if(j == pattern.length()){
        return i - pattern.length();
    }
    return -1;
}

int main(){
    std::cout << kmp("ABABCABABA","ABC") << std::endl;
}