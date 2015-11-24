#include<stdio.h>
#include<stdlib.h>

struct p{
  double x;
  double y;
};

struct maxmin{
    int first;
    int second;
    double rekord;
};

typedef struct p punkt;

int compare(const void* a1, const void* a2){
  const punkt* p1 = (const punkt*)a1;
  const punkt* p2 = (const punkt*)a2;
  return (p1->x*p1->x) + (p1->y*p1->y) > (p2->x*p2->x) + (p2->y*p2->y);
}

double odl(punkt a, punkt b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main(){
  int liczba;
  scanf("%d", &liczba);
  punkt *tab = (punkt*)malloc(sizeof(punkt)*liczba);
  for(int i = 0;i < liczba;i++){
    double a, b;
    scanf("%lf %lf", &a, &b);
    tab[i].x = a;
    tab[i].y = b;
  }
  qsort(tab, liczba, sizeof(punkt), compare);
  for(int i = 0;i < liczba;i++){
    printf("(%lf,%lf) \t", tab[i].x, tab[i].y);
    if(i%3 == 2){
        printf("\n");
    }
  }
    struct maxmin mini, maxi;
    mini.rekord = 10000000000;
    maxi.rekord = 0;
    for(int i = 0;i < liczba;i++){
        for(int j = i+1;j < liczba;j++){
            double x = odl(tab[i], tab[j]);
            if(maxi.rekord < x){
                maxi.rekord = x;
                maxi.first = i;
                maxi.second = j;
            }
             if(mini.rekord > x){
                mini.rekord = x;
                mini.first = i;
                mini.second = j;
            }
        }
    }
  printf("\n Min: (%lf,%lf) i (%lf,%lf)\n Max: (%lf,%lf) i (%lf,%lf)",   tab[mini.first].x,
                                                                        tab[mini.first].y,
                                                                        tab[mini.second].x,
                                                                        tab[mini.second].y,
                                                                        tab[maxi.first].x,
                                                                        tab[maxi.first].y,
                                                                        tab[maxi.second].x,
                                                                        tab[maxi.second].y);
}
