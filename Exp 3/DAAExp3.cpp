#include <iostream>
#include <unordered_map>
using namespace std;

void findFrequency(int arr[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    cout << "Element   Frequency\n";
    for (auto it : freq) {
        cout << it.first << "   " << it.second << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    findFrequency(arr, n);
    return 0;
}
