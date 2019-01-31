#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
 
using namespace std;
using ll = long long int;
 
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n, vector<int>());
  for(int i = 0; i < n + m - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
  }
  vector<int> ind(n, 0);
  vector<int> parent(n , -1);
  vector<int> longest(n, 0);
  vector<bool> flag(n, false);
  //入次数のカウント
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < graph[i].size(); j++)
    {
      ind[graph[i][j]]++;
    }
  }
  //根の見つける
  int root = 0;
  for(int i = 0; i < n; i++)
  {
    if(ind[i] == 0)
    {
      root = i;
      break;
    }
  }
  //各頂点について根からの最長経路を見つける
  //rootを取り除きながら各頂点の親を更新していく
  queue<int> s;
  s.push(root);
  while(!s.empty())
  {
    int target = s.front();
    s.pop();
    for(int i = 0; i < graph[target].size(); i++)
    {
      int next = graph[target][i];
      ind[next]--;
      if(ind[next] == 0)
      {
        //親の更新
        parent[next] = target;
        s.push(next);
      }
    }
  }
  for(auto e : parent)
  {
    cout << e + 1 << endl;
  }
}
