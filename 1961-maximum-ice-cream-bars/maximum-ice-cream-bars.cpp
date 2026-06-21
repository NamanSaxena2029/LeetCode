class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int steps = 0;
        // sort(costs.begin(),costs.end());
        // for(int i = 0 ; i < costs.size() ; i++) {
        //     if(costs[i]<=coins) {
        //         coins -= costs[i];
        //         steps++;
        //     } else {
        //         break;
        //     }
        // }
        // return steps;

        vector<int> freq(100001,0);
        for(int i : costs) {
            freq[i]++;
        }
        for(int i = 1 ; i < freq.size() ; i++) {
            if(freq[i]==0) {
                continue;
            }
            int x = min(freq[i],coins/i);
            steps += x;
            coins -= x*i;
            if(coins<i) {
                break;
            }
        }
        return steps;
    }
};