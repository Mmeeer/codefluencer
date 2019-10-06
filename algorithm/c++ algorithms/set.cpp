#include<set>
#include<stdio.h>
int main(){
  set<int> s;
  multiset<int> ms;
  int n, tmp;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &tmp);
    s.insert(tmp);
    ms.insert(tmp);
  }
  set<int>::iterator it;
  for(it = s.begin(); it != s.end(); it++){
    printf("%d ", *it);
  }
  for(it = ms.begin(); it != ms.end(); it++){
    printf("%d ", *it);
  }
}
