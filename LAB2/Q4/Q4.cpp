#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int Partition(int arr[], int l, int r){
    int lst = arr[r], i = l, j = l;
    while (j < r) {
        if (arr[j] < lst) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int randomPartition(int arr[], int l,int r){
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return Partition(arr, l, r);
}

void MedianCal(int arr[], int l, int r,int k, int& a, int& b){
    if (l <= r) {
        int partitionIndex = randomPartition(arr, l, r);
        if (partitionIndex == k) {
            b = arr[partitionIndex];
            if (a != -1)
                return;
        }
 
        else if (partitionIndex == k - 1) {
            a = arr[partitionIndex];
            if (b != -1)
                return;
        }
 
        if (partitionIndex >= k)
            return MedianCal(arr, l,partitionIndex - 1,k, a, b);
 
        else
            return MedianCal(arr,partitionIndex + 1,r, k, a, b);
    }
 
    return;
}

int findMedian(int arr[], int n){
    int ans, a = -1, b = -1;
    if (n % 2 == 1) {
        MedianCal(arr, 0, n - 1,n / 2, a, b);
        ans = b;
    }
    else {
        MedianCal(arr, 0, n - 1,n / 2, a, b);
        ans = (a + b) / 2;
    }
    return ans;
}

int main(){
    
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }

    int n;
    inputFile>>n;
    
    int *A = new int[n];
    for(int i=0;i<n;i++){inputFile>>A[i];}
    inputFile.close();

    clock_t start,end;
    start=clock();
    int median = findMedian(A,n);
    end=clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);

    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec for "<<n<<" elements"<<endl;
    outputFile<<"The median of the unsorted array is: "<<median<<endl;
}