class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double> pq;
        double total =0;
        for(int x : arr){
            pq.push((double)x);
            total += x;
        }
        double target = total / 2.0;
        double curr = total;
        int ops = 0;
     while( curr > target){
         double x = pq.top();
         pq.pop();
         double half = x / 2.0;
         curr -= (x - half);
         pq.push(half);
         ops++;
     }
        return ops;
    }
    
};