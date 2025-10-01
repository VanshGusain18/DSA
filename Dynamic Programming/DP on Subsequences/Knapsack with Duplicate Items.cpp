// Brute Approch

class Solution {
  public:
    int fn(vector<int>& val, vector<int>& wt, int capacity, int idx)
    {
        if(capacity == 0) return 0; 
        if(idx == 0)
        {
            return (capacity / wt[0]) * val[0]; 
        }
        
        int notTaken = fn(val, wt, capacity, idx-1);
        int taken = -1e9;
        if(wt[idx] <= capacity)
        {
            taken = val[idx] + fn(val, wt, capacity-wt[idx], idx);
        }
        return max(notTaken, taken);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        return fn(val, wt, capacity, n-1);
    }
};
