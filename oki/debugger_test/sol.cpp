#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

vector<int> v;
stack<Point> pts;
int x = 3;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N = 2137;
    string s = "aaa";

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    Point p1(1, 2);
    Point p2(3, 4);
    Point p3(5, 6);
    pts.push(p1);
    pts.push(p2);
    pts.push(p3);
}
