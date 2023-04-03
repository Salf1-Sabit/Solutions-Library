/* Problem name: Investigation 
 * Problem link: https://lightoj.com/problem/investigation */
#include <bits/stdc++.h> 
using namespace std;

int a, b, k;
int dp[10][82][2][82];

int sol (string org_seq, int pos = 0, int dig_sum = 0, bool allowed_any_digit = false, int kmod = 0) { 
  if (pos == (int) org_seq.size()) { 
    return !kmod and !(dig_sum % k) ? 1 : 0;
  }
  int& cur_state_ans = dp[pos][dig_sum][allowed_any_digit][kmod];
  if (cur_state_ans != -1) { 
    return cur_state_ans;
  }
  cur_state_ans = 0;
  for (short tmp_dig = 0; tmp_dig <= 9; ++tmp_dig) { 
    if (!allowed_any_digit and org_seq[pos] - '0' < tmp_dig) { 
      break;
    }
    bool allowed_any_digit2 = !allowed_any_digit ? (tmp_dig < org_seq[pos] - '0' ? true : false) : true;
    cur_state_ans += sol(org_seq, pos + 1, dig_sum + tmp_dig, allowed_any_digit2, (kmod * 10 + tmp_dig) % k);
  }
  return cur_state_ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int cs = 1; cs <= tt; ++cs) { 
    cin >> a >> b >> k;
    int ans = 0;
    if (k <= 81) { 
      memset(dp, -1, sizeof dp);
      int full_ans = sol(to_string(b));
      memset(dp, -1, sizeof dp);
      int part_ans = sol(to_string(a - 1));
      ans = full_ans - part_ans;
    }
    cout << "Case " << cs << ": " << ans << '\n';
  }
  return 0;
}
