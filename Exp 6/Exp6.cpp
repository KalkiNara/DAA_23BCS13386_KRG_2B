#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

bool canPartition(vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr)
        totalSum += num;

    if (totalSum % 2 != 0)
        return false;

    return subsetSum(arr, totalSum / 2);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (canPartition(arr))
        cout << "Yes, array can be partitioned into two subsets of equal sum!" << endl;
    else
        cout << "No, array cannot be partitioned into two subsets of equal sum!" << endl;

    return 0;
}
