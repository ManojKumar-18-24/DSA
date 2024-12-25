#include<bits/stdc++.h>
using namespace std;

string* comb(int n,string a[],int size)
{

}

int main()
{
 int n;cin>>n;
return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

void print_factor_sum(int n, vector<int>& factors) {
    if (n == 1) {
        for (int i = 0; i < factors.size(); i++) {
            cout << factors[i];
            if (i != factors.size()-1) {
                cout << " + ";
            }
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                print_factor_sum(n/i, factors);
                factors.pop_back();
            }
        }
    }
}

int main() {
    int n = 4;
    vector<int> factors;
    print_factor_sum(n, factors);

    n = 6;
    factors.clear();
    print_factor_sum(n, factors);

    n = 8;
    factors.clear();
    print_factor_sum(n, factors);

    return 0;
}
*/