/*Boyer-Moore Voting Algorithm*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Handle empty vector edge case
        if (nums.empty()) return -1;

        int res = 0; 
        int c = 1;

        // Phase 1: Find a majority candidate
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[res]) {
                c++;
            } else {
                c--;
                if (c == 0) {
                    c = 1; 
                    res = i;
                }
            }
        }

        // Phase 2: Verify if the candidate is the actual majority
        c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[res] == nums[i]) {
                c++;
            }
        }

        if (c > nums.size() / 2) {
            return nums[res];
        }
            
        return -1; // Return -1 if no majority element exists
    }
};

int main() {
    Solution solution;
    
    // Test Case: 3 is the majority element (appears 4 times out of 7 elements)
    vector<int> nums = {3, 2, 3, 2, 3, 1, 3};
    
    int result = solution.majorityElement(nums);
    
    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "No majority element found." << endl;
    }
    
    return 0;
}
