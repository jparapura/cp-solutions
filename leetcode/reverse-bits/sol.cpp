#include <bits/stdc++.h>
#include <bitset>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    for (int i = 0; i < 16; i++) {
        int left = n & (1 << (31 - i));
        int right = n & (1 << i);
        if (left != 0 && right == 0) {
            n -= left;
            n += 1 << i;
        }
        else if (left == 0 && right != 0) {
            n -= right;
            n += 1 << (31 - i);
        }
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    uint32_t n;
    cin >> n;
    uint32_t r = reverseBits(n);
    bitset<32> x(r);
    cout << x << endl;
}
