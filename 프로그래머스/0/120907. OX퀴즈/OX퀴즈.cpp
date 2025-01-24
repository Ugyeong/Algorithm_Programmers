#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    string a, cal, b, equal, c;
    for(int i=0; i<quiz.size(); i++){
        stringstream ss(quiz[i]);
        ss>>a>>cal>>b>>equal>>c;
    
        if(cal=="+"){
            if(stoi(a)+stoi(b)==stoi(c)) answer.push_back("O");
            else answer.push_back("X");
        }else if (cal=="-"){
            if(stoi(a)-stoi(b)==stoi(c)) answer.push_back("O");
            else answer.push_back("X");
        }
    }
    
    return answer;
}