// In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (Buy->sell->Buy->sell). The stock prices throughout the day are represented in the form of an array of prices. 
// Given an array price of size N, find out the maximum profit that a share trader could have made.

// Solution:

int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    int first_buy[price.size()];
    int second_buy[price.size()];
    
    int min_cost_so_far = INT_MAX;
    int max_profit = 0;
    
    for(int i = 0; i<n; i++) {        // traversing from left to right
        if(i == 0) {
            min_cost_so_far = price[i];
            first_buy[i] = max_profit;
            continue;
        }
        
        min_cost_so_far = min(price[i], min_cost_so_far);
        max_profit = max(max_profit, price[i] - min_cost_so_far);
        first_buy[i] = max_profit;
    }
    
    int max_selling_price_so_far = INT_MIN;
    max_profit = 0;
    
    for(int i = n-1; i>=0; i--) {          // traversing from right to left
        if(i == n-1) {
            max_selling_price_so_far = price[i];
            max_profit = 0;
            second_buy[i] = max_profit;
            continue;
        }
        
        max_selling_price_so_far = max(max_selling_price_so_far, price[i]);
        max_profit = max(max_selling_price_so_far - price[i], max_profit);
        second_buy[i] = max_profit;
    }
    
    int final_profit = INT_MIN;
    
    for(int i = 0; i<n; i++) {
        final_profit = max(final_profit, first_buy[i] + second_buy[i]);
    }
    
    return final_profit;
}