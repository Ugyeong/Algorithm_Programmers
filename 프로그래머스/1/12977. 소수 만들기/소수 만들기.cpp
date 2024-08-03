#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> arr;
    bool flag = true;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                arr.push_back(nums[i]+nums[j]+nums[k]);
            }
        }
    }
    
    for(int i=0; i<arr.size(); i++){
        flag = true;
        for(int j=2; j<=arr[i]/2; j++){
            if(arr[i]%j==0) {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
 
    return answer;
}