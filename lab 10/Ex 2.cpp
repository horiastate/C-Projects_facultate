#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 5;
const int MAX_W = 15;

int w[MAX_N] = {12, 2, 1, 1, 4};
int v[MAX_N] = {4, 2, 2, 1, 10};

int memo[MAX_N + 1][MAX_W + 1];

int knapsack(int n, int W) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (memo[n][W] != -1) {
        return memo[n][W];
    }
    if (w[n - 1] > W) {
        return memo[n][W] = knapsack(n - 1, W);
    } else {
        return memo[n][W] = max(knapsack(n - 1, W), v[n - 1] + knapsack(n - 1, W - w[n - 1]));
    }
}

int main() {
    memset(memo, -1, sizeof(memo));
    cout << "Valoarea maxima care poate fi obtinuta este: " << knapsack(MAX_N, MAX_W) << endl;
    return 0;
}

