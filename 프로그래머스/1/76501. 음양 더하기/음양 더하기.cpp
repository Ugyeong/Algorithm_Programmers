#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int true_sum = 0;
    int false_sum = 0;
    for(int i=0; i<absolutes.size(); i++){
        if(signs[i]==true) true_sum += absolutes[i];
        else false_sum += absolutes[i];
    }
    return true_sum-false_sum;
}