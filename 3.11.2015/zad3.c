#include<stdio.h>

char evtab[100], exptab[1000];

int str_to_integer(char* tab, int n){


}

int is_in_range(char* tab, int n, int index, char min, char max){
  while(1){
    if(tab[index] == ' '){
      continue;
    }
    if(tab[index] >= min && tab[index] <= max){
      return index;
    }
    else{
      return 0;
    }
    index++;
    if(index >= n){
      return -1;
    }
  }
}

void cpy_exp_to_evtab(char* exp, int n){
  int x = 0;
  for(int i = 0;i < n;i++){
    if(int a = is_in_range(exp, n, '*', '/')){
      if(x == 1){
        memcpy() 
      }
      x = 1;
    }
  }
}

int evalueate(char* tab, int n){

}

int evalueate(char* tab, int n, arg1){

}
int parse(char* tab, int n){
  if(int a = is_in_range(tab, n, 0, '0', '9')){
  }
}



int main(){

}
