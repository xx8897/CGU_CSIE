#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include <queue>
#include <deque>
#include <list>

using namespace std;

int n = 0;
int v = 0;
int ** array;
struct Node{
  int data=0;
  int numofedge=0;
  int color = 0;
  Node *child;
};
Node *pointer;
queue<Node *> q;

int findFirst(Node *Node[]){
  pointer = NULL;
  int i=0;

  bool find = false;
  while(find==false && i<n){
    pointer = Node[i];
    if(pointer->child!=NULL){
      find = true;
    }
    if(pointer->child==NULL){
      i++;
    }
  }
  if(find)
    return i;
  else
    return -1;
}

void dfs_visit(int* node_color, int node,int parent){
  if(node_color[node]==0){
    cout << parent+1 << " " << node+1 << endl;
    node_color[parent] = 1;
  }
  for(int i=0;i<n;i++){
    if(i!=node && (array[node][i]==1 && node_color[i]==0)){
      dfs_visit(node_color,i,node);
    }
  }
  node_color[node] = 2;
}

void dfs(int u,int v){
  cout << "Matrix DFS Algorithm" << endl;
  int* node_color = new int[n];
  // 0=white, 1=gray, 2=black
  for(int i=0;i<n;i++){
    node_color[i] = 0;
  }
  dfs_visit(node_color, v, u);
  for (int i = 0; i < n;i++){
    if(node_color[i]==0){
      dfs_visit(node_color, i, i);
    }
  }
}
void bfs(Node *list[]){
  int *color= new int[n];
  for (int i = 0; i < n;i++){
    color[i] = 0;
  }
  
  for(int i=0;i<n;i++){
    pointer = list[i];
    int k = i;
    if (pointer->child == NULL && color[i] == 0)
    {
      color[i] = 1;
      cout << i + 1 << " " << i + 1 << endl;
    }
    color[i] = 1;
    for (int j = 0; j < n;j++)
    {
      while (pointer->child != NULL )
      {
        if(color[pointer->child->data-1]==0){
          q.push(pointer->child);
          color[pointer->child->data - 1] = 1;
          cout << k + 1 << " " << pointer->child->data<<endl;
        }
        pointer = pointer->child;
      }
      if(!q.empty()){
      k = q.front()->data - 1;
      color[k] = 1;
      pointer = list[k];

      q.pop();
      }
    }
    
  }
}

int main(){

  srand( time(NULL) );

  cout << "請輸入節點數";
  cin >> n;
  int max = n*(n - 1) / 2;
  cout << "請輸入邊線數"<<" "<<"最多"<< max <<"個";
  cin >> v; 

  Node *list[n];
  //cout << "ok1" << endl;

  array = new int * [n];     
        //此矩陣有 n 個列(rows); 先 new 出 n 個 int *
  for (int i=0; i<n; i++)
  {   
    array[i] = new int [n];
    //每一列有 n 行(columns); array[i] 指向新 new 出的 n 個 int
  }

  //cout << "ok2" << endl;

  for (int i = 0; i < n;i++){
    for (int j = 0; j < n;j++){
      array[i][j] = 0;
    }
  }

  //cout << "ok3"<< endl;
  int x=0;
  int y=0;
  for (int i = 0; i < v; i++){
    x = rand() % n;
    y = rand() % n;
    while((x==y)||(array[x][y]==1)){
      x = rand() % n;
      y = rand() % n;
    }
    array[x][y] = 1;
    array[y][x] = 1;
  }
  cout << "adjust matrix"<<endl;
  cout << " ";
  for (int i = 0; i < n;i++){
    cout << " " << i+1;
  }
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    cout << i + 1 << " ";
    for (int j = 0; j < n; j++)
    {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }

  cout << "adjust list" << endl;
  for (int i = 0; i < n;i++){
    list[i] = new Node();
    list[i]->data = i+1;
    pointer = list[i];

    for (int j = 0; j < n;j++){

      if(array[i][j]==1){
              
        list[i]->numofedge++;
        
        pointer->child = new Node();
        pointer->child->data = j + 1;
        pointer = pointer->child;
      }
    }
  }
  
  //cout << "okk" << endl;
  for (int i = 0; i < n;i++){
    cout << list[i]->data;
    pointer = list[i];
    for (int j = 0; j < list[i]->numofedge;j++){
      pointer = pointer->child;
      cout << "-->" << pointer->data;
    }
    cout<< endl;
  }

  int u= findFirst(list);
  dfs(u, pointer->child->data-1);

  cout << "Mateix BFS Algorithm"<< endl;
  bfs(list);

  // 動態矩陣用完後還給系統, 好習慣! 怎麼 new 來的就怎麼還 !
  for (int i = 0; i < n; i++)
    {
      delete[] array[i];
    }
  delete [] array;




  cout << "結束" <<endl;
  return 0;
}

