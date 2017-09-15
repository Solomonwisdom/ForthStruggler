////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-08-03 15:15:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define M 7
#define N 7
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
char maze[M][N];
int DFS (char maze[M][N], int m, int n, int x, int y, int xd, int yd, int t)
{
    char o;

    if (!t && xd == x && yd == y) return 1;
    if (t <= 0 || t < ABS(xd - x) + ABS(yd - y)) return 0;
    o = maze[x][y];
    maze[x][y] = 'X';
    if (x > 0 && 'X' != maze[x - 1][y] && DFS (maze, m, n, x - 1, y, xd, yd, t - 1)) {
        return 1;
    }
    if (x < m - 1 && 'X' != maze[x + 1][y] && DFS (maze, m, n, x + 1, y, xd, yd, t - 1)) {
        return 1;
    }
    if (y > 0 && 'X' != maze[x][y - 1] && DFS (maze, m, n, x, y - 1, xd, yd, t - 1)) {
        return 1;
    }
    if (y < n - 1 && 'X' != maze[x][y + 1] && DFS (maze, m, n, x, y + 1, xd, yd, t - 1)) {
        return 1;
    }
    maze[x][y] = o;
    return 0;
}
int main (void)
{
    int m, n, t;
    int i, j, xs, ys, xe, ye;

    while (EOF != scanf ("%d%d%d", &m, &n, &t) && m + n + t) {
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                do {
                    scanf ("%c", &maze[i][j]);
                } while ('S' != maze[i][j] && 'D' != maze[i][j] && '.' != maze[i][j] && 'X' != maze[i][j]);
                if ('S' == maze[i][j]) {
                    xs = i; ys = j;
                } else if ('D' == maze[i][j]) {
                    xe = i; ye = j;
                }
            }
        }
        if (!((ABS(xe - xs) + ABS(ye - ys) - t) & 1) && DFS (maze, m, n, xs, ys, xe, ye, t)) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}