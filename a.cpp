#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  int n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    vector<int> memo(26, 0);
    memo[a[i] - 'a']++;
    memo[b[i] - 'a']++;
    memo[c[i] - 'a']++;
    sort(memo.begin(), memo.end());
    reverse(memo.begin(), memo.end());
    count += 3 - memo.front();
  }
  cout << count << endl;
}
