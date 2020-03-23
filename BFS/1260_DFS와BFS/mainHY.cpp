#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
#define MAX 1001


//재풀이
#define MAX 1001
vector<vector<int>> graph(MAX, vector<int>(MAX, 0)); //vector로 이차원배열 생성
bool visited[MAX] = { false, };
int N;
void BFS(int start);
void DFS(int start);

int main() {
   int  M, V;
   cin >> N >> M >> V;

   int A, B;
   for (int i = 0; i < M; i++) {
      cin >> A >> B;
      graph[A][B] = 1;
      graph[B][A] = 1;
   }
   DFS(V);
   cout << "\n";
   BFS(V);

}

//깊이 탐색 -> 쭉
void DFS(int start) {
   cout << start << " "; //출력
   visited[start] = true; //방문했음

   for (int i = 1; i <= N; i++) {
      if (graph[start][i] == 1 && !visited[i]) { //방문하지 않았고, edge로 연결되어있으면
         DFS(i); //넘어가서 그 vertex로 dfs() 호출
      }
   }
   return;
}

//넓이탐색
void BFS(int start) {
   queue<int> q;

   visited[start] = false; //dfs에서 true로 바꾸어줬기 때문에 false로
   q.push(start); //시작점을 q에 push

   while (!q.empty()) { //q가 빌때까지
      int a = q.front();
      cout << q.front() << " ";
      q.pop(); //출력후에는 pop

      for (int i = 1; i <= N; i++) {
         if (graph[a][i] == 1 && visited[i]) { //연결되어있고 방문하지 않았다면
            q.push(i); //q에 푸시
            visited[i] = false;
         }
      }
   }
   return;
}
