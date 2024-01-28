#include <bits/stdc++.h> 
using namespace std; 



int cross_sum(int arr[], int l, int mid, int h) { 
    int sum = 0; 
    int leftSum = INT_MIN; 
    for (int i = mid; i >= l; i--) { 
        sum = sum + arr[i]; 
        if (sum > leftSum) 
            leftSum = sum; 
    } 

    sum = 0; 
    int rightSum = INT_MIN; 
    for (int i = mid; i <= h; i++) { 
        sum = sum + arr[i]; 
        if (sum > rightSum) 
            rightSum = sum; 
    } 

    
    return max({leftSum + rightSum - arr[mid], leftSum, rightSum}); 
} 

int subarray_sum(int arr[], int l, int h) { 
    if (l > h) 
        return INT_MIN; 
    if (l == h) 
        return arr[l]; 

    int mid = (l + h) / 2; 

   
    return max({subarray_sum(arr, l, mid - 1), 
            subarray_sum(arr, mid + 1, h), 
            cross_sum(arr, l, mid, h)}); 
} 

int main() { 
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the input file" << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening the output file" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        inputFile >> arr[i];
    }

    int maxSum = subarray_sum(arr, 0, n - 1);

    outputFile << "Maximum contiguous sum is " << maxSum;

    delete[] arr;
    inputFile.close();
    outputFile.close();

    return 0; 
}