#include <iostream>
#include <string>
#include <vector>
using namespace std;

string A;

int min_length = 0x7fff0000;

void encoding(string &s)
{
    int n = s.size();
    string encoded = "";
    char temp = '9'; // init
    int cnt = 0;
    for(char &elem : s)
    {
        if(elem != temp)
        {
            if(temp != '9')
            {
                if(cnt == 10){
                    encoded+='1';
                    encoded+='0';
                }
                else
                    encoded+=cnt+'0';
            }
            cnt = 0;
            temp = elem;
            encoded+=elem;
            cnt++;
        }
        else
        {
            cnt++;
        }
    }
    if(cnt == 10){
        encoded+='1';
        encoded+='0';
    }
    else
        encoded+=cnt+'0';
    min_length = min(min_length,(int)encoded.size());
}

void shift(string &s)
{
    int n = s.size();
    char temp = s[n-1];
    for(int i =n-1; i>0;i--)
    {
        s[i] = s[i-1];
    }
    s[0] = temp;
}

int main() {
    cin >> A;

    // Please write your code here.
    
    int size = A.size();
    for(int i=1;i<A.size();i++)
    {
        shift(A);
        encoding(A);
        // cout << A << endl;
    }
    cout << min_length;
    return 0;
}
