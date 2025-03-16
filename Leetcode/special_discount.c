int* finalPrices(int* prices, int pricesSize, int* returnSize) {

    int* answer = (int*)malloc(pricesSize * sizeof(int));
    
    for(int i = 0; i < pricesSize; i++){

        answer[i] = prices[i];

        for(int j = i + 1; j < pricesSize; j++){

            if(prices[j] <= prices[i]){
                answer[i] = prices[i] - prices[j];
                break;
            }
        }

    }
    *returnSize = pricesSize;
    return answer;
}