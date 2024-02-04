#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

int k_largest(int arr[], int l, int r, int K)
{
	if (K > 0 && K <= r - l + 1) {
		int p = partition(arr, l, r);
		if (p - l == K - 1)
			return arr[p];
		if (p - l > K - 1)
			return k_largest(arr, l, p - 1, K);
		return k_largest(arr,p+1,r,K-p+l-1);			
	}
	return INT_MIN;
}
int main()
{
	 ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    int n,k;
    inputFile >> n>>k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        inputFile >> a[i];
    }
    inputFile.close();
    ofstream outputFile("output.txt");
     if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }
    outputFile << "K'th large element is "
		<< k_largest(a, 0, n - 1, n-k+1)<< endl;

    outputFile.close();

	return 0;
}