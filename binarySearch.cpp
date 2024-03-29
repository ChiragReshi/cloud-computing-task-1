#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }

        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;

    // Perform binary search
    int result = binarySearch(arr, target);

    // Print the result
    if (result != -1) {
        std::cout << "Element found at index " << result << "\n";
    } else {
        std::cout << "Element not found in the array\n";
    }

    return 0;
}
