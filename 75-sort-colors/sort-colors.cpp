class Solution {
public:
    void sortColors(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        int mid=0;
        while(mid<=j){
            if(arr[mid]==0){
                swap(arr[i],arr[mid]);
                i++;mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
           else if(arr[mid]==2){
                swap(arr[mid],arr[j]);
                j--;
            }

        }

        

        }

};