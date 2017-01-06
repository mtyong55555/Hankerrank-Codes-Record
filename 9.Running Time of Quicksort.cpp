#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int swap_quick = 0;

int intersection(vector<int> &arr,int n){
    int i,j;
    int count = 0;
    int value;
    for(i = 1; i < n; i++){
        value = arr[i];
        j = i - 1;
        while(j >= 0 && value < arr[j]){
            arr[j + 1] = arr[j];
            count++;
            j--;
        }
        arr[j + 1] = value;
    }
    return count;
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
            swap_quick++;
        }
    }
    int temp = arr[ind];
    arr[ind] = arr[end];
    arr[end] = temp;
    swap_quick++;
    quick_in_place(arr,start,ind - 1);
    quick_in_place(arr,ind + 1,end);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr_quick(n),arr_insert(n);
    for(int i = 0; i < n; i++){
        cin >> arr_quick[i];
        arr_insert[i] = arr_quick[i];
    }
    
    int swap_insert = 0;
    
    swap_insert = intersection(arr_insert,n);
    quick_in_place(arr_quick,0,n-1);
    
    cout << swap_insert - swap_quick << endl;
    
    return 0;
}

