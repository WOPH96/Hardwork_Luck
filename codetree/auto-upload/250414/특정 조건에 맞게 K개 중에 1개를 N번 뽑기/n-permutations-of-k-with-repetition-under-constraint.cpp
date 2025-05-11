#include <iostream>
#include <vector>
using namespace std;

int k, n;

vector<int> comb;

void backtrack(int depth, int count)
{
    // 가지치기
    if(count >=2 ) return;

    if(depth == n)
    {
        for(int &elem : comb)
        {
            cout << elem << " "; 
        }
        // cout << count;
        cout << endl;
        return;
    }

    

    for(int i=1;i<=k;i++)
    {
        if(!comb.empty() && comb.back() == i)
        {
            comb.push_back(i);
            backtrack(depth+1,count+1);
        }
        else
        {
            comb.push_back(i);
            backtrack(depth+1,0);
        }
        comb.pop_back();
        
    }
    
}

int main() {
    cin >> k >> n;
    // comb.resize(n);
    // Please write your code here.

    backtrack(0,0);

    return 0;
}
