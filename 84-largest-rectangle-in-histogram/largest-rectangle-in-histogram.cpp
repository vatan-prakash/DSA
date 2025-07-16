class Solution {
public:
    
    vector<int> NSL(vector<int>& heights){
        
        int n=heights.size();
        vector<int> left(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >=heights[i]){
              st.pop();
            }
    //while loop khtam ab mtlb st.top<height[i] mtlb ans askta hai ab dekho stack empty hai ya nhi
            if(!st.empty()){
                left[i]=st.top();  //mtlb left me st.top hai or vo chota hai
            }
            else{
                left[i]=-1;//means left me elemnt bada hai current se
            }

            st.push(i);
        }
       return left;
    }

    vector<int> NSR(vector<int>& heights){
        int n=heights.size();
        vector<int> right(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >=heights[i]){
              st.pop();
            }
    //while loop khtam ab mtlb st.top<height[i] mtlb ans askta hai ab dekho stack empty hai ya nhi
            if(!st.empty()){
                right[i]=st.top();  //mtlb left me st.top hai or vo chota hai
            }
            else{
                right[i]=n;//means left me elemnt bada hai current se
            }

            st.push(i);
        }
       return right;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);

       int maxArea=0;

       for(int i=0;i<n;i++){

        int width=right[i]-left[i]-1;
        int area=heights[i]*width;

        maxArea=max(maxArea, area);
       }

       return maxArea;

    }
};