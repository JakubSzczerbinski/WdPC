#include<stdio.h>

#define N 30

int tab[N];

int main (){
  int a;
  scanf("%d\n", &a);
  for(int i = 0;i < a;i++){
    int x;
    x = getchar();
    while(x != '\n'){
      tab[x - 'a']++;
      x = getchar();
    }
    x = getchar();
    while(x != '\n'){
      tab[x - 'a']--;
      x = getchar();
    }
    int answer = 1;
    for(int i = 0;i < N;i++){
      if(tab[i] != 0){
	answer = 0;
	break;
      }
    }
    if(answer)printf("TAK\n");
    else printf("NIE\n");
    for(int i = 0;i < N;i++){
      tab[i] = 0;
    }
  }
} 
