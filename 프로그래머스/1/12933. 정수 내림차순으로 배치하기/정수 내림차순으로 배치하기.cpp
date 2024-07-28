#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);
    int idx = 0;
    vector<int> tmp(10);
    for(int i=0; i<str.size(); i++){
        idx = str[i]-'0';
        tmp[idx]++;
    }
    str = "";
    for(int i=9; i>=0; i--){
        for(int j=0; j<tmp[i]; j++){
            str+=to_string(i);
        }
    }

    return stol(str);
}