#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return (a+b)>(b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numstr;
    string tmp = "";
    for(int i=0; i<numbers.size(); i++){
        numstr.push_back(to_string(numbers[i]));
    }
    
    sort(numstr.begin(), numstr.end(), cmp);
    if(numstr[0]=="0") return "0";
    
    for(int i=0; i<numstr.size(); i++){
        answer+=numstr[i];
    }
    return answer;
}