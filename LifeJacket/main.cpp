//
//  main.cpp
//  그리디 알고리즘 - 구명 조끼
//
//  Created by 김난영 on 2020/03/11.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> people, int limit) {
         int answer = 0;
    int size = people.size();
    
    int start = 0;
    int end = size-1;
    
    
    sort(people.begin(), people.end(), greater<int>());
    
    
    if(size ==1 ){
        return 1;
    }
    while(start < end+1){
        
        //if( (*iterBegin) + (*iterEnd-1) > limit){
        if(people[start] + people[end] > limit ){
            answer++;
           // people.erase(people.begin());
            start++;
        }
        else{
            answer++;
            start++;
            end--;
        }
              
    }
    

   // cout << "answer : " << answer << endl;
    return answer;
    
}


int main() {
   
    
    vector<int> people = {70,50,80,50};
    int limit = 100;
    
    solution(people, limit);
    
    
    return 0;
}
