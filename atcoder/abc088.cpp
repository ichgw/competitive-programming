#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_H 50
#define MAX_W 50
const int INF = 10000000;
typedef pair<int, int> P;
int sp();
void init();

char maze[MAX_H][MAX_W+1];
int d[MAX_H][MAX_W];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
int h, w;
int w_cnt=0;

int main(){
  init();
  int n=sp();
  if (n!=-1) {
    printf("%d\n", w_cnt-(n+1));
  }else{
    printf("-1\n");
  }
  // test();
  return 0;
}

void init(){
  cin >> h >> w;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      cin >> maze[y][x];
      if(maze[y][x]=='.') w_cnt++;
      d[y][x]=INF;
    }
  }
}

int sp(){
  queue<P> que;
  que.push(P(0, 0));
  d[0][0]=0;
  while(que.size()){
    P p = que.front(); que.pop();
    if(p.first==w-1&&p.second==h-1){
      return d[p.second][p.first];
    }else{
      for (int i = 0; i < 4; i++) {
        int nx = p.first  + dx[i];
        int ny = p.second + dy[i];
        if (0 <= nx && nx < w && 0 <= ny && ny < h && maze[ny][nx] != '#' && d[ny][nx] == INF) {
          que.push(P(nx, ny));
          d[ny][nx]=d[p.second][p.first]+1;
        }
      }
    }
  }
  return -1;
}
