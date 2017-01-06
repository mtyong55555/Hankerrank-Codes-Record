#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_arr(vector<int> & arr, int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void quick_in_place(vector<int>& arr,int start,int end){
    if(start >= end){
        return;
    }
    int pivot = arr[end];
    int ind = start;
    for(int i = start; i < end; i++){
        if(arr[i] <= pivot){
            int temp = arr[ind];
            arr[ind] = arr[i];
            arr[i] = temp;
            ind++;
        }
    }
    int temp = arr[ind];
    arr[ind] = arr[end];
    arr[end] = temp;
    print_arr(arr,arr.size());
    quick_in_place(arr,start,ind - 1);
    quick_in_place(arr,ind + 1,end);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    quick_in_place(arr,0,n-1);
    
    return 0;
}

