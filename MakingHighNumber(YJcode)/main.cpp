#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {      // k : 제거해야 할 수의 개수
    string answer = "";                      // 선택해야할 수 : number.length() - k
                                             
    int current = 0;                         // 큰 수를 만들기 위해 선택한 자리의 인덱스 값
    int location = 0;                        // "
    char max;

    while (k != number.length())
    {       //아스키코드 0보다 작은 ..0도 맥스가 될 수 있게..
        max = 47;                            // '0' = 48이므로 0보다 작은 수로 최대값 설정
        int i;                               // 검사할 위치를 나타내는 변수

        for (i = current; i < k + 1; i++)    // 선택한 숫자 뒤부터 최대 가능 범위
        {
            if (max < number[i])             // 최대값 설정 및 위치 설정
            {
                max = number[i];
                location = i;                   // 최댓값의 인덱스 값이 location
            }
        }
        answer.push_back(number[location]);    // answer에 넣기
        current = location + 1;                // 선택한 수 뒤자리 설정
        k++;                                   //
    }
    return answer;
}

int main()
{
    string number = "4177252841";
    cout << solution(number, 4) << endl;

    string number1 = "1231234";
    cout << solution(number1, 3) << endl;
}






