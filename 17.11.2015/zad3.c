#include<stdio.h>

  int tab[1000][1000];

int check(int w1, int k1, int w2, int k2){
  int result = 0;
  for(int i = w1;i < w2;i++){
    for(int j = k1;j < k2;j++){
      result += tab[i][j] == 0;
    }
  }
}

void rotate90(int* x1, int* x2, int* y1, int* y2){
  int a1 = *y2;
  int a2 = *y1;
  int b1 = *x1;
  int b2 = *x2;
  *x1 = a1;
  *x2 = a2;
  *y1 = b1;
  *y2 = b2;
}

int main(){
  int a, x;
  scanf("%d", &a);
  for(int i = 0;i < a;i++){
    for(int j = 0;j < a/32;j++){
      scanf("%d", &x);
      for(int k = 0;k < 32;k++){
        tab[i][j*32+k] = x&(1<<(32-k));
      }
    }
  }
  int x1, x2, y1, y2;
  scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
  for(int i = 0;i < 5;i++){
    printf("%d %d %d %d \n", x1, y1, x2, y2);
    rotate90(&x1, &x2, &y1, &y2);
  }


}
