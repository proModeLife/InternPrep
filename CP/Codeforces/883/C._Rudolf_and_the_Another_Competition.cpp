
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<vector<int>> times(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> times[i][j];
            }
            sort(times[i].begin(),times[i].end());
        }
        int points = 0;
        long long penalty = 0;
        long long curr=0;
        for (int i = 0; i < m; i++) {
            curr+=times[0][i];
            if(curr<=h)
            {
                points++;
                penalty += curr;
            }
            else break;
        }
        int place = 1;
        for (int i = 1; i < n; i++) 
        {
            long long currPenalty = 0;
            int currPoints = 0;
            curr=0;
            for (int j = 0; j < m; j++) 
            {
                curr+=times[i][j];
                if(curr<=h)
                {
                    currPoints++;
                    currPenalty += curr;
                }
                else break;
            }
            if (currPoints>points || (currPoints==points &&currPenalty < penalty)) 
                place++;       
        }

        cout << place << endl;
    }

    return 0;
}
