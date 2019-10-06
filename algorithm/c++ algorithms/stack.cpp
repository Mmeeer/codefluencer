#include<stack>
#include<stdio.h>
int main(){
  stack<int> s;
  int n, tmp;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &tmp);
    s.push(tmp);
  }
  while(!s.empty()){
    printf("%d ", s.top());
    s.pop();
  }
  return 0;
}
