#include <iostream>

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> arr[i];
    }
    std::cout << "The elements of the array are: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

