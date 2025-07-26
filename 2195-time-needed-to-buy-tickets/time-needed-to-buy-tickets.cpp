class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
      int n=tickets.size();
      int time =0;
    //   int i=0 ;
       queue<int> q;
       for(int i=0;i<n;i++){
        q.push(i);
       }

       while(tickets[k]!=0){
       int f=q.front();
       tickets[f]--;
       //ky line me lagega
        if(tickets[f]>0){
            q.push(f);
        }
        q.pop();
        time++;
       }
      
      return time;
    }
};