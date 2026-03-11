class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        int n = arr.size();

        for (int i = 0; i <= n - k; i++) {
            int maxval = arr[i];

            for (int j = i; j < i + k; j++) {
                if (arr[j] > maxval) {
                    maxval = arr[j];
                }
            }

            ans.push_back(maxval);
        }

        return ans;
    }
};