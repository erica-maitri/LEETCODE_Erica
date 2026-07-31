#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        for (int x : nums) {
            // Keep first two elements or any element
            // that is different from nums[k-2]
            if (k < 2 || x != nums[k - 2]) {
                nums[k] = x;
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = obj.removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "Modified Array: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}