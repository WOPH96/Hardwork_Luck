#include <stdio.h>
int N, ans;
int ori[22][22]; // 입력 맵
int map[22][22]; // 이동 맵
int vis[22][22]; // 이미 합쳐진 블록
int res[6]; // 어디로 이동 할 것인 가?
void input(); // 입력
void back(int c); // 5번 이동
void move(int n); // 상하좌우 이동
void solve(); 
int main() {
    input();
    back(1);
    printf("%d", ans);
}
void input() { // 입력
    scanf("%d", &N);
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)scanf("%d",&ori[i][j]);
}
void back(int c) {
    if (c > 5) { // 5번 이동
        for(int i=1;i<=N;i++)for(int j=1;j<=N;j++) map[i][j]=ori[i][j]; //초기화
        for (int t = 1; t <= 5; t++) { // 5번 이동
            for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)vis[i][j]=0; // 이미 방문한 곳을 매 번 초기화
            move(res[t]); // 이동
        }
        int t = 0;
        for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)t=(t<map[i][j]? map[i][j]:t); // map안의 최대 값
        ans = (ans > t ? ans : t); // 전체 최대 값
    }
    else {
        for (int i = 1; i <= 4; i++) {
            res[c] = i;
            back(c + 1);
        }
    }
}
void move(int n) {
    if (n == 1) { // 하
        for (int i = N - 1; i >= 1; i--) {
            for (int j = N; j >= 1; j--) {
                if (map[i][j]) { // 숫자가 있으면
                    for (int t = 1; ; t++) {
                        if (i + t > N) break; // 범위 제한
                        if (i + t == N && !map[i + t][j]) { // 끝에 도착 했을 때, 비어있다면 
                            map[N][j] = map[i][j]; // 끝 점에 이동 
                            map[i][j] = 0; // 이동 하였다면 기존 위치에 0
                            break;
                        }
                        if (map[i + t][j] == 0) continue; // map이 비어있다면 다음 값을 본다
                        else if (map[i + t][j] != map[i][j]) { // 이동 하려는 곳에 답이 있는데, 답이 다르다면
                            if (t != 1) { // 굳이 t != 1을 한 이유는, t == 1일때 map[i][j] = 0을 하면 이동한 값이 0이 된다.
                                map[i + t - 1][j] = map[i][j];
                                map[i][j] = 0;
                            }
                            break;
                        }
                        else {
                            if (!vis[i + t][j]) { // 방문하지 않은 곳
                                map[i + t][j] += map[i][j]; // 값 2배 map[i + t][j] = 2 * map[i][j];
                                vis[i + t][j] = 1; // 방문한 곳
                                map[i][j] = 0; // 기존 값
                            }
                            else { // 이미 방문한 곳
                                if (t != 1) { // 위와 마찬가지의 이유
                                    map[i + t - 1][j] = map[i][j];
                                    map[i][j] = 0;
                                }
                            }
                            break; // 탈출
                        }
                    }
                }
            }
        }
    }
    else if (n == 2){ // 상, 이후 같음
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j]) {
                    for (int t = 1; ; t++) {
                        if (i - t < 1) break;
                        if (i - t == 1 && !map[i - t][j]) { 
                            map[i - t][j] = map[i][j];
                            map[i][j] = 0;
                            break;
                        }
                        if (map[i - t][j] == 0) continue;
                        else if (map[i - t][j] != map[i][j]) {
                            if (t != 1) {
                                map[i - t + 1][j] = map[i][j];
                                map[i][j] = 0;
                            }
                            break;
                        }
                        else {
                            if (!vis[i - t][j]) {
                                map[i - t][j] += map[i][j];
                                vis[i - t][j] = 1;
                                map[i][j] = 0;
                            }
                            else {
                                if (t != 1) {
                                    map[i - t + 1][j] = map[i][j];
                                    map[i][j] = 0;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (n == 3) { // 좌
        for (int j = 2; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                if (map[i][j]) {
                    for (int t = 1; ; t++) {
                        if (j - t < 1) break;
                        if (j - t == 1 && !map[i][j - t]) { 
                            map[i][j - t] = map[i][j];
                            map[i][j] = 0;
                            break;
                        }
                        if (map[i][j - t] == 0) continue;
                        else if (map[i][j - t] != map[i][j]) {
                            if (t != 1) {
                                map[i][j - t + 1] = map[i][j];
                                map[i][j] = 0;
                            }
                            break;
                        }
                        else {
                            if (!vis[i][j - t]) {
                                map[i][j - t] += map[i][j];
                                vis[i][j - t] = 1;
                                map[i][j] = 0;
                            }
                            else {
                                if (t != 1) {
                                    map[i][j - t + 1] = map[i][j];
                                    map[i][j] = 0;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    else { // 우
        for (int j = N - 1; j >= 1; j--) {
            for (int i = 1; i <= N; i++) {
                if (map[i][j]) {
                    for (int t = 1; ; t++) {
                        if (j + t > N) break;
                        if (j + t == N && !map[i][j + t]) { 
                            map[i][j + t] = map[i][j];
                            map[i][j] = 0;
                            break;
                        }
                        if (map[i][j + t] == 0) continue;
                        else if (map[i][j + t] != map[i][j]) {
                            if (t != 1) {
                                map[i][j + t - 1] = map[i][j];
                                map[i][j] = 0;
                            }
                            break;
                        }
                        else {
                            if (!vis[i][j + t]) {
                                map[i][j + t] += map[i][j];
                                vis[i][j + t] = 1;
                                map[i][j] = 0;
                            }
                            else {
                                if (t != 1) {
                                    map[i][j + t - 1] = map[i][j];
                                    map[i][j] = 0;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
