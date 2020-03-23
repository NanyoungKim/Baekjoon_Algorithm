#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<stack>
using namespace std;

string solution1(string number, int k) {
    stack<char> stk;
    int sz = number.length() - k; //결과의 길이

    for (int i = 0; i < number.length(); i++) {
        char ch = number[i]; //순서대로 넣고
        for (; (!stk.empty()) && k > 0; k--) { //스택이 비지않고 k번 동안
            char stack_top = stk.top();
            if (stack_top >= ch)    //이미들어가있는 요소가 크다면
                break;
            stk.pop();//작다면 pop
        }
        stk.push(ch);//넣어주기
    }
    while (stk.size() != sz)//크기가 다르면
        stk.pop(); //pop
    string answer;
    while (!stk.empty()) {
        char x = stk.top();
        answer = x + answer;
        stk.pop();
    }
    return answer;
}

int main() {
    string an = solution1("15778595",3);
    cout << an << endl;
}


