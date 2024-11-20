#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {}; // Handle empty input
        if (n == 1) return arr; // Single element array

        vector<int> ans;
        int ele1 = INT_MIN, ele2 = INT_MIN, c1 = 0, c2 = 0;

        // Step 1: Find potential majority elements
        for (int i = 0; i < n; i++) {
            if (arr[i] == ele1) {
                c1++;
            } else if (arr[i] == ele2) {
                c2++;
            } else if (c1 == 0) {
                ele1 = arr[i];
                c1 = 1;
            } else if (c2 == 0) {
                ele2 = arr[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        // Step 2: Verify the potential majority elements
        c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == ele1) c1++;
            else if (arr[i] == ele2) c2++;
        }

        if (c1 > n / 3) ans.push_back(ele1);
        if (c2 > n / 3 && ele2 != ele1) ans.push_back(ele2); // Avoid duplicates

        sort(ans.begin(), ans.end()); // Optional: Return sorted output
        return ans;
    }
};
