#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../template/template.cpp"
#include "../../graph/graph-template.cpp"

#include "../../graph/tree/tree-diameter.cpp"

int main() {
  int N;
  cin >> N;
  TreeDiameter< int > g(N);
  g.read(N - 1, 0, true);
  cout << g.build() << endl;
}
