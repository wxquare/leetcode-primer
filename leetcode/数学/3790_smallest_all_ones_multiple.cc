class Solution { public: int minAllOneMultiple(int k){int r=0;for(int i=1;i<=k;++i){r=(r*10+1)%k;if(!r)return i;}return -1;} };
