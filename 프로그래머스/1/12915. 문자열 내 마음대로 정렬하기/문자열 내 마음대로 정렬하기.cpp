#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int nn;

bool compare(string a, string b){
    if(a[nn]==b[nn]) return a<b;
    else return a[nn]<b[nn];
}

vector<string> solution(vector<string> strings, int n) {
    nn = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}