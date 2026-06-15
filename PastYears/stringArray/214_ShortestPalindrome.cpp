/*Naive solution*/
string shortestPalindrome(string s) {
    int n = s.length();
    string rev(s);
    reverse(rev.begin(), rev.end());
    for(int i = 0; i < n; i++){
        if(s.substr(0, n-i) == rev.substr(i))
            return rev.substr(0,i)+s;
    }
    return "";
}

/*Better performance by using KMP Algorithm*/
string shortestPalindrome(string s) {
    string rev(s);
    reverse(rev.begin(), rev.end());
    string s_new = s + "+" + rev;
    int size = s_new.size();
    vector<int> f(size, 0);
    /*j used to count the length of longest prefix that equal suffix
    of the string having the length from 0 to i*/
    for (int i = 1, j = 0; i < size; i++) {
        while (j > 0 && s_new[i] != s_new[j])
            j = f[j - 1];
        if (s_new[i] == s_new[j])
            j++;
        f[i] = j;
    }
    return rev.substr(0, s.size() - f[size - 1]) + s;
}
