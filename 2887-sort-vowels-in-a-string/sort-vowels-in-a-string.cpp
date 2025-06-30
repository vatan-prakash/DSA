class Solution {
public:
    string sortVowels(string s) {
    vector<int> upper(26,0);
    vector<int> lower(26,0);
    string ans="";

    for(int i=0;i<s.size();i++){
        if(s[i] =='A' || s[i] =='E' || s[i] =='I' || s[i] =='O' || s[i] =='U'){
            upper[s[i]-'A']++;
            s[i]='#';
        }

        else if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
          lower[s[i] - 'a']++;
          s[i] = '#'; 
          }
    }


     //l##tc#d#
    for(int i=0;i<26;i++){
       char c='A'+i;
       while(upper[i]){
        ans+=c;
        upper[i]--;
       }
    }

     for(int i=0;i<26;i++){
       char c='a'+i;
       while(lower[i]){
        ans+=c;
        lower[i]--;
       }
    }
    int i=0;
    int j=0;

    while(j<ans.size()){
        if(s[i] =='#'){
            s[i]=ans[j];
            j++;
        }
        i++;
    }
    return s;

    }        
};