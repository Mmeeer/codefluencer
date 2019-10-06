#include<vector>
#include<stdio.h>
int main(){
  vector<int> v;
  int n, tmp;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &tmp);
    v.push_back(tmp);
  }
  for(int i = n - 1; i >= 0; i--){
    printf("%d", v[i]);
  }
  return 0;
}
