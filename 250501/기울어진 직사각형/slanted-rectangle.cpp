#include <iostream>

using namespace std;

int n;
int grid[20][20];

int max_sum = -1;

int dy[] = {-1,-1,1,1}; 
int dx[] = {1,-1,-1,1};

void make_ractangle(int sy,int sx)
{
    
    
    int ny=-1, nx=-1;
    auto is_valid = [&]{return (0<=ny && ny<n && 0<=nx && nx<n);};
    for(int l1 = 1; l1< n; l1++) // 변의 길이1
    {
        for(int l2 = 1; l2<n; l2++) // 변의 길이2 
        {  
            int y= sy, x = sx;
            int sum = 0;
            bool flag = false;
            //첫번째 이동 l1 만큼
            for(int d = 0; d<l1; d++)
            {
                ny = y+dy[0], nx = x+dx[0];
                if(is_valid())
                {
                    y=ny,x=nx;
                    sum+=grid[ny][nx];
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if(flag) continue; // 다른 변으로 테스트 
            
            //두번째 이동 l2 만큼
            for(int d = 0; d<l2; d++)
            {
                ny = y+dy[1], nx = x+dx[1];
                if(is_valid())
                {
                    y=ny,x=nx;
                    sum+=grid[ny][nx];
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if(flag) continue; // 다른 변으로 테스트 

            //세번째 이동 l1 만큼
            for(int d = 0; d<l1; d++)
            {
                ny = y+dy[2], nx = x+dx[2];
                if(is_valid())
                {
                    y=ny,x=nx;
                    sum+=grid[ny][nx];
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if(flag) continue; // 다른 변으로 테스트 

            //네번째 이동 l2 만큼
            for(int d = 0; d<l2; d++)
            {
                ny = y+dy[3], nx = x+dx[3];
                if(is_valid())
                {
                    y=ny,x=nx;
                    sum+=grid[ny][nx];
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if(flag) continue; // 다른 변으로 테스트

            max_sum = max(max_sum,sum);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) // 시작점
        {
            make_ractangle(i,j);
        }
    }

    cout << max_sum ;
    return 0;
}
