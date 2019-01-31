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
  vector<pair<ll, ll>> dish(n);
  for(int i = 0; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    dish[i] = {a, b};
  }
  vector<pair<ll, int>> dish_sum(n);
  for(int i = 0; i < n; i++)
  {
    dish_sum[i] = {dish[i].first + dish[i].second, i};
  }
  sort(dish_sum.begin(), dish_sum.end());
  reverse(dish_sum.begin(), dish_sum.end());
  ll takashi = 0;
  ll aoki = 0;
  for(int i = 0; i < n; i++)
  {
    if(i % 2 == 0)
    {
      takashi += dish[dish_sum[i].second].first;
    }else{
      aoki += dish[dish_sum[i].second].second;
    }
  }
  cout << takashi - aoki << endl;
}
