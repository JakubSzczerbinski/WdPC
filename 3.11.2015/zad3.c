#include<stdio.h>

char temptab[100], expression_tab[1000];

struct exp{
  char type;
  unsigned long long int value;
};

int hasHour = 0;

struct exp tab[100];
int exp_count = 0;

unsigned long long int parse_int(int s, int e){
  unsigned long long int result = 0;
  for(int i = s;i < e;i++){
    if('0' <= expression_tab[i] && expression_tab[i] <= '9'){
      result *= 10;
      result += expression_tab[i]-'0';
    }
    if(expression_tab[i] == ':'){
      result *= 6;
      hasHour = 1;
    }
  }
  printf("%lld \n", result);
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
    if(t[i] == ' '){
      if(exp_count % 2 == 0){
	       tab[exp_count].value = parse_int(start, i);
	       tab[exp_count].type = 'v';
      }
      else{
	       tab[exp_count].type = t[i-1];
      }
      exp_count++;
      while(t[i] == ' '){
	       i++;
      }
      start = i;
    }
  }
  tab[exp_count].value = parse_int(start, i);
  tab[exp_count].type = 'v';
  exp_count++;
}

unsigned long long int evalueate(){
  unsigned long long int value = tab[0].value;
  for(int i = 1;i < exp_count;i += 2){
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

void print_result(unsigned long long int result){
  if(hasHour){
    int hh = result/(60*60);
    int mm = (result/(60))%(60);
    int ss = result%(60*60);
    if(hh != 0){
      printf("%d:", hh);
    }
    if(hh != 0 || mm != 0){
      printf("%d:", mm);
    }
    if(hh != 0 || mm != 0 || ss != 0){
      printf("%d\n", ss);
    }
  }
  else{
    printf("%llu\n", result);
  }
}


int main(){
  int i = 0;
  while((expression_tab[i] = getchar()) != '\n'){
    i++;
  }
  parse(expression_tab, i);
  unsigned long long int res = evalueate();
  print_result(res);
}
