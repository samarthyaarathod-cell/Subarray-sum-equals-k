#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;  // Base case

    int sum = 0, count = 0;

    for (int num : nums) {
        sum += num;

        // Check if (sum - k) exists
        if (mp.find(sum - k) != mp.end()) {
            count += mp[sum - k];
        }

        // Store current prefix sum
        mp[sum]++;
    }

    return count;
}

// Driver code
int main() {
    vector<int> nums1 = {1,1,1};
    int k1 = 2;
    cout << "Output: " << subarraySum(nums1, k1) << endl;

    vector<int> nums2 = {1,2,3};
    int k2 = 3;
    cout << "Output: " << subarraySum(nums2, k2) << endl;

    return 0;
}