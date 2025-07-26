class Solution {
public:
    int timeRequiredToBuy(vector<int>& ticket, int k) {
      int n=ticket.size();
      int time =0;
    //   int i=0 ;
      for(int i=0;i<=k;i++){
        time+=min(ticket[k],ticket[i]);
      }
       for(int i=k+1;i<n;i++){
     
        time+=min(ticket[k]-1,ticket[i]);
      }
      
      return time;
    }
};