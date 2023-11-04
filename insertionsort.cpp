#include <ctime>
#include <bits/stdc++.h>
using namespace std;

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
main(){
    int arr[] = { 12, 11, 13, 5, 6}; // Time: 1e-06 seconds Arr Size: 5
    
    // int arr[] = { 12, 11, 13, 5, 6, 7, 5, 2, 76, 3, 1, 9, 10, 20, 40}; // Time: 1e-06 seconds Arr Size: 15
    
//    int arr[] = { 12, 11, 13, 5, 6, 7, 5, 2, 76, 3, 1, 9, 10, 100, 200, 300, 42, 23, 60, 20}; // Time: 1e-06 seconds Arr Size: 20
    
//    int arr[] = { 12, 11, 13, 6, 7, 5, 76, 3, 1, 9, 100, 200, 300, 42, 60, 30, 50, 23, 87, 38, 80, 12, 25, 544, 67, 643, 356, 324567, 256, 1223455}; // Time: 1e-06 seconds Arr Size: 30

    // Array 5 (Size 30)
    // int arr[] = {97, 62, 51, 82, 18, 46, 34, 29, 73, 11, 91, 38, 77, 57, 27, 69, 21, 83, 65, 49, 32, 68, 42, 13, 76, 52, 44, 35, 78, 31}; // Time: 1e-06 seconds Arr Size: 30

    // Array 6 (Size 56)
//    int arr[] = {93, 61, 14, 25, 37, 54, 76, 28, 49, 18, 66, 72, 43, 17, 29, 91, 38, 84, 57, 15, 62, 23, 79, 47, 31, 12, 67, 98, 53, 21, 86, 71, 34, 58, 97, 44, 24, 89, 64, 19, 27, 73, 42, 87, 63, 36, 52, 74, 46, 82, 22, 41, 81, 56, 33, 55}; // Time: 2e-06 seconds Arr Size: 56

    // Array 7 (Size 74)
//    int arr[] = {72, 61, 34, 22, 45, 93, 57, 16, 75, 41, 68, 81, 31, 88, 54, 37, 19, 69, 25, 47, 82, 65, 28, 94, 73, 42, 14, 62, 38, 71, 96, 23, 51, 77, 12, 64, 32, 89, 76, 49, 26, 58, 92, 53, 18, 36, 66, 21, 44, 74, 91, 63, 33, 78, 55, 11, 43, 85, 67, 29, 27, 52, 86, 59, 15, 56, 98, 24, 17, 79, 35, 87, 46, 10}; // Time: 3e-06 seconds Arr Size: 74

    // Array 8 (Size 157)
//    int arr[] = {31, 82, 67, 19, 94, 56, 39, 14, 75, 28, 46, 61, 98, 37, 22, 68, 25, 88, 51, 74, 33, 76, 49, 72, 44, 15, 63, 30, 85, 59, 26, 42, 77, 20, 66, 41, 12, 71, 38, 96, 54, 29, 69, 13, 87, 64, 18, 55, 84, 48, 11, 78, 47, 10, 27, 73, 40, 23, 70, 45, 90, 34, 52, 31, 89, 57, 16, 97, 62, 53, 21, 86, 60, 36, 24, 35, 50, 95, 32, 91, 58, 17, 92, 43, 79, 50, 75, 15, 81, 26, 55, 29, 66, 45, 98, 21, 56, 14, 84, 23, 64, 38, 72, 11, 37, 60, 91, 53, 31, 68, 12, 77, 59, 30, 87, 25, 82, 46, 28, 86, 52, 13, 97, 35, 70, 19, 78, 42, 63, 24, 44, 89, 67, 27, 79, 57, 20, 47, 32, 76, 71, 48, 73, 10, 95, 40, 18, 54, 34, 16, 33, 80, 22, 49, 74, 58, 85}; // Time: 6e-06 seconds Arr Size: 157
    
    int N = sizeof(arr) / sizeof(arr[0]);

    std::clock_t start_time = std::clock();
    insertionSort(arr, N);
    std::clock_t tot_time = std::clock() - start_time;
    std::cout << "Time: "
        << ((double) tot_time) / (double) CLOCKS_PER_SEC
        << " seconds" << " Arr Size: " << N << std::endl;
    return 0;
}
