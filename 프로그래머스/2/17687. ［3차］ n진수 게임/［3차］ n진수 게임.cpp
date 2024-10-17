#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string arr[17] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

string change(int n, int num){
    string tmp = "";

    while(num>=n){
        tmp+=arr[num%n];
        num/=n;
    }
    tmp+=arr[num];    
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    string tmp = "";
    
    while(tmp.length()<=t*m+p){
        tmp+=change(n,num++);
    }
    tmp+=change(n,num);
    
    for(int i=0; answer.size()<t; i++){
        if((i%m+1)==p) answer+=tmp[i];
    }
    return answer;
}