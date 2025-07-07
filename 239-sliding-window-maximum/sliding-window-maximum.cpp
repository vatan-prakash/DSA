class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
       
       
        vector<int> result;
        deque<int> dq;
        int i = 0, j = 0;
         while(j<arr.size()){
            //calculation 
            
            while(dq.size()>0 && dq.back()<arr[j]){
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            if(j-i+1<k) j++;

           else if(j-i+1==k) {
            result.push_back(dq.front());
            //slide window
            if(dq.front()==arr[i]){
                dq.pop_front();
            }
            i++;j++;
           }
         }
         
        return result;
    }
};