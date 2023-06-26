class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int n = costs.size();
        for(int i = 0; i < candidates; i++){
            pq1.push(costs[i]);
        }

        for(int i = max(candidates, n - candidates); i < n; i++){
            pq2.push(costs[i]);
        }

        int head = candidates;
        int tail = n - candidates - 1;

        long long ans = 0;
        while(k > 0){
            if(pq2.empty() || !pq1.empty() && pq1.top() <= pq2.top()){
                ans += pq1.top();
                pq1.pop();

                if(head <= tail){
                    pq1.push(costs[head]);
                    head++;
                }
            }
            else{
                ans += pq2.top();
                pq2.pop();

                if(head <= tail){
                    pq2.push(costs[tail]);
                    tail--;
                }
            }
            k--;
        }

        return ans;
    }
};