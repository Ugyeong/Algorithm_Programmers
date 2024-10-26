#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> arr;
    int count = 0;
    int n = elements.size();
    elements.insert(elements.end(), elements.begin(), elements.end());
    for(int i=0; i<n; i++){
        for(int j=1; j<=n; j++){
            count = 0;
            for(int k=0; k<j; k++){
                count+=elements[i+k];
            }
            arr.push_back(count);
        }
    }
    
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
   
    answer = arr.size();
    
    return answer;
}