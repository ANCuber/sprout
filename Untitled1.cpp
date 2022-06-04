#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

char letter[26];
int arr[7];
map <unsigned ll, int> mp;
const int m = 1000007;

unsigned ll hs(vector <char> s) {
    unsigned ll ret = 0;
    for (int i = 1; i <= s.size(); ++i) {
        ret += (s[i-1]-'a')*arr[s.size()-i];
        ret %= m;
    }
    return ret;
}


void dfs(int len,vector <char> str) {
    for (int i = 0 ;i < 26; ++i) {
        str.push_back(letter[i]);
        if (len > 1) dfs(len-1,str);
        else {
            for (auto i : str) {
                cout<<i;
            }
            cout<<endl;
        }
        str.pop_back();
    }
}

int main() {
    const int c = 26;
    arr[0] = 1;
    for (int i = 0; i < 26; ++i) letter[i] = 'a'+i;
    for (int i = 1; i < 7; ++i) {
        arr[i] = arr[i-1]*c;
    }
    vector <char> str;
    for (int i = 1; i <= 6; ++i) {
        dfs(i,str);
    }
    return 0;
}