/*
record: timestamp and price
used multiple set instead of set since
multiple timestamp may have the same price

For example:
[1 10], [2, 10]

==> use set, only 1 value of 10 will be save
prices [10]

Then next update [1 3]
==> will remove 10 out of prices, and insert 3
==> the new prices [3]
==> max = 3 is wrong, since we still have 10 for timestamp at 2

If we user multiset ==> prices [10 10]
then, after updating [1 3]
==> remove 10, insert 3, then prices [3, 10]
==> max is still equal 10
*/

class StockPrice {
public:
    map<int, int>m;//timestamp, price
    multiset<int>prices;
    
    StockPrice() {}
    
    /*correct the price from any wrong previous record*/
    void update(int timestamp, int price) {
        /*O(logN)*/
        if(m.find(timestamp) != m.end()){
            prices.erase(prices.find(m[timestamp]));
        }
        m[timestamp] = price;
        prices.insert(price);
    }
    
    /*return the latest price <=> latest timestamp <=> max timestamp*/
    /*O(1)*/
    int current() {
       return m.rbegin()->second;
    }
    
    /*O(1)*/
    int maximum() {  
        return *prices.rbegin();
    }
    
    /*O(1)*/
    int minimum() {
        return *prices.begin();
    }
};
