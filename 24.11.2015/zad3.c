#include <stdio.h>
#include <stdlib.h>
#define INF 1<<31

#ifdef DEBUG
    #define printd printf
#else
    #define printd if (0)printf
#endif

#define EMPTY 0
#define WALL 1
#define TREASURE 2

#define INF 1<<31

#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )
#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )

int tab[30][30];

typedef struct node{
  int length;
  int turns;
  int type;
}node;

int set_node(int l, int t, int x, int y){
  tab[x][y].length = l;
  tab[x][y].turns = t;
  return tab[x][y];
}




int find_border(int x, int y, int l, int f){
  if(tab[x][y] == WALL)return INF;
  if(tab[x][y].length > l){

  }
}



int main(){

}
