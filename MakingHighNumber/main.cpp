//
//  main.cpp
//  그리디 알고리즘
//
//  Created by 김난영 on 2020/03/01.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;



string solution(string number, int k) {
    string answer = "";
   
       int numLen = number.length();        //처음 숫자의 길이
       int p = numLen-k;                    //k가 제거할 수의 개수이므로 p는 수를 제거하고 나서의 수 길이
       int a = numLen-(p-1);                //최소로 검사해야 하는 숫자 갯수
       int check = 0;                       //검사 횟수
       
       for(int i = 0; i< p; i++){
           
           char m = number[0];              //숫자의 맨 첫 자리 수
           //string max;
         //  cout << "max = " << max << endl;
           
           check = 0;                       //검사 횟수를 초기화
           
           for(int j=0; j<a-1; j++){        //맨 처음 수를 기준으로 a-1 번 비교를 해야하므로 반복.
               
               if(m < number[j+1]){         //제일 큰 수를 찾는다.
                   m = number[j+1];
                   check = j+1;//check = 2  //
                
               }
               else{
                //   check = 0;
               }

               
           }
           
           string max(1,m);             //큰 수를 뽑아서 숫자를 하나씩 완성해 나간다.
           answer.append(max);
           
           for(int b=0; b<numLen-(check+1); b++){   //이미 선택된 수를 제외하고 남은 수들로
               number[b] = number[b+check+1];       //다시 문자열을 만든다.
           }
           
           numLen = numLen-(check+1);               //새로 만든 문자열 길이로 재 정의 한다.
           if(numLen==0){
              // char m2 = number[1];
           //    string max2(1,m2);
             //  answer.append(max2);
               break;
           }
           a = numLen-p+i+2;
           
          
           
       }
    
    
    
      //  cout << answer << endl;
    
    
    return answer;
}

int main() {
   
    
    
 
    string number = "1231234";
    string answer = "";

  //  cout << "number[0] = " << number[0] << endl;
   
    solution(number, 3);        //두번째 파라미터는 제거할 수의 개수
    
    
    
    
    
    return 0;
}
