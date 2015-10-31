#include<stdio.h>
#include<math.h>

#define N 46341

int tab[N];

int ile_dzielnikow(int a){
   int s = 1, pierw = sqrt(a) + 1;
   for(int i = 2;i < pierw;i++){
     if(a % i == 0)s++;
    
   }
   int wynik = s*2;
   pierw = sqrt(a);
   if(pierw*pierw == a)wynik--;
   return wynik;
}

int main (){
    tab[1] = 1;
    for(int i = 2;i < N;i++){
      tab[i] = ile_dzielnikow(i);
    }
    int a;
    scanf("%d", &a);
    for(int i = 1;i < N-1;i++){
      int x, w;
      if(i % 2 == 0){
	x = tab[i/2] * tab[i+1];
	w =(i/2)*(i+1);
      }

      else{
	x = tab[i] * tab[(i+1)/2];
	w = i*((i+1)/2);
      }
      if(x >= a){
	printf("%d %u %d\n", i, w, x);
	return 0;
      }
    }
    printf("BRAK\n");
    
}