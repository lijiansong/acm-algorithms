#include <iostream> 
#include <cstring>
#include <iterator>
#include <vector>
#include <cstdio>
using namespace std;

struct Frame
{
    int x1, y1;
    
    int x2, y2;
    

    Frame()
    {
        x1 = y1 = 100;
        
        x2 = y2 = -100;
    }
};
bool used[26];

int into[26];


int map[26][26];
char matrix[32][32];

vector<char> ans;


void buildMap(Frame frame[])
{
    for (int i = 0; i < 26; ++i)
    {
      
        if (used[i])
        {
            
            for (int j = frame[i].x1; j <= frame[i].x2; ++j)
            {
                if (matrix[j][frame[i].y1] != i+'A')
                {
                          if (map[i][matrix[j][frame[i].y1]-'A'] == 0)
                    {
                      
                        into[matrix[j][frame[i].y1]-'A']++;
                    
                        map[i][matrix[j][frame[i].y1]-'A'] = 1;
                    }
                }
                if (matrix[j][frame[i].y2] != i+'A')
                {
                    if (map[i][matrix[j][frame[i].y2]-'A'] == 0) 
                    {
                        into[matrix[j][frame[i].y2]-'A']++;
                    
                        map[i][matrix[j][frame[i].y2]-'A'] = 1;
                    }
                }
            }

            for (int j = frame[i].y1; j <= frame[i].y2; ++j)
            {
                if (matrix[frame[i].x1][j] != i+'A')
                {
                    if (map[i][matrix[frame[i].x1][j]-'A'] == 0)
                    {
                        into[matrix[frame[i].x1][j]-'A']++;
                    
                        map[i][matrix[frame[i].x1][j]-'A'] = 1;
                    }
                }
                if (matrix[frame[i].x2][j] != i+'A')
                {
                    if (map[i][matrix[frame[i].x2][j]-'A'] == 0)
                    {
                        into[matrix[frame[i].x2][j]-'A']++;
                    
                        map[i][matrix[frame[i].x2][j]-'A'] = 1;
                    }
                }
            }
        }
    }
}    

void topo(int depth, int count)
{

    if (depth >= count)
    {
        copy(ans.begin(), ans.end(), ostream_iterator<char>(cout));
        
        cout << endl;
        
        return;
    }
    
    for (int i = 0; i < 26; ++i)
    {
        if (used[i])
        {
            if (into[i] == 0)    
            {

                ans.push_back(i+'A');
            
                into[i] = -1;
                
                for (int k = 0; k < 26; ++k)
                {
                    if (map[i][k] == 1)
                    {    
                        into[k]--;
                    }
                }
                
                topo(depth+1, count);
                
                
                ans.pop_back();
                
                into[i] = 0;
                
                for (int k = 0; k < 26; ++k)
                {
                    if (map[i][k] == 1)
                    {    
                        into[k]++;
                    }
                }                
            }
        }
    }
}

int main()
{
    int n, m;
    
    while (scanf("%d",&n) != EOF)
    {
        cin >> m;
        
        memset(used, 0, sizeof(used));
        
        memset(into, 0, sizeof(into));
        
        memset(map, 0, sizeof(map));
        
        memset(matrix, 0, sizeof(matrix));
        
        Frame frame[26];
        
        ans.clear(); 
        
        string temp;
        
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            for (int j = 0; j < m; ++j)
            {
                matrix[i][j] = temp[j];
                
                if (matrix[i][j] != '.')
                {
                    int toNum = matrix[i][j]-'A';
                    
                    used[toNum] = true;
                    
                    if (frame[toNum].x1 > i) frame[toNum].x1 = i;
                    if (frame[toNum].y1 > j) frame[toNum].y1 = j;
                    if (frame[toNum].x2 < i) frame[toNum].x2 = i;
                    if (frame[toNum].y2 < j) frame[toNum].y2 = j;
                }
            }
        }
        
        buildMap(frame);

        
        int count = 0;
        
        for (int i = 0; i < 26; ++i)
            if (used[i])
                count++;
        
        topo(0, count); 
    }
}