#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    int idx;
    unordered_map<string, int> m;
    
    for(int i=0; i<players.size(); i++){
        m[players[i]] = i;
    }
    
    for(int i=0; i<callings.size(); i++){
        idx = m[callings[i]];
        
        swap(players[idx], players[idx-1]);
        m[players[idx-1]] = idx-1;
        m[players[idx]] = idx;
    }
    
    return players;
}