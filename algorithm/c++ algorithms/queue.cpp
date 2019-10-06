#include<queue>
#include<stdio.h>
int main(){
  queue<int> q;
  priority_queue<int> pq;
  int n, tmp;
  scanf("%d", n);
  while(n--){
    scanf("%d", &tmp);
    q.push(tmp);
    pq.push(tmp);
  }
  while(!q.empty()){
    printf("%d", q.front());
    q.pop();
  }
  while(!pq.empty()){
    printf("%d", pq.top());
    pq.pop();
  }
}
