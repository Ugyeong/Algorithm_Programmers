#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int count;
    int idx;
    
    for(int i=0; i<photo.size(); i++){
        count = 0;
        for(int j=0; j<photo[i].size(); j++){
            if(find(name.begin(), name.end(), photo[i][j])!=name.end()){
                idx = find(name.begin(), name.end(), photo[i][j])-name.begin();
                count+=yearning[idx];
            }
        }
        answer.push_back(count);
    }
    return answer;
}