#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n ; 
    cin >> n;

    vector<int> arr = {3};
    //bottom-up 방식
    for(int i = 1  ; i <= n ; ++i)
        arr.push_back(arr[i-1]*2 -4);

    cout << arr[n] << endl;
    return 0;
}