class Solution {
public:
    int strStr(string haystack, string needle) {
    int m=needle.length();
    int n=haystack.length();
    if(m==0 || n==0) return -1;
    if(m>n) return -1;
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m && haystack[i+j]==needle[j]){
            j++;
        }
        if(j==m) return i;
    }
    return -1;  
    }
};