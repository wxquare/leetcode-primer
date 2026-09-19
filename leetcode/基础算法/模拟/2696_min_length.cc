class Solution {
public:
    int minLength(string s) {
        /*
            "ABFCACCDDB"
        */
        
        bool con = true;
        int start = 0;
        while(con){
            if((start = s.find("AB")) != string::npos){
                con = true;
                s = s.erase(start,2);
                continue;
            }
            
            if((start = s.find("CD")) != string::npos){
                con = true;
                s = s.erase(start,2);
                continue;
            }
            con = false;
        }
        return s.length();
    }
};