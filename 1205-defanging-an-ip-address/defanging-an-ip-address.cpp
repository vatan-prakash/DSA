class Solution {
public:
    string defangIPaddr(string address) {
        int i=0;
        string temp="";
        while(i<address.length()){
            if(address[i]=='.'){
            temp+="[.]";
            }
            else{
                temp.push_back(address[i]);
            }
            i++;
        }
        return temp;
    }
};