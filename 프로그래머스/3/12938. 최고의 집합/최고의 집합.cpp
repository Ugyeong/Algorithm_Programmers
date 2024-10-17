#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> tmp(n,s/n);

    if(n>s){
        tmp.clear();
        tmp.push_back(-1);
        return tmp;
    }

    for(int i=0; i<s%n; i++){
        tmp[i%n]++;
    }

    sort(tmp.begin(), tmp.end());

    return tmp;
}