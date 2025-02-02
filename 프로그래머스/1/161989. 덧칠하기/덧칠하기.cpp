#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int complete = 0;
    for(int i=0; i<section.size(); i++){
        if(section[i]>complete){
            answer++;
            complete = section[i] + m - 1;
        }
    }
    return answer;
}