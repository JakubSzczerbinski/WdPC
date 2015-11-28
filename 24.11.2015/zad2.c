#include<stdio.h>
#include<stdlib.h>
#include<float.h>



#ifdef DEBUG
    #define printd printf
#else
    #define printd if (0)printf
#endif


typedef struct czynnik{
    double a;
    struct czynnik *next;
}czynnik;

typedef struct wielomian{
    int size;
    czynnik *first;
}wielomian;

czynnik* nowy_czynnik(){
    czynnik* c = malloc(sizeof *c);
    return c;
}

wielomian* init(double* tab, int size){
    wielomian* w = malloc(sizeof *w);
    w->size = size;
    w->first = 0;
    if(size != 0){
        w->first = nowy_czynnik();
        w->first->a = tab[0];
        w->first->next = NULL;
    }
    czynnik* prev = w->first;
    for(int i = 1;i < size;i++){
        czynnik* c = nowy_czynnik();
        c->next = NULL;
        c->a = tab[i];
        prev->next = c;
        prev = c;
    }
    return w;
}

wielomian* dodaj(wielomian* P, wielomian* S){
    int size = (P->size > S->size ? P->size : S->size);
    double *tab = calloc(size, sizeof *tab);
    czynnik *p = P->first, *s = S->first;
    for(int i = 0;i < size;i++){
        int v1 = 0, v2 = 0;
        if(p != NULL){
            v1 = p->a;
            p = p->next;
        }
        if(s != NULL){
            v2 = s->a;
            s = s->next;
        }
        tab[i] = v1+v2;
    }
    wielomian *W = init(tab, size);
    free(tab);
    return W;
}

wielomian* odejmij(wielomian* P, wielomian* S){
    int size = (P->size > S->size ? P->size : S->size);
    double *tab = calloc(size, sizeof *tab);
    czynnik *p = P->first, *s = S->first;
    for(int i = 0;i < size;i++){
        int v1 = 0, v2 = 0;
        if(p != NULL){
            v1 = p->a;
            p = p->next;
        }
        if(s != NULL){
            v2 = s->a;
            s = s->next;
        }
        tab[i] = v1-v2;
    }
    wielomian *W = init(tab, size);
    free(tab);
    return W;
}

wielomian* pomnoz(wielomian* P, wielomian* S){
    int size = P->size + S->size -1;
    double *tab = calloc(size, sizeof *tab);
    int i = 0,  j = 0;
    for(czynnik *p = P->first;p != NULL;p = p->next){
        for(czynnik *s = S->first;s != NULL;s = s->next){
            fflush(stdout);
            tab[i+j] += p->a*s->a;
            j++;
        }
        j = 0;
        i++;
    }
    wielomian *W = init(tab, size);
    free(tab);
    return W;
}

double wartosc(wielomian *P, double x){
    double res = 0;
    for(czynnik *p = P->first;p != NULL;p = p->next){
        res *= x;
        res += p->a;
    }
    return res;
}

void print(wielomian* P){
    for(czynnik *p = P->first;p != NULL;p = p->next){
        printf("%f ", p->a);
    }
    printf("\n");
}

double absolute(double a){
  return (a > 0 ? a : -a);
}

typedef struct przedzial{
  double xp, yp;
  double xk, yk;
}przedzial;

przedzial* nowy_przedzial(wielomian *w, double x1, double x2){
    przedzial* p = malloc(sizeof *p);
    p->xp = x1;
    p->xk = x2;
    p->yp = wartosc(w, x1);
    p->yk = wartosc(w, x2);
    return p;
}

double miejsce_zero(wielomian *w, przedzial* p, double dokl){
  double sr_przedzialu, wartosc_srodka;
  sr_przedzialu = (p->xp+p->xk)/2;
  wartosc_srodka = wartosc(w, sr_przedzialu);
  printd("%f %f %f %f\n", p->xp, p->xk, p->yp, p->yk);
  if(absolute(p->xp - p->xk) < dokl){
    printd("xD \n");
    return (p->xp + p->xk)/2;
  }
  if(wartosc_srodka > DBL_EPSILON){
    if(p->yp > DBL_EPSILON){
      printd("w1 \n");
      p->yp = wartosc_srodka;
      p->xp = sr_przedzialu;
    }
    if(p->yk > DBL_EPSILON){
      printd("w2 \n");
      p->yk = wartosc_srodka;
      p->xk = sr_przedzialu;
    }
    return miejsce_zero(w, p, dokl);
  }
  if(wartosc_srodka < -DBL_EPSILON){
    if(p->yp < -DBL_EPSILON){
      printd("w3 \n");
      p->yp = wartosc_srodka;
      p->xp = sr_przedzialu;
    }
    if(p->yk < -DBL_EPSILON){
      printd("w4 \n");
      p->yk = wartosc_srodka;
      p->xk = sr_przedzialu;
    }
    return miejsce_zero(w, p, dokl);
  }
  if(wartosc_srodka >= -DBL_EPSILON && wartosc_srodka <= DBL_EPSILON){
    printd("XDDDD \n");
    return sr_przedzialu;
  }
  printd("ERROR");
  return 0;
}

int main(){
    double tab[]={1, 0, -500};
    wielomian *W = init(tab, 3);
    przedzial *p = nowy_przedzial(W, -100, 0);
    printf("%f", miejsce_zero(W, p, 0.00001));
}
