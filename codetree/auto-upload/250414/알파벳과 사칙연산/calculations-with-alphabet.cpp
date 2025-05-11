#include <iostream>
#include <vector>
using namespace std;

string fomula;
vector<int> datas(6,0);
int max_value = -1*0x7fff0000;

int calculate()
{
    int sum = 0;
    char oper = 0;
    for(auto &elem : fomula)
    {
        if(elem >= 'a' && elem <='f')
        {
            if (oper==0)
            {
                sum += datas[elem-'a'];
            }
            else
            {
                if(oper == '+')
                    sum += datas[elem-'a'];
                else if(oper == '*')
                    sum *= datas[elem-'a'];
                else if(oper == '-')
                    sum -= datas[elem-'a'];
            }
        }
        else
        {
            oper = elem; 
        }

    }
    return sum;
}

void backtrack(int idx)
{
    if(idx==6)
    {
        max_value = max(max_value,calculate());
        return;
    }

    for(int i=4; i>=1; i--)
    {
        datas[idx] = i;
        backtrack(idx+1);

    }
}

int main() {
    cin >> fomula;

    // Please write your code here.
    
    

    backtrack(0);
    cout << max_value;
    return 0;
}
