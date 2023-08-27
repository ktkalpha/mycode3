#include <stdio.h>

int graph_gen(int a, int b, int g[12][12]);
int dfs(int start, int end, int g[12][12]);

int stack[12] = {};
int visited[12] = {};
int topIdx;

int main() {
  int graph[12][12] = {};
  graph_gen(0, 1, graph);
  graph_gen(0, 2, graph);
  graph_gen(0, 3, graph);
  graph_gen(1, 4, graph);
  graph_gen(1, 5, graph);
  graph_gen(2, 7, graph);
  graph_gen(3, 8, graph);
  graph_gen(3, 9, graph);
  graph_gen(4, 10, graph);
  graph_gen(7, 6, graph);
  graph_gen(9, 11, graph);
  topIdx = -1;
  dfs(0, 6, graph);
}
int graph_gen(int a, int b, int g[12][12]) {
  g[a][b] = 1;
  g[b][a] = 1;
  return 0;
}
int dfs(int start, int end, int g[12][12]) {
  int i;
  printf("%d->", start);
  visited[start] = 1;
  topIdx--;
  for (i = 11; i >= 0; i--) {
    if (g[start][i] == 1 && !visited[i]) {
      stack[topIdx + 1] = i;
      topIdx++;
      //   printf("%d , %d : %d\n", start, i, stack[topIdx]);
    }
  }
  if (topIdx < -1) {
    return 0;
  }
  dfs(stack[topIdx], end, g);
}