#include <iostream>

using namespace std;

int n, m;
int grid[5][5];
int max_area = -9999;

struct Pos
{
    int y,x;   
};

struct Ractangle
{
    Pos s,e;
};

bool check_overlap(const Ractangle &r1, const Ractangle &r2)
{
    return (r2.s.x <= r1.e.x && r2.s.y <= r1.e.y);
}

int get_area_sum (const Ractangle &r)
{   
    int sum = 0;
    for(int i =r.s.y; i<=r.e.y; i++)
    {
        for(int j =r.s.x; j<=r.e.x;j++)
        {
            sum +=grid[i][j];
        }
    }
    return sum;
}


void make_other_ractangle(const Ractangle &r1)
{
    int area1 = get_area_sum(r1);
    // cout << area1 <<endl;
    for(int s_y = 0; s_y<n; s_y++)
    {
        for(int s_x = 0; s_x<m;s_x++) // 두번째 네모 좌상단 모서리 좌표
        {
            for(int e_y = s_y; e_y <n; e_y++)
            {
                for(int e_x = s_x; e_x <m; e_x++) 
                {// 두번째 네모 우하단 모서리 좌표, s보다 같거나 커야함
                    //(0,0) ~ (n-1,m-1) 결정 가능 

                    Ractangle r2 = {{s_y,s_x},{e_y,e_x}};
                    if(check_overlap(r1,r2)) continue; // 겹치면 패스 
                    
                    int area2 = get_area_sum(r2);
                    int sum_area = area1+area2;
                    max_area = max(max_area,sum_area);
                }
            }
        }
    }
}



int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.



    for(int s_y = 0; s_y<n; s_y++)
    {
        for(int s_x = 0; s_x<m;s_x++) // 첫번째 네모 좌상단 모서리 좌표
        {
            for(int e_y = s_y; e_y <n; e_y++)
            {
                for(int e_x = s_x; e_x <m; e_x++) 
                {// 첫번째 네모 우하단 모서리 좌표, s보다 같거나 커야함
                    //(0,0) ~ (n-1,m-1) 결정 가능 

                    Ractangle r1 = {{s_y,s_x},{e_y,e_x}};
                    
                    make_other_ractangle(r1);
                }
            }
        }
    }

    cout << max_area;

    return 0;
}
