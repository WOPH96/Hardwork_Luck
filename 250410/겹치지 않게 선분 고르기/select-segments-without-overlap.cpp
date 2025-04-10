#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x1[15], x2[15];

struct Line
{
    int x1,x2;
    int length;
    bool operator <(Line &L)
    {
        if(this->length == L.length )
            return this->x1 < L.x1;
        return this->length < L.length;
    }
};

vector<Line> lines;

int main() {
    cin >> n;
    lines.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i].x1 >> lines[i].x2;
        lines[i].length = lines[i].x2 - lines[i].x1;
    }

    // Please write your code here.
    sort(lines.begin(),lines.end());

    int end_point = 0 ;
    int cnt = 0;
    for(auto &elem : lines)
    {
        // cout << elem.x1 << elem.x2 << " ";
        if (end_point<elem.x1)
        {
            cnt ++;
            end_point = elem.x2;
        }
    }
    cout << cnt;
    cout << endl;
    return 0;
}
