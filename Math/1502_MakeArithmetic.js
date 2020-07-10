var canMakeArithmeticProgression = function(arr) {
    arr.sort(function(a,b){return a-b});
    var temp = arr[1] - arr[0];
    for (var i = 2; i < arr.length; i++) {
        if (arr[i]- arr[i-1] !== temp) return false;
    }
    return true;
};
