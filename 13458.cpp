#include <iostream>

using namespace std;


int main(){
    int n, b, c;
    cin>>n;
    int arr[n+10];
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cin>>b>>c;
    for (int i = 0; i < n; ++i) {
        int temp = arr[i] - b;
        answer++;
        if(temp > 0) {
            answer += temp/c;
            if(temp % c > 0) answer++;
        }
    }
    cout<<answer<<endl;
}