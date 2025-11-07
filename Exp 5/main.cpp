#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Merge two halves of the array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Generate random numbers
vector<int> generateRandomNumbers(int n, int range = 10000) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }
    return arr;
}

int main() {
    srand(time(0));

    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    for (int n : sizes) {
        vector<int> arr = generateRandomNumbers(n);

        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        cout << "Time taken to sort " << n << " elements using Merge Sort: "
             << duration.count() / 1000.0 << " milliseconds" << endl;
    }

    return 0;
}
