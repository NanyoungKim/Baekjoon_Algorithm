//
//  main.cpp
//  BFS - 단지번호붙이기(2667번)
//
//  Created by 김난영 on 2020/03/30.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
queue<pair<int,int> > q;
vector<int> vec;
int count = 0;
int num = 0;



bool isFinish = false;


bool Inside(int a, int b){
    
    if((a >=0 && a < N) && (b >= 0 && b < N)){
        return true;
    }
    else{
        return false;
    }
   
}

void searchFunc(int **map, int **visit){
    
    bool chk = false;
    int c = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            c++;
            
            if((map[i][j] ==1) && visit[i][j] == 0){ //집이 있는데 아직 방문하지 않았으면
                q.push(make_pair(i,j));
                visit[i][j] = 1;
                chk = true;    //시작 노드 찾은것
                vec.push_back(1);         //총 몇개의 단지가 있는지
                break;
                
            }
            
            
            
        }
        if(c == ((int)pow(N,2))) {chk = true; break; }
        
        
        if(chk == true) {break;}
    }
    
    
    
    if(chk==false){     //다 돌았는데도 집 있는 곳 못 찾은 것은 더이상 서치할 노드 없는 것
        isFinish = true;
    }
    
    //if(num!=0) {num++;}
}


void bfs(int **map, int **visit){
    
    
    int move[4][2] = {
        {-1,0}, //위
        {1,0},//아래
        {0,-1},//왼
        {0,1}//오른
    };

 
    
    while(!isFinish){
    


            int row = q.front().first;
            int col = q.front().second;

            while(!q.empty()){
                
                for(int i=0; i<4; i++){
                           
                       //위 0,0 / 아래 1,0 / 왼/ 오
                       int nextRow = row + move[i][0];
                       int nextCol = col + move[i][1];
                    
                    //범위 안에 있고, 방문할 노드가 비어있고, 그 노드에 집이 있으면
                     if((Inside(nextRow, nextCol) == true) && (visit[nextRow][nextCol] == 0) && (map[nextRow][nextCol] == 1)){
                    
                         q.push(make_pair(nextRow, nextCol));
                         visit[nextRow][nextCol] = 1;
                         
                         vec[num]++;
                         
                         
                     }

                }
                
                q.pop();
                if(q.empty() == false) { //큐에 아직 노드가 있으면
                
                    row = q.front().first;
                    col = q.front().second;
                }
                
                
            }


            //단지 하나 서치 끝
            //다시 집이 있는 단지를 찾기 위해 searchFunc() 호출
            num++;
            searchFunc(map, visit);
        



                
    }
    sort(vec.begin(), vec.end());
    
    cout << num << endl;
    
    for(std::vector<int>::size_type i = 0; i != vec.size(); i++) {
        cout << vec[i] << endl;
    }
    
}








int main() {

    cin >> N;
    
    
    int **mapArr = new int*[N];
    int **visitArr = new int*[N];
    

    for(int i=0; i<N; i++){
        mapArr[i] = new int[N];
        visitArr[i] = new int[N];
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &mapArr[i][j]);
            
            visitArr[i][j] = 0;
        }
    }
    
    
    
    searchFunc(mapArr, visitArr);
    bfs(mapArr, visitArr);
    
    
    
    
    return 0;
}
