#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    bool stop = false;
    bool flag = true;
    string tmp;
    vector<string> str = {"aya", "ye", "woo", "ma"};
    int before = -1;
    
    for(int i=0; i<babbling.size(); i++){
        flag = true;
        stop = false;
        before = -1;
        
        tmp = babbling[i];
        while(!stop){
            switch(tmp[0]){
                case 'a':
                    if(before!=0 && tmp.substr(0,3)==str[0]){
                        if(tmp.length()==str[0].size()){
                            stop = true;
                        }else{
                            tmp = tmp.substr(3);
                        }
                    }else {
                        flag = false;
                        stop = true;
                    }
                    before = 0;
                    break;
                    
                case 'y':
                    if(before!=1 && tmp.substr(0,2)==str[1]){
                        if(tmp.length()==str[1].size()){
                            stop = true;
                        }else{
                            tmp = tmp.substr(2);
                        }
                    }else {
                        flag = false;
                        stop = true;
                    }
                    before = 1;
                    break;
                    
                case 'w':
                    if(before!=2 && tmp.substr(0,3)==str[2]){
                        if(tmp.length()==str[2].size()){
                            stop = true;
                        }else{
                            tmp = tmp.substr(3);
                        }
                    }else {
                        flag = false;
                        stop = true;
                    }
                    before = 2;
                    break;
                    
                case 'm':
                    if(before!=3 && tmp.substr(0,2)==str[3]){
                        if(tmp.length()==str[3].size()){
                            stop = true;
                        }else{
                            tmp = tmp.substr(2);
                        }
                    }else {
                        flag = false;
                        stop = true;
                    }
                    before = 3;
                    break;
                    
                default:
                    flag = false;
                    stop = true;
            }
        }
        if(flag) answer++;
        cout<<" ";
    }
    
    return answer;
}