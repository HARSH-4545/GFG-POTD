class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
         int n = arr.size(), index = -1;

        
        for (int i = n - 1; i >= 1; i--) {
            if (arr[i - 1] < arr[i]) {
                index = i - 1;
                break;
            }
        }

       
        if (index == -1) {
            std::reverse(arr.begin(), arr.end());
            return;
        }

   
        for (int i = n - 1; i > index; i--) {
            if (arr[i] > arr[index]) {
                std::swap(arr[i], arr[index]);
                break;
            }
        }

        
        std::reverse(arr.begin() + index + 1, arr.end());
    }
};
