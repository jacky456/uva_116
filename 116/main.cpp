#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <queue>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;

void printPath(vector<vector<int>> &mat);

int main() {
    string str;
    int row, col;
    while (cin >> row >> col){
        vector<vector<int>> mat;

        for (int i = 0; i < row; i++){
            vector<int> rvec;
            for (int j = 0; j < col; j++){
                int k;
                cin >> k;
                rvec.push_back(k);
            }
            mat.push_back(rvec);
        }

        printPath(mat);
    }

    return 0;
}

void printPath(vector<vector<int>> &mat){
    vector<vector<int>> minM;
    vector<int> rvec (mat[0].size(), INT_MAX);
    minM.reserve(mat.size());
    for (int i = 0; i < mat.size(); i++)
        minM.push_back(rvec);

    for (int i = 0; i < mat.size(); i++)
        minM[i][mat[0].size()-1] = mat[i][mat[0].size()-1];

    for (int j = int(mat[0].size()-2); j >= 0; j--){
        for (int i = 0; i < mat.size(); i++){
            int size = int(mat.size());
            if (mat[i][j] + minM[(i-1+size) % size][j+1] < minM[i][j])
                minM[i][j] = mat[i][j] + minM[(i-1+size) % size][j+1];

            if (mat[i][j] + minM[(i+1) % size][j+1] < minM[i][j])
                minM[i][j] = mat[i][j] + minM[(i+1) % size][j+1];

            if (mat[i][j] + minM[i][j+1] < minM[i][j])
                minM[i][j] = mat[i][j] + minM[i][j+1];
        }
    }

    int smallest = INT_MAX;
    int idx = 0;
    for (int i = 0; i < minM.size(); i++)
        if (minM[i][0] < smallest){
            smallest = minM[i][0];
            idx = i;
        }

    queue<int> path;
    path.push(idx+1);
    int size = int(mat.size());
    for (int j = 1; j < minM[0].size(); j++){
        int s, m, l;

        s = min((idx-1+size) % size, min((idx+1) % size, idx));
        l = max((idx-1+size) % size, max((idx+1) % size, idx));
        m = (idx-1+size) % size + (idx+1) % size + idx - s - l;

        int small = min(minM[s][j], min(minM[m][j], minM[l][j]));

        if (minM[s][j] == small)
            idx = s;
        else if (minM[m][j] == small)
            idx = m;
        else if (minM[l][j] == small)
            idx = l;

        path.push(idx+1);
    }

    int isfront = 1;
    while(!path.empty()){
        if(!isfront)
            cout << " ";
        int node = path.front();
        path.pop();
        cout << node;
        isfront = 0;
    }
    cout << endl;
    cout << smallest << endl;

}