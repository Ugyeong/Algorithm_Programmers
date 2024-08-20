#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chk(int a, int b){ //최소공배수 구하기
    for(int i=b; i<=a*b; i++){
        if(i%a==0 && i%b==0){
            return i;
        }
    }
}

int solution(vector<int> arr) {
    int answer;
    bool flag = false;
    int c = 2;
    
    if(arr.size()==1) return arr[0];
    
    sort(arr.begin(), arr.end());
    answer = arr[arr.size()-1];
    
    while(!flag){
        flag = true;
        
        answer = chk(arr[arr.size()-c], answer);
        c++;
        
        for(int i=0; i<arr.size(); i++){ //모두의 배수인지 확인
            if(answer%arr[i]!=0){
                flag = false;
                break;
            }
        }
    }
    return answer;
}