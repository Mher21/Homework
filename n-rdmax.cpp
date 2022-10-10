#include <algorithm>
#include <iostream>
using namespace std;
 
// Function to return k'th smallest element in a given array
int kthbiggest(int arr[], int n, int k)
{
    // Sort the given array
    sort(arr, arr + n);
 
    // Return k'th element in the sorted array
    return arr[n-k];
}
 
// Driver program to test above methods
int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout<<"k=";cin>>k;
 

cout << "K'th biggest element is " << kthbiggest(arr, n, k)<<endl;
    return 0;
}
