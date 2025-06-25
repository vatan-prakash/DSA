class Solution {
public:
    string sortSentence(string s) {
        string temp="";
        vector<string> ans(10); 
        int index=0;
        int count=0;

        while(index<s.length()){
            if(s[index] == ' '){
               //find position of words in sentence by last char
               
               int pos=temp.back()-'0';//converted string to num
               temp.pop_back(); //remove num from word which is at last 
               ans[pos]=temp;
               count++;// to count number of words
               temp="";//empty temp again
            }
            else{
                temp+=s[index];
                
            }
            index++;
        }

        int pos=temp.back()-'0';//converted string to num
               temp.pop_back(); //remove num from word which is at last 
               ans[pos]=temp;
               count++;// to count number of words
               temp="";

        for(int i=1;i<=count;i++)  {
            temp+=ans[i]+" ";
           
        }

        temp.pop_back();
        return temp;     
    }
};