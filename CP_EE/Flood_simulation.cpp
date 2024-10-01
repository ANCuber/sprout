#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

float Elevation[50][50] = {
{0,0,0,0,1,1,1,1,1,2,2,2,2,2,2,3,3,4,4,3,3,3,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1},
{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,3,3,4,4,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1},
{0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,3,3,3,3,3,3,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,2,2,2,3,3,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
{1,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
{1,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1},
{1,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1},
{1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
{1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2},
{1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2},
{1,1,1,1,0,0,0,0,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{1,1,1,1,0,0,0,0,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
{1,1,1,1,0,0,0,0,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
{1,1,1,1,0,0,0,0,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4},
{1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,3,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,4,4,4,4,4,4,4,5,5,5,5},
{1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,3,3,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5},
{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,3,3,3,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5},
{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,3,3,3,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5},
{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,6,6,6,6,7,7,8,9},
{1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,5,5,5,5,6,6,6,6,6,6,7,7},
{1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5},
{1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5},
{1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4},
{1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4},
{2,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4},
{2,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4},
{2,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,4},
{2,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4},
{2,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3},
{2,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
{2,2,2,2,2,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3},
{2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3},
{2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3},
{2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3},
{3,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3},
{3,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3},
{2,2,2,3,3,3,3,3,3,3,3,2,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3},
{2,2,2,3,3,3,3,3,3,3,2,2,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3},
{2,2,2,3,3,3,3,4,3,3,2,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3},
{2,2,2,3,3,3,3,3,3,3,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3},
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout<<"Please enter how many hour(s) will the rain last:"<<endl;
    int prd; cin>>prd;
    vector<vector<double> > wtr(55, vector<double>(55,0)), dw(55,vector<double>(55,0)), ele(55,vector<double>(55,2e9));
    for (int i = 1; i <= 50; ++i) for (int j = 1; j <= 50; ++j) ele[i][j] = Elevation[i-1][j-1];
    ele[0][0] = ele[0][1] = ele[0][2] = ele[0][3] = ele[0][4] = ele[1][0] = ele[2][0] = ele[3][0] = ele[4][0] = 0;
    int hrs = 0, flg = 1;
    while(true) {
        if (++hrs <= prd) {
            for (int i = 1; i <= 50; ++i) {
                for (int j = 1; j <= 50; ++j) {
                    wtr[i][j] += 1.0;
                }
            }
        }
        for (int i = 0; i <= 51; ++i) for (int j = 0; j <= 51; ++j) dw[i][j] = 0;
        for (int i = 1; i <= 50; ++i) {
            for (int j = 1; j <= 50; ++j) {
                for (int k = 0; k < 4; ++k) {
                    double cur = max(0.0,min(wtr[i][j]+ele[i][j]-wtr[i+dx[k]][j+dy[k]]-ele[i+dx[k]][j+dy[k]],wtr[i][j]))/4.0;
                    //double cur = min(max(wtr[i][j]+ele[i][j]-wtr[i+dx[k]][j+dy[k]]-ele[i+dx[k]][j+dy[k]],0.0),wtr[i][j])/4.0;
                    dw[i][j] -= cur;
                    dw[i+dx[k]][j+dy[k]] += cur;
                }
            }
        }
        flg = 1;
        for (int i = 1; i <= 50; ++i) {
            for (int j = 1; j <= 50; ++j) {
                wtr[i][j] += dw[i][j];
                if (Elevation[i-1][j-1] && wtr[i][j] >= 0.1) flg = 0;
            }
        }
        if (flg) break;
    }
    cout<<"It takes "<<hrs<<" hour(s) until all water level (excluding river) is less than 1cm higher than the elevation."<<endl;
    return 0;
}
