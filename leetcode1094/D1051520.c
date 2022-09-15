//leetcode 1094. car pooling
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    
    int res[1001] = { 0 };
    
    //people get up at trips[i][1]
    //and people get off at trips[i][2]
    //the other array element are '0'
    //bacause no one get up or get off at those index
    for(int i=0; i<tripsSize; i++){
        res[ trips[i][1] ] += trips[i][0];
        res[ trips[i][2] ] -= trips[i][0];
    }
    
    int sum = 0;
    
    for(int i=0; i<=1000; i++){
        sum += res[ i ];
        
        if(sum > capacity)
            return false;
    }
    return true;
}
