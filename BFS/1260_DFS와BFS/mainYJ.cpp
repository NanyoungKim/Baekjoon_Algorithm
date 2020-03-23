#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> stackDFS;
queue<int> queueBFS;

void DFS(int V, int N, int* visited, int* edge[]) {
//   stackDFS.push(V);               // stack 지워서 해결 해보기

   // 방문했을 때, 방문여부배열을 1로
   visited[V] = 1;
   cout << V << " ";                     // 해당 노드 출력

   for (int i = 1; i <= N; i++)
   {
      if (edge[V][i] == 1 && visited[i] != 1)         // 노드가 연결되어 있고, 방문 전 노드라면
      {
      //   stackDFS.pop();
         DFS(i, N, visited, edge);               // DFS(i) --> i 방문하고 그 다음엔 i와 연결된 노드 -> ...
      }
   }
}

void BFS(int V, int N, int* visited, int* edge[]) {
   queueBFS.push(V);               // FIFO 구조인 큐를 이용 --> 방문하는 노드 큐에 넣기
   
   while (!queueBFS.empty())         // 큐가 빌 때까지 반복
   {
      int search = queueBFS.front();

      // 큐의 FRONT가 방문 전이라면 출력 후 POP / 방문했다면 그냥 POP
      if (visited[search] != 1)
      {
         cout << search << " ";
      }
      queueBFS.pop();

      // 방문 여부 노드 1로
      visited[search] = 1;

      // 큐의 FRONT와 연결되어 있고, 방문 전 노드라면 QUEUE에 넣어줌
      for (int i = 1; i <= N; i++)
      {
         if (edge[search][i] == 1 && visited[i] != 1)
         {
            queueBFS.push(i);
         }
      }
   }
}

int main() {
   // 노드 개수, 간선 개수, 시작 노드
   int N, M, V;

   int a, b;

   // 방문 여부를 알려주는 배열(0 : 방문 전/ 1 : 방문 후)
   int* visited;

   // 간선 연결 여부를 알려주는 2차원 배열( 연결 O : 1/ 연결 X: 0)
   int** edge;

   cin >> N >> M >> V;


   visited = new int[N + 1];
   for (int i = 0; i < N + 1; i++)
   {
      visited[i] = 0;
   }

   edge = new int* [N + 1];
   for (int i = 0; i < N + 1; i++)
   {
      edge[i] = new int[N + 1];
   }

   for (int i = 0; i < M; i++)
   {
      cin >> a >> b;
      edge[a][b] = 1;
      edge[b][a] = 1;
   }

   DFS(V, N, visited, edge);
   cout << endl;

   for (int i = 0; i < N + 1; i++)
   {
      visited[i] = 0;
   }

   BFS(V, N, visited, edge);
   cout << endl;

}
