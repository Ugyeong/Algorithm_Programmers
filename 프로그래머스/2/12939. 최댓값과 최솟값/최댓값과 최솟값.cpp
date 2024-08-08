#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr;
    string tmp = "";
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            arr.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp+=s[i];
    }
    arr.push_back(stoi(tmp));
    
    sort(arr.begin(), arr.end());
    answer = to_string(arr[0]) + " " + to_string(arr[arr.size()-1]);
    return answer;
}