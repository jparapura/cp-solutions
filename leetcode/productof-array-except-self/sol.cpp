#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int prefix = 1;
    int n = nums.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

void printVector(vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {1,2,3,4};
    auto b = productExceptSelf(a);
    printVector(b);


    a = {9, 0, -2};
    b = productExceptSelf(a);
    printVector(b);
}


