#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void quickSort(vector <int> &arr) {
    if(arr.size() <= 1)
       return;
    vector<int> front,back;
    int n = arr.size();
    int pivot = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[0])
            front.push_back(arr[i]);
        else
            back.push_back(arr[i]);
    }
    quickSort(front);
    quickSort(back);
    arr.clear();
    arr.insert(arr.end(),front.begin(),front.end());
    arr.push_back(pivot);
    arr.insert(arr.end(),back.begin(),back.end());
    printArr(arr);
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
