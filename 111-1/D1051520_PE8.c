#include <stdio.h>
#include <stdlib.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);

        int graph[n+1][n+1];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                graph[i][j] = -1;
        
        while(m--){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            graph[u][v] = graph[v][u] = w;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=1; k<=n; k++){
                    if(i == j || i == k || j == k)
                        continue;
                    
                    if(graph[i][k] == -1 && graph[i][j] != -1 && graph[j][k] != -1){
                        graph[i][k] = graph[k][i] = graph[i][j] + graph[j][k];
                    }
                    
                    else if(graph[i][k] > graph[i][j] + graph[j][k]){
                        graph[i][k] = graph[k][i] = graph[i][j] + graph[j][k];
                    }
                }
            }
        }

        int answer = -1;
        //i is virus
        //j is vaccine
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j)
                    continue;

                int infectedMax = 0;
                for(int k=1; k<=n; k++){
                    if(graph[i][k] <= graph[j][k]){
                        infectedMax++;
                    }
                }

                if(answer < infectedMax)
                    answer = infectedMax;
            }
        }

        printf("%d\n", answer);
    }
    return 0;
}
