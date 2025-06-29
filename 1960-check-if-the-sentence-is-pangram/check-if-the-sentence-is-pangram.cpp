class Solution {
public:
    bool checkIfPangram(string sentence) {
    string alphabet = "";

    char ch = 'a';
    while (ch <= 'z') {
        alphabet += ch;
        ch++;
    }
    unordered_map<char,int> mp;
    for(int x:sentence){
        mp[x]++;
    }
    if(mp.size()==26) return true;
    else return false;
     

    


    }
};