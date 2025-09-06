#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y, dist;
} Node;

int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    int visited[100][100] = {0};

    Node queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = (Node){startX,startY,0};
    visited[startX][startY] = 1;

    while(front < rear){
        Node cur = queue[front++];
        if(cur.x == goalX && cur.y == goalY) return cur.dist;

        for(int d=0; d<4; d++){
            int nx = cur.x;
            int ny = cur.y;
            while(1){
                nx += dx[d];
                ny += dy[d];
                if(nx<0 || nx>=grid_count || ny<0 || ny>=grid_count || grid[nx][ny]=='X') break;
                if(!visited[nx][ny]){
                    visited[nx][ny]=1;
                    queue[rear++] = (Node){nx,ny,cur.dist+1};
                }
            }
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d\n",&n);
    char** grid = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        grid[i] = malloc((n+1)*sizeof(char));
        fgets(grid[i], n+2, stdin);
        if(grid[i][strlen(grid[i])-1]=='\n') grid[i][strlen(grid[i])-1]='\0';
    }

    int startX, startY, goalX, goalY;
    scanf("%d %d %d %d",&startX,&startY,&goalX,&goalY);

    int res = minimumMoves(n,grid,startX,startY,goalX,goalY);
    printf("%d\n", res);

    for(int i=0;i<n;i++) free(grid[i]);
    free(grid);
    return 0;
}
