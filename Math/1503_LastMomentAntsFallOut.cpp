/*  Two ants moving in two different directions meet at some point, they change their directions and continue moving again
<=> they move and pass through each others, we can simulation like:
T:   0s   0         1         2         3         4         5         6         7         8         9
ants:               a>        b>        c>                  <d        <e
                    ----------------------                  ------------  

     1s   0         1         2          3         4         5        6         7         8         9
ants:                         a>         b>        <c       <e         //c and d have changed direction already by colliding
                                                   d> 

    1.5s   0         1         2          3         4         5        6         7         8         9
ants:                               a>         <b        e>           // b and c have changed direction
                                               c>        <d           // d and e have changed direciton
                                               
      2s   0         1         2          3         4         5        6         7         8         9
ants:                                     <a        <c        e>      // a and b have changed 
                                          b>        d>                // d and c have changed  
                                          
     2.5s   0         1         2          3         4         5        6         7         8         9
ants:                                 <a        c>                 e>  // c and b have changed 
                                                <b        d>               

       3s   0         1         2          3         4         5        6         7         8         9
ants:                           <a         <b        c>        d>       e>  
                                --------------       ---------------------        
                                
So, if we assume they go and pass through each other, the graph will be like :

      3s    0        1         2          3         4         5        6         7         8         9
ants                           <d         <e        a>        b>       c>
                               ------------          ---------------------
Because all of the ants are the same, so the ants do not matter; we just focus on the number of ants go to the left and right direction. */
                               
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0, maxRight = 0;
        for (auto x:left) {
            maxLeft = max(maxLeft, x);
        }
        for(auto x:right) {
            maxRight = max(maxRight, n-x);
        }
        return max(maxLeft, maxRight);
    }
};

//==> improving code
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (auto x:left) ans = max(ans, x);
        for(auto x:right) ans = max(ans, n-x);
        return ans;
    }
};
