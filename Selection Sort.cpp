#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(n^2) for all cases
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    selectionSort(arr);
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
