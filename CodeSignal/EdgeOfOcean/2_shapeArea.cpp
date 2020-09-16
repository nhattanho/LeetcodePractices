/*
Below we will define an n-interesting polygon. Your task is to find the area of a polygon for a given n.

A 1-interesting polygon is just a square with a side of length 1. An n-interesting polygon is obtained by taking the n - 1-interesting polygon
and appending 1-interesting polygons to its rim, side by side. You can see the 1-, 2-, 3- and 4-interesting polygons in the picture at link.
https://app.codesignal.com/arcade/intro/level-2/yuGuHvcCaFCKk56rJ
Example

    For n = 2, the output should be
    shapeArea(n) = 5;
    For n = 3, the output should be
    shapeArea(n) = 13.
    
    when n = 4
    ==> 2*0 + 1 + 2*1 + 1 + 2*2 + 1 +     2*3 + 1     + 2*2 + 1 + 2*1 + 1 + 2*0 + 1 
    ==> 2(2*0 + 1 + 2*1 + 1 + 2*2 + 1) + 2*3 + 1 
    ==> 2( 2(0+1+2) + 3 ) + 2*3 + 1 <=> 2( 2(1+2+3+...+n-2) + n-1 ) + 2*(n-1) + 1 
    ==> 2(n-1)(n-1) + 2*(n-1) + 1 <==> 2n(n-1) + 1
*/

int shapeArea(int n) {
    return 2*n*(n-1) + 1;
}



