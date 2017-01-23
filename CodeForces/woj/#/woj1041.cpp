#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40
char maze[SIZE][SIZE];
int state[SIZE][SIZE];
typedef struct{
  int x, y, life;
}node ;
int size, sx, sy;

int inside(node a){
  return (a.x >= 0 && a.x < size && a.y >= 0 && a.y < size);
}

void input1(){
  int i, j;
  scanf("%d", &size);
  for(i = 0; i < size; i++){
    scanf("%s", maze[i]);
    for(j = 0; j < size; j++){
      state[i][j] = 0;
      if(maze[i][j] == 'p'){
        sx = i, sy = j;
      }
    }
  }
}

int bfs1(node cur);

int go1(node cur, int dx, int dy){
  node next = cur;
  char t;
  next.x += dx;
  next.y += dy;
  if(!inside(next) || state[next.x][next.y] >= cur.life)return 0;
  t = maze[next.x][next.y];
  if(t == 'd') {
    next.life--;
  }else if(t == 'k'){
    next.life = 0;
  }
  return bfs1(next);
}

int bfs1(node cur){
  if(cur.life <= 0)return 0;
  if(maze[cur.x][cur.y] == 'a')return 1;
  state[cur.x][cur.y] = cur.life;
  if(go1(cur, -1, 0))return 1;
  if(go1(cur, 0, -1))return 1;
  if(go1(cur, 1, 0))return 1;
  if(go1(cur, 0, 1))return 1;
  return 0;
}

int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    input1();
    node start = {sx, sy, 2};
    if(bfs1(start)){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }
  return 0;  
}