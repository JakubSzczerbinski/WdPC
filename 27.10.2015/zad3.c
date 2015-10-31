#include<stdio.h>

int array[100][100];
int n, k;

int check_row(int index){
    int check_tab[100];
    for(int i = 0;i < 100;i++){
        check_tab[i] = 0;
    }
    for(int i = 0;i < n;i++){
        int x = ++check_tab[array[index][i]];
        if(x >= 2)return 0;
    }
    return 1;
}

int check_collumn(int index){
    int check_tab[100];
    for(int i = 0;i < 100;i++){
        check_tab[i] = 0;
    }
    for(int i = 0;i < n;i++){
        int x = ++check_tab[array[i][index]];
        if(x >= 2)return 0;
    }
    return 1;
}

int check_box(int x, int y){
    int check_tab[100];
    for(int i = 0;i < 100;i++){
        check_tab[i] = 0;
    }
    for(int i = x*k;i < (x+1)*k;i++){
        for(int j = x*k;j < (x+1)*k;j++){
            int x = ++check_tab[array[i][j]];
            if(x >= 2)return 0;
        }
    }
    return 1;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            array[i][j];
        }
    }
    //Sprawdzanie rzedow
    for(int i = 0;i < n;i++){
        if(!check_row(i)){
            printf("NIE");
            return 0;
        }
    }
    //Sprawdzanie kolumn
    for(int i = 0;i < n;i++){
        if(!check_collumn(i)){
            printf("NIE");
            return 0;
        }
    }
    //Sprawdzanie blokow
    int temp = n/k;
    for(int i = 0;i < temp;i++){
        for(int j = 0;j < temp;j++){
            if(!check_box(i, j)){
                printf("NIE");
                return 0;
            }
        }
    }
    printf("TAK");
    return 0;
}
