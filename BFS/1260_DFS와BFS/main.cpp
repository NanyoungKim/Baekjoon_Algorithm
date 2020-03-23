//
//  main.cpp
//  DFS BFS - 1260번 DFS와 BFS
//
//  Created by 김난영 on 2020/03/12.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int N,M,V;
vector<int> vec;

vector<int> vec2;
stack<int> Stack;
queue<int> Queue;

void dfs(int start, int visitedArr[], int **gra){
    
    visitedArr[start] = 1;      //처음 시작 노드는 방문된 것
    Stack.push(start);          //스택에 넣음
   vec.push_back(start);        //vec 벡터는 answer 임
    
    
    
    while(!Stack.empty()){      //스택에 아무것도 없을 때 까지 반복
        
        bool chk = false;
        
        int i;
        for(i=1; i<=N; i++){
            
            
            if((gra[start][i]==1) && (visitedArr[i]==0)){           //노드가 연결되어있고 방문한 노드가 아니면
                Stack.push(i);          //노드를 스택에 넣고
                visitedArr[i]=1;        //방문했다고 표시하고
                start = i;              //시작 노드를 연결된 노드로 바꿈
                vec.push_back(i);
                chk = true;             //연결된 노드가 있다는 것을 나타냄
                break;                  //dfs 이므로 break 하고 for문 나감
            }
            
        
        }
        if(chk==false){                     //연결된 노드가 없으면(막다른 길이면)
            Stack.pop();                    //스택에서 꺼냄
            if(Stack.empty()!=true){
                start = Stack.top();        //스택이 비지 않았으면 시작노드는 스택의 맨 위 노드
            }
        }
        
        
    }
   // cout << "dfs : ";
    for(int j=0; j<vec.size(); j++){
   
        cout << vec[j] << " ";
    }
    cout << endl;

    
}


void bfs (int start, int visitedArr[], int **gra){
    
    
    
    visitedArr[start] = 1;
    Queue.push(start);
    vec2.push_back(start);
    
    
    
    while(!Queue.empty()){
   
        int i;
        for(i=1; i<=N; i++){
            
            
            if((gra[start][i]==1) && (visitedArr[i]==0)){       //bfs 라서 break 없이 연결된 노드는 쭉 방문
                Queue.push(i);
                visitedArr[i]=1;
                vec2.push_back(i);

            }
            
        
        }
        Queue.pop();                    //연결된 자식들 다 돌면 맨 앞에 있는 노드(부모노드) 삭제
        start = Queue.front();          //맨 앞의 노드(삭제된 부모노드의 자식 중 숫자가 제일 작은 노드)를 시작 노드로 설정
        
    
        
        
        
    }
    
    
    //cout << "bfs : ";
     for(int j=0; j<vec2.size(); j++){
    
         cout << vec2[j] << " ";
     }
    
    
  
    
}





int main() {
    
   
    
    
    cin >> N >> M >> V;
    
    

    int *visitedArr = new int[N+1];     //0,1 ~ N               //방문한 노드인지 아닌지 구분. 0이면 방문x 1이면 방문o
    
    for(int i=0; i<N+1; i++){
        visitedArr[i] = 0;                                      //처음엔 0으로 초기화
    }
    
    int **graph;                                                //연결된 간선을 나타내는 2차원 배ㅕㅇㄹ
    graph = new int*[N+1];
    for(int i=0; i<N+1; i++){
        graph[i] = new int [N+1];
    }
    
    for(int i=0; i<N+1; i++){
        for(int j=0; j<N+1; j++){
            graph[i][j] = 0;
        }
    }
    
    
    int a,b= 0;
    for(int i=0; i<M; i++){
       
        cin >> a >> b;
        
        graph[a][b] = 1;                                        //a노드와 b노드가 연결되었으면 1로 표시
        graph[b][a] = 1;
        
    }
    
    
    
    
   
   

    //dfs(V, int (*visitedArr), int (*graph)[N + 1]);
    
    
    dfs(V, visitedArr, graph);
    
    for(int i=0; i<N+1; i++){
        visitedArr[i] = 0;                      //dfs 실행 후 visitedArr 초기화
    }
    bfs(V, visitedArr, graph);
    
    
    
    return 0;
}
