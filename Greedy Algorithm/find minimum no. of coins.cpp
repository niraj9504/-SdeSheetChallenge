int findMinimumCoins(int amount) 
{
    vector<int> coins={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int cns=0,i=8;
    while(amount && i>=0){
        if(amount/coins[i]>0){
            cns+=amount/coins[i];
            amount-=(coins[i])*(amount/coins[i]);
        }
        i--;
    }
    return cns;
}
