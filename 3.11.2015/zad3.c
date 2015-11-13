#include<stdio.h>

char temptab[100], expression_tab[1000];

struct exp{
  char type;
  unsigned long long int value;
}

exp tab[100];
int exp_count = 0;

unsigned long long int parse_int(int s, int e){
  unsigned long long int result = 0;
  for(int i = s;i < e;i++){
    if('0' <= t[i] && t[i] <= '9'){
      result *= 10;
      result += t[i]-'0';
    }
    if(t[i] = ':'){
      result *= 60;
    }
  }
  return result;
}

void parse(char* t, int l){
  int start, i;
  for(i = 0;i < l;i++){
    if(t[i] != ' '){
      break;
    }
  }
  start = i;
  for(;i < l;i++){
    if(tab[i] == ' '){
      if(exp_count % 2 == 0){
	tab[exp_count].value = parse_int(start, i);
	tab[exp_count].type = 'v';
      }
      else{
	tab[exp_count].type = tab[i-1];
      }
      exp_count++;
      while(tab[i] == 0){
	i++;
      }
      start = i;
    }
  }

}

unsigned long long int evalueate(){
  unsigned long long int value = tab[0].value;
  for(int i = 1;i < exp_count;i += 2;){
    switch (tab[i].type){
      case '+':
	value += tab[i+1].value;
	break;
      case '*':
	value *= tab[i+1].value;
	break;
      case '-':
	value -= tab[i+1].value;
	break;
      case '/':
	value /= tab[i+1].value;
	break;
      default:
	printf("error");
    }
  }
  return value;
}




int main(){
  
}
