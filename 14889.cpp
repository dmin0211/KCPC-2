#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n;
int pairScore[21][21], answer = 20*20*100;
bool visit[22];
int firstIndex = 0;

void func(int start, int count){
    if (count == n/2){
        vector<int> startArr, linkArr;
        int score1 = 0, score2 = 0;
        for (int i = 1; i <= n; ++i) {
            if (visit[i]) startArr.push_back(i);
            else linkArr.push_back(i);
        }
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                if(i==j) continue;
                score1 += pairScore[startArr[i]][startArr[j]];
                score2 += pairScore[linkArr[i]][linkArr[j]];
            }
        }
        int temp = abs(score1 - score2);
        answer = min(answer, temp);
        return;
    }
    for (int i = start; i <= n; ++i) {
        if(!visit[i]) {
            visit[i] = true;
            if(count==0 && i>n/2) return;
            func(start + 1, count + 1);
            visit[i] = false;
        }
    }
}

int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d",&pairScore[i][j]);
        }
    }
    func(1,0);
    printf("%d\n",answer);
}