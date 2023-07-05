// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         int x = 0;
//         int f = 0;
//         int totalJobs = tasks.size();

//         unordered_map<char,int> mpp;
//         for(auto c:tasks){
//             mpp[c]++;
//             if(f < mpp[c]){
//                 f = mpp[c];
//             }
//         }

//         for(auto M:mpp){
//             if(M.second == f){
//                 x++;
//             }
//         }

//         int ans = max((n+1)*(f-1)+x, totalJobs);
//         return ans;
//     }
// };
class Solution{
public:
    int leastInterval(vector<char>& tasks, int n){
        
        unordered_map<char,int> mpp;
        for(auto c:tasks){
            mpp[c]++;
        }
        priority_queue<int> pq;
        for(auto m:mpp){
            pq.push(m.second);
        }

        int time = 0;
        while(!pq.empty()){
            int cycle = n+1;
            vector<int> remain;
            
            while(cycle > 0 && !pq.empty()){
                int maxLen = pq.top();
                pq.pop();
                if(maxLen > 1){
                    remain.push_back(maxLen-1);
                }
                time++;
                cycle--;
            }

            for(auto x:remain){
                pq.push(x);
            }

            if(pq.empty()) break;
            time += cycle;
        }

        return time;
    }
};