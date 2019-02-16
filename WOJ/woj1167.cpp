/*
Name:
Copyright:
Author:
Date: 04/01/16 03:34
Description: woj1167
深度搜索，X、Y被弄反了，调了很久，囧
*/
#include<iostream>
#include<stdio.h>
using namespace std;
#pragma warning(disable:4996)
int r, c;
int dx[8] = { 0, 1, -1, 1, -1, 0, -1, 1 };
int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int nextX, nextY;
char matrix[100][100];
void Dfs(int x, int y)
{
    if (x<c&&x >= 0 && y<r&&y >= 0)
    {
        if (matrix[y][x] == 'O')
        {
            matrix[y][x] = 'X';
            for (int i = 0; i<8; i++)
            {
                nextX = x + dx[i];
                nextY = y + dy[i];
                Dfs(nextX, nextY);
            }
        }
        else return;
    }
    else return;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int count;
    while (cin >> r >> c&&r != 0 && c != 0)
    {
        count = 0;
        for (int i = 0; i<r; ++i)
        {
            for (int j = 0; j<c; ++j)
            {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i<r; ++i)
        {
            for (int j = 0; j<c; ++j)
            {
                if (matrix[i][j] == 'O')
                {
                    count++;
                    Dfs(j,i);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}