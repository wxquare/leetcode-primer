


#include <iostream>
#include <vector>

using namespace std;


void kmp(string& text,string pattern) {
    int n = pattern.length();
    vector<int> lps(n,0);  // the longest length prefix that equals to suffix.
    int len = 0;
    for(int i=1;i<pattern.length();){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0){
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int i = 0; // point to text
    int j = 0; // point to pattern
    while(i < text.length()){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        // 找个一个匹配的
        if(j == pattern.length()){
            int start = i - j;
            std::cout << "find and start " << start << std::endl;
            j = lps[j-1]; 
        } else if(i < text.length() && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
}


int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    kmp(text,pattern);
    return 0;
}
