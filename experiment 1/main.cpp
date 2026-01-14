#include <bits/stdc++.h>
using namespace std;

int operations = 0;
int maxdepth = 0;

void complexRec(int n, int depth) {
    maxdepth = max(maxdepth, depth);

    if (n <= 2) {
        return;
    }

    int p = n;
    while (p > 0) {
        operations++;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            operations++;
            temp[i] = i ^ p;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        operations++;
        small[i] = i * i;
    }

    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
        operations += n;
    } else {
        reverse(small.begin(), small.end());
        operations += n;
    }

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    complexRec(16, 1);
    cout << operations << endl;
    cout  << maxdepth << endl;
    return 0;
}

//Jaipreet 24BCS10480
//output for input 16 - operations = 480, depth = 4