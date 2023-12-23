// Problem link: https://codeforces.com/problemset/problem/1883/D

#include <bits/stdc++.h>
using namespace std;

int main () { 
  int q;
  cin >> q;
  multiset<int> l, r;
  while (q--) { 
    char c;
    int nl, nr;
    cin >> c >> nl >> nr;
    if (c == '+') { 
      l.insert(nl);
      r.insert(nr);
    } else { 
      l.erase(l.find(nl));
      r.erase(r.find(nr));
    }
    if (!l.empty()) { 
      int max_l = *l.rbegin();
      int min_r = *r.begin();
      cout << (min_r < max_l ? "YES" : "NO") << '\n';
    } else { 
      cout << "NO\n";
    }
  }
  return 0;
}
