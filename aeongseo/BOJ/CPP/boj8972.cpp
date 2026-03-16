/*** 8972. 미친 아두이노 ***/

#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

const int INF = 1e8;

struct Point { int i, j; };

void init();
void moveI(int od);
Point moveR(int ti, int tj);

int R, C;
Point pointI;
vector<Point> pointR;
vector<vector<char>> grid;
bool bomb = false;

int di[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dj[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    grid.assign(R, vector<char>(C));
    init();

    string line;
    cin >> line;
    for (int c = 0; c < line.size(); c++){
        int od = line[c] - '0';

        moveI(od);
        if(bomb) {
            cout << "kraj " << c + 1;
            return 0;
        }

        vector<vector<int>> next_grid(R, vector<int>(C, 0));
        vector<Point> next_pointR;

        for(Point &p : pointR){
            Point np = moveR(p.i, p.j);
            
            if(np.i == pointI.i && np.j == pointI.j){
                cout << "kraj " << c + 1;
                return 0;
            }
            next_grid[np.i][np.j]++;
        }

        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                grid[i][j] = '.';
            }
        }
        grid[pointI.i][pointI.j] = 'I';
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if(next_grid[i][j] == 1){
                    grid[i][j] = 'R';
                    next_pointR.push_back({i, j});
                }
            }
        }
        pointR = next_pointR;
    }

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}

void init(){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'I') pointI = {i, j};
            if(grid[i][j] == 'R') pointR.push_back({i, j});
        }
    }
}

void moveI(int od){
    grid[pointI.i][pointI.j] = '.';
    pointI = {pointI.i + di[od], pointI.j + dj[od]};
    if(grid[pointI.i][pointI.j] == '.') grid[pointI.i][pointI.j] = 'I';
    else bomb = true;

}

Point moveR(int ti, int tj){
    int mind = INF;
    Point pointN;

    for (int d = 1; d < 10;d++){
        if(d == 5) continue;

        int ni = ti + di[d];
        int nj = tj + dj[d];
        int dist = abs(pointI.i - ni) + abs(pointI.j - nj);

        if(dist < mind){
            mind = dist;
            pointN.i = ni;
            pointN.j = nj;
        }
    }

    return pointN;
}