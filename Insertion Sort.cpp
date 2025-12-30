#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(n^2) in worst and average case, O(n) in best case
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    insertionSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
