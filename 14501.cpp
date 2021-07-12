#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> arr[15];
int answer = 0;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int days, cost;
        cin>>days>>cost;
        arr[i] = {days, cost};
    }
    for (int i = n-1; i >= 0 ; --i) {
        if(i + arr[i].first > n) arr[i].second = arr[i+1].second;
        else {
            arr[i].second = max(arr[i+1].second, arr[i].second + arr[i+arr[i].first].second);
            answer = max(answer, arr[i].second);
        }
    }
    cout<<answer<<endl;
}