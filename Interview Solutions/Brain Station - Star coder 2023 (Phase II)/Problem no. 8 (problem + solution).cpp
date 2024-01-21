/* Brain Station 23 (Star coder - Phase II) 2024
 * Solution of Problem no. 8
 * Author: Salfi_Sabit
 * Topic: Dynamic Programming
 */

/* Problem statement (simplified)
   You're given N lines. Each of the i-th line contains 3 integers {xi, di, pi}
   respectively. Now, you've to maximize the profit (in other words, sum of "pi").
   Where, xi = Denotes the required minutes to use the item "i"
               Suppose, if you've only used two item "i" and "j" till now,
               then the the total sum would be (xi + xj)
          di = Denotes that, if you want to choose the item "i" then
               the total sum of "xi" should be less then this "di"
          pi = Denotes the profit you will get if you're able to use 
               this item. 
  Now, you've to maximize the profit (in other words, sum of "pi"). */

/* Contraints (I hardly rememered)
   1 <= T <= 10
   1 <= N <= 100
   1 <= di <= 2000 
   1 <= xi, pi <= 20
 * Sample Input: 
   1
   5
   1 2 3 
   3 1 50
   2 4 20
   1 2 40
   1 6 30
 * Sample Output: 
   100
   3
 */

#include <bits/stdc++.h>
using namespace std;

struct triplet {
  int x, d, p;
};

int n;
const int N = (int) 1e2;
const int M = (int) 2e3 + 1;
vector<triplet> a(N);
vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(M));

pair<int, int> sol (int i, int used_time) { 
  if (i == n) { 
    return pair<int, int>{0, 0}; 
  }
  pair<int, int>& ans = dp[i][used_time];
  if (ans != pair<int, int>{-1, -1}) { 
    return ans;
  }
  pair<int, int> ans1 = sol(i + 1, used_time);
  pair<int, int> ans2 = {0, 0};
  if (used_time < a[i].d) { 
    ans2 = sol(i + 1, a[i].x + used_time);
    ans2.first += a[i].p;
    ans2.second += 1;
  }
  return ans = max(ans1, ans2);
}

int main () { 
  int tt;
  cin >> tt;
  for (int cs = 1; cs <= tt; ++cs) { 
    cin >> n;
    for (int i = 0; i < n; ++i) { 
      cin >> a[i].x >> a[i].d >> a[i].p;
      for (int j = 0; j <= 2000; ++j) { 
        dp[i][j] = {-1, -1};
      }
    }
    sort(a.begin(), a.begin() + n, [&] (triplet A, triplet B) { 
      return A.d < B.d;
    });
    auto ans = sol(0, 0);
    cout << "Case #" << cs << ":\n" << ans.first << "\n" << ans.second << '\n';
  }
  return 0;
}

