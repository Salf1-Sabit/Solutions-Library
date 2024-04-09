/* One of the cleanest solution of the problem LOJ-1089
 * Problem link: https://lightoj.com/problem/points-in-segments-ii */

#include <bits/stdc++.h>
using namespace std;

int main () { 
  int tt;
  cin >> tt;
  for (int caseNo = 1; caseNo <= tt; ++caseNo) { 
    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> points;
    for (int i = 0; i < n; ++i) { 
      int l, r;
      cin >> l >> r;
      points.push_back({l, 0, -1}); // Mark the starting point with 0
      points.push_back({r, 2, -1}); // Mark the ending point with 2
    }
    for (int i = 0; i < q; ++i) { 
      int point;
      cin >> point;
      /* Mark the queryPoints with 1.
       * So, that if there are multiple starting and ending 
       *     points for only just one point then, the queryPoints must be in the center.
       * Which helps us counting the whole answer in a "Regular bracket sequence" fashion. */
      points.push_back({point, 1, i}); 
    }
    sort(points.begin(), points.end());
    int curCnt = 0;
    vector<int> queryAns(q);
    for (auto [x, y, qId] : points) { 
      curCnt += (y == 0);
      curCnt -= (y == 2);
      if (y == 1) { 
        queryAns[qId] = curCnt;
      }
    }
    cout << "Case " << caseNo << ":\n";
    for (auto x : queryAns) { 
      cout << x << "\n";
    }
  }
  return 0;
}
