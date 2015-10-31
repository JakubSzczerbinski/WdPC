#include <stdio.h>
#include <math.h>
#define N 65600

char sito_tab[N];
int pierwsze[10000];
int przedzial = 1, potega_przedzialu = 0;
int lewa_strona;

int power(int a, int b){
  int x = 1;
  for(int i = 0;i < b;i++){
    x *= a;
  }
  return x;
}

int lewa_strona_do_palindrom(int x){
  int palindrom = x;
  x /= 10;
  while(x != 0){
    palindrom *= 10;
    palindrom += x%10;
    x /= 10;
  }
  return palindrom;
}

int init_palindrom(int k){
  while(k >= przedzial*10){
    przedzial *= 100;
    potega_przedzialu += 2;
  }
  if(k < przedzial){
    k = przedzial;
  }
  lewa_strona = k/power(10, potega_przedzialu/2);
  int wynik = lewa_strona_do_palindrom(lewa_strona);
  if(wynik > k)return wynik;
  return lewa_strona_do_palindrom(++lewa_strona);
}

int next_palindrom(){
  return lewa_strona_do_palindrom(++lewa_strona);
}

void sito(){		//Sito erastotenesa 
    for(int i = 2;i < N;i++){
      if(sito_tab[i] == 1)continue;
      for(int j = 2*i;j < N;j += i){
	sito_tab[j] = 1;
      }
    }
    int j = 0;
    for(int i = 2;i < N;i++){
      if(sito_tab[i] == 0){
	pierwsze[j] = i;
	j++;
      }
    }
}

int jest_pierwsza(int a){
  int pierw = sqrt(a)+1;
  for(int i = 0;pierwsze[i] < pierw;i++){
    if(a % pierwsze[i] == 0)return 0;
  }
  return 1;
}


int main(){
  sito();
  int k;
  scanf("%d", &k);
  init_palindrom(k);
  for(int i = init_palindrom(k);i < 1<<30;i = next_palindrom()){
    if(jest_pierwsza(i)){
      printf("%d \n", i);
      return 0;
    }
  }
      
      
  printf("NIE MA TAKIEJ LICZBY W PRZEDZIALE DO 10 MLD");
  return 0;
}