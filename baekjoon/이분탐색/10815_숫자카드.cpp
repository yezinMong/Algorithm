/*
[문제]
상근이는 숫자 카드 N개를 가지고 있다.
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지 구하라.

[출력]
주어진 M개의 수에 대해, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1,
아니면 0을 출력한다.
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> v;
vector<int> num;

bool binary_search(int n, int key) {
    int start = 0;
    int end = n - 1;

    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (v[mid] == key) return true;
        else if (v[mid] < key) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

int main() {
    scanf("%d", &N);
    int n;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        v.push_back(n);
    }
    
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &n);
        num.push_back(n);
    }

    sort(v.begin(), v.end()); // 이분탐색을 할 경우 정렬이 되어있어야 한다.
    for (int n : num) {
        bool check = binary_search(N, n);
        if (check) printf("1 ");
        else printf("0 ");
    }
    return 0;
}
