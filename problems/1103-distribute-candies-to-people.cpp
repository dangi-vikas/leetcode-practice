class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
		int i = 0, x = 1;
        
		while(candies != 0){
			if(candies < x) {
				ans[i % num_people] += candies;
				break;
			}

			ans[i % num_people] += x;
			candies -= x;

			x++; i++;
		}

		return ans;
    }
};