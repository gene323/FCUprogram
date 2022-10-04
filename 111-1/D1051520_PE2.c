#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv){
    FILE *file = fopen("D1051520_PE2.csv", "w+");

    srand(time(NULL));

    const int N = atoi(argv[1]);
    const int M = atoi(argv[2]);
    const int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1},
        {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int count[N][M];
    int bug[2] = {atoi(argv[3]), atoi(argv[4])};
    int move = 0;
    int grid = N * M - 1;

    //Error range stop the program
    if(N < 3 || N > 40 || M < 2 || M > 20){
        printf("2<n<=40, 2<=m<=20\n");
        printf("Your N:%d, M:%d", N, M);
        return 0;
    }
    //initialize count array
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            count[i][j] = 0;
    
    count[bug[0]][bug[1]] = 1;

    for(int k=0; k<50000; k++){
        int num = rand() % 8;
        //determine whether collide the border
        while(bug[0] + dir[num][0] < 0
            || bug[0] + dir[num][0] >= N
            || bug[1] + dir[num][1] < 0
            || bug[1] + dir[num][1] >= M){

            num = rand() % 8;
        }

        bug[0] += dir[num][0];
        bug[1] += dir[num][1];
        move++;

        if(count[bug[0]][bug[1]] == 0)
            grid--;

        count[bug[0]][bug[1]] += 1;

        //represents all the grids are walked
        if(grid == 0)
            break;
    }

    //print to .csv file
    fprintf(file, "The total number of moves = %d\n", move);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            fprintf(file, "%d%c", count[i][j],
                    (j == M - 1)? '\n': ',');
        }
    }

    fclose(file);
    return 0;
}
