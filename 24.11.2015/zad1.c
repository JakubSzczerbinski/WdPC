#include<stdio.h>
#include<stdlib.h>

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

int main(){
    double tab[] = {1, 2, 3, 4}, tab1[] = {2, 3, 1};
    wielomian *K = init(tab, 4);
    wielomian *L = init(tab1, 3);
    print(L);
    print(K);
    wielomian *S = odejmij(K, L);
    print(S);
    wielomian *P = pomnoz(K, S);
    print(P);
    double r = wartosc(P, 0.5);
    printf("%f \n", r);
}
