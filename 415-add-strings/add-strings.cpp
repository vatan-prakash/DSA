class Solution {
public:
   
   string add(string& num1,string& num2){
       
        int i1=num1.size()-1;
        int i2=num2.size()-1;

        string ans;
        int carry=0, sum;

        while(i2>=0){
            sum = (num1[i1]-'0') + (num2[i2]-'0') + carry;
            carry= sum/10;
            char c='0'+ (sum%10);
            ans+=c;
            i1--;i2--;

        }

        while(i1>=0){
            sum=  (num1[i1]-'0')  + carry;
            carry= sum/10;
            char c='0'+ ( sum % 10 );
            ans+=c;
            i1--;
        }
        if(carry){
            ans+=(carry+'0');
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
    
    string addStrings(string num1, string num2) {
       if(num1.size()<num2.size()){
        return add(num2,num1);
       }
       else {
       return add(num1,num2);
       }

    }
};