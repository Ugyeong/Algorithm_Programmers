#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    answer.push_back(-1);
    int min_idx = min_element(arr.begin(), arr.end())-arr.begin();
    arr.erase(arr.begin()+min_idx);
    if(arr.size()>0) return arr;
    else return answer;
}