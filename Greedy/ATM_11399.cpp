#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
    
    int answer = 0;
    int N;
    cin >> N;
    
    vector<int> vec;

    int num;
    for(int i =0; i< N; i++){
       cin >> num;
        vec.push_back(num);

    }
    
    
    sort(vec.begin(), vec.end());
    
    
    int n = N;
    for(int i=0; i<N; i++){
        
        answer += n*vec[i];
        n--;
    }
    
    cout << answer;
    

    
    
    return 0;
}
