#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int m = park.size();
    int n = park[0].size();
    bool flag = false;
    int x, y;
    string dir;
    int go;
    
    for(int i=0; i<m; i++){
        if(flag) break;
        for(int j=0; j<n; j++){
            if(park[i][j] == 'S'){
                x = i;
                y = j;
                flag = true;
                break;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++){
        dir = routes[i][0];
        go = routes[i][2]-'0';
        flag = true;
        
        if(dir=="E"){
            if(y+go<n){
                for(int j=y+1; j<=y+go; j++){
                    if(park[x][j]=='X'){
                        flag = false;
                        break;
                    }
                }
            }else flag = false;
            if(flag) y+=go;
        }else if(dir=="W"){
            if(y-go>=0){
                for(int j=y-1; j>=y-go; j--){
                    if(park[x][j]=='X'){
                        flag = false;
                        break;
                    }
                }
            }else flag = false;
            if(flag) y-=go;
        }else if(dir=="S"){
            if(x+go<m){
                for(int j=x+1; j<=x+go; j++){
                    if(park[j][y]=='X'){
                        flag = false;
                        break;
                    }
                }
            }else flag = false;
            if(flag) x+=go;
        }else if(dir=="N"){
            if(x-go>=0){
                for(int j=x-1; j>=x-go; j--){
                    if(park[j][y]=='X'){
                        flag = false;
                        break;
                    }
                }
            }else flag = false;
            if(flag) x-=go;
        }
    }
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}