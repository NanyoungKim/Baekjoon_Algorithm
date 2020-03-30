//
//  main.cpp
//  BFS - 미로찾기(2178번)
//
//  Created by 김난영 on 2020/03/29.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <queue>
#include <utility>


using namespace std;

int N, M = 0;




pair<int, int> idx;
queue<pair<int,int>> q;

void bfs (int **maze, int **cnt, int r, int c){
    
    
   
    
    while(!q.empty()){
        
        int count = 0;
        
        
    if((r == 0) && (c == 0)){       //오른쪽, 아래만
        
        if((cnt[r+1][c] == 0) && (maze[r+1][c] == 1)){      //아래
             cnt[r+1][c] = cnt[r][c] + 1;
             //bfs(maze, cnt, r+1, c);
            
            q.push(make_pair(r+1, c));
            
         }
        
         if((cnt[r][c+1] == 0) && (maze[r][c+1] == 1)){      //오른쪽
             cnt[r][c+1] = cnt[r][c] + 1;
             //bfs(maze, cnt, r, c+1);
             q.push(make_pair(r, c+1));
             
             
         }

    }
    
    
    
    if((r == 0) && (1 <= c < M -1)){    //위쪽만 빼고
        
        if((cnt[r][c-1] == 0) && (maze[r][c-1] == 1)){      //왼쪽
              cnt[r][c-1] = cnt[r][c] + 1;
           //bfs(maze, cnt, r, c-1);
            q.push(make_pair(r, c-1));
          }
        
          if((cnt[r+1][c] == 0) && (maze[r+1][c] == 1)){      //아래
              cnt[r+1][c] = cnt[r][c] + 1;
             // bfs(maze, cnt, r+1, c);
              q.push(make_pair(r+1, c));
          }
         
          if((cnt[r][c+1] == 0) && (maze[r][c+1] == 1)){      //오른쪽
              cnt[r][c+1] = cnt[r][c] + 1;
              //bfs(maze, cnt, r, c+1);
              q.push(make_pair(r, c+1));
          }
    }
    
    
    if((r ==0) && (c == M -1)){      //왼쪽, 아래쪽만
        if((cnt[r][c-1] == 0) && (maze[r][c-1] == 1)){      //왼쪽
              cnt[r][c-1] = cnt[r][c] + 1;
            //bfs(maze, cnt, r, c-1);
            q.push(make_pair(r, c-1));
          }
        
          if((cnt[r+1][c] == 0) && (maze[r+1][c] == 1)){      //아래
              cnt[r+1][c] = cnt[r][c] + 1;
              //bfs(maze, cnt, r+1, c);
              q.push(make_pair(r+1, c));
          }
    }
    
    if((1 <= r < N-1) && (c == 0)){   //왼쪽만 빼고
        if((cnt[r-1][c] == 0) && (maze[r-1][c] == 1)){      //위
               cnt[r-1][c] = cnt[r][c] + 1;
               //bfs(maze, cnt, r-1, c);
            q.push(make_pair(r-1, c));
           }
           if((cnt[r+1][c] == 0) && (maze[r+1][c] == 1)){      //아래
               cnt[r+1][c] = cnt[r][c] + 1;
              // bfs(maze, cnt, r+1, c);
               q.push(make_pair(r+1, c));
           }
          
           if((cnt[r][c+1] == 0) && (maze[r][c+1] == 1)){      //오른쪽
               cnt[r][c+1] = cnt[r][c] + 1;
               //bfs(maze, cnt, r, c+1);
               q.push(make_pair(r, c+1));
           }
    }
    
    
    
    if((r == N-1) && (c == 0)){           //위, 오른쪽만
        if((cnt[r-1][c] == 0) && (maze[r-1][c] == 1)){      //위
               cnt[r-1][c] = cnt[r][c] + 1;
               //bfs(maze, cnt, r-1, c);
            q.push(make_pair(r-1, c));
           }
        if((cnt[r][c+1] == 0) && (maze[r][c+1] == 1)){      //오른쪽
            cnt[r][c+1] = cnt[r][c] + 1;
           // bfs(maze, cnt, r, c+1);
            q.push(make_pair(r, c+1));
        }
    }
    
    
    if((r == N-1) && (1<= c < M -1)){   //아래만 빼고
        if((cnt[r-1][c] == 0) && (maze[r-1][c] == 1)){      //위
              cnt[r-1][c] = cnt[r][c] + 1;
              //bfs(maze, cnt, r-1, c);
            q.push(make_pair(r-1, c));
          }
          if((cnt[r][c-1] == 0) && (maze[r][c-1] == 1)){      //왼쪽
              cnt[r][c-1] = cnt[r][c] + 1;
              //bfs(maze, cnt, r, c-1);
              q.push(make_pair(r, c-1));
          }
         
          if((cnt[r][c+1] == 0) && (maze[r][c+1] == 1)){      //오른쪽
              cnt[r][c+1] = cnt[r][c] + 1;
             // bfs(maze, cnt, r, c+1);
              q.push(make_pair(r, c+1));
          }
    }
    
    if((1<= r < N-1) && (c == M-1)){       //오른쪽만 빼고
        if((cnt[r-1][c] == 0) && (maze[r-1][c] == 1)){      //위
              cnt[r-1][c] = cnt[r][c] + 1;
             // bfs(maze, cnt, r-1, c);//위
            q.push(make_pair(r-1, c));
          }
          if((cnt[r][c-1] == 0) && (maze[r][c-1] == 1)){      //왼쪽
              cnt[r][c-1] = cnt[r][c] + 1;
             // bfs(maze, cnt, r, c-1);
              q.push(make_pair(r, c-1));
          }
        
          if((cnt[r+1][c] == 0) && (maze[r+1][c] == 1)){      //아래
              cnt[r+1][c] = cnt[r][c] + 1;
              //bfs(maze, cnt, r+1, c);
              q.push(make_pair(r+1, c));
          }
    }
    
        
        
        
        q.pop();
        r = q.front().first;
        c = q.front().second;
    
        
    }
    
    if((r==N-1) && (c == M-1)){
        cout << cnt[r][c];
    }
    
    
    
    
    
}
    
  
    
    
    
    
    
   
    
    





int main() {
    
   
    cin >> N >> M;
    
    int curRow = 0;
    int curCol = 0;
    
    
    int **mazeArr = new int*[N];            //2차원 배열 동적배열 선언
    int **cntArr = new int*[N];
    for(int i=0; i<M; ++i){
        mazeArr[i] = new int[M];            //초기화
        cntArr[i] = new int[M];
    }
    
    
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            cin >> mazeArr[i][j];           //갈 수 있는 길 입력
            cntArr[i][j] = 0;               //카운트 초기 값은 0으로
        }
    }
    
    cntArr[0][0] = 1;                       //시작지점은 1로 시작
    
    
    cout << "mazeArr = ";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
        
            cout << mazeArr[i][j] << " ";
        }
        cout << endl;
    }
    
   
    q.push(make_pair(0,0));
    bfs(mazeArr, cntArr, curRow, curCol);
    
    
    
    
    
    
    
    
    return 0;
}
