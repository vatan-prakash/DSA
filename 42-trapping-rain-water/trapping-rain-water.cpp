class Solution {
public:
    int trap(vector<int>& height) {
       
       
        int n=height.size();
        if (n == 0) return 0;
         vector<int> maxleft(n);
         maxleft[0]=height[0];
        for(int i=1;i<n;i++){
            maxleft[i]=max(maxleft[i-1],height[i]);
        }
         vector<int> maxright(n);
         maxright[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--){
            maxright[i]=max(maxright[i+1],height[i]);
        }
        
          vector<int> water(n);
         int sum=0;
        for(int i=0;i<n;i++){
            water[i]=min(maxright[i],maxleft[i])-height[i];
            if(water[i]>0) sum+=water[i];
        }
       return sum;

    }
};