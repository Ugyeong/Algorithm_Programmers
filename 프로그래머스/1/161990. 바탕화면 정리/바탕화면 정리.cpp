#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux, luy = 51, rdx, rdy = -1;
    int x, y;
    bool first = true;
    
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[0].size(); j++){
            if(wallpaper[i][j]=='#'){
                x = i;
                y = j;
                if(first){
                    lux = x;
                    first = false;
                }
                if(y<luy) luy = y;
                if(y>rdy) rdy = y;
            }
        }
    }
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(x+1);
    answer.push_back(rdy+1);
    
    return answer;
}