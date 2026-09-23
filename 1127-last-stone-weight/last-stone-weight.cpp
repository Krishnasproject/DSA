class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int>pq;

        for(int ch : stones){
            pq.push(ch);
        }

       while( pq.size()>1){

        int temp = pq.top();
            pq.pop();
            int a = pq.top();
            pq.pop();
            if(temp!=a){
                //temp = 0;
                a = temp-a;
                pq.push(a);
            } 
       } 
       if(pq.size()==1)
        return pq.top();
    else
         return 0;
    }
    
};