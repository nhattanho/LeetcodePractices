Contiguous Subarrays
You are given an array arr of N integers. For each index i, you are required to determine the number of contiguous subarrays that fulfill the following conditions:

    The value at index i must be the maximum element in the contiguous subarrays, and
    These contiguous subarrays must either start from or end on index i.

Signature
int[] countSubarrays(int[] arr)
Input

    Array arr is a non-empty list of unique integers that range between 1 to 1,000,000,000
    Size N is between 1 and 1,000,000

Output
An array where each index i contains an integer denoting the maximum number of contiguous subarrays of arr[i]
Example:
arr = [3, 4, 1, 6, 2]
output = [1, 3, 1, 5, 1]
Explanation:

    For index 0 - [3] is the only contiguous subarray that starts (or ends) with 3, and the maximum value in this subarray is 3.
    For index 1 - [4], [3, 4], [4, 1]
    For index 2 - [1]
    For index 3 - [6], [6, 2], [1, 6], [4, 1, 6], [3, 4, 1, 6]
    For index 4 - [2]
    
vector <int> CountSubarrays(vector <int> arr) {
  /*value, index*/
  stack<pair<int,int>>st;
  int s = arr.size();
  
  /* save the number of the values less or equal than a specific postion
  so if at index 4, has two less then number ==> has three sub array included it self
  [0] [1] [2] [3] [4] [5]
   10  9   4   5   6   7
   ==> 4 5 6, 5 6, 6 */
  vector<int> l(s, 0);
  
  for (int i = 0; i < s; i++){
    if(st.empty()){
      l[i] = i+1;
      //st.push({arr[i], i});
    }else{
      while(!st.empty()){
        if(arr[i] > st.top().first){
          st.pop();
        }else break;
      }
      if(st.empty()) l[i] = i+1;
      else {
        l[i] = i - st.top().second;
      }
      //st.push({arr[i], i});
    }
    st.push({arr[i], i});
  }
  
  while(!st.empty()) st.pop();
  
  for (int i = s-1; i >= 0; i--){
    if(st.empty()){
      l[i] += abs(i-s) - 1;
    }else{
      while(!st.empty()){
        if(arr[i] > st.top().first){
          st.pop();
        }else break;
      }
      if(st.empty()) l[i] += abs(i-s) - 1;
      else {
        l[i] += abs(i - st.top().second) - 1;
      }
    }
    st.push({arr[i], i});
  }
  
  return l;
}


/*Optimal Solution*/
vector <int> CountSubarrays(vector <int> arr) {
  /*value, index*/
  stack<pair<int,int>>st;
  int s = arr.size();
  
  /* save the number of the values less or equal than a specific postion
  so if at index 4, has two less then number ==> has three sub array included it self
  [0] [1] [2] [3] [4] [5]
   10  9   4   5   6   7
   ==> 4 5 6, 5 6, 6 */
  vector<int> l(s, 0);
  for(int i = 0; i < s; i++){
    while(!st.empty() && arr[i] > st.top().first){
      st.pop();
    }
    if(st.empty()) l[i] = i+1;
    else l[i] = i - st.top().second;
    st.push({arr[i], i});
  }
  while(!st.empty()) st.pop();
  for(int i = s-1; i >= 0; i--){
    while(!st.empty() && arr[i] > st.top().first){
      st.pop();
    }
    if(st.empty()) l[i] += abs(i - s) - 1;
    else l[i] += abs(i - st.top().second) - 1;
    st.push({arr[i], i});
  }
 
  return l;
}

/*More optimal*/
void getList(int start, int end, bool leftSide, vector<int> arr, vector<int>& l){
  /*value, index*/
  stack<pair<int,int>>st;
  for(int i = start; (leftSide)?(i < end):(i>=0); (leftSide)?(i++):i--){
    while(!st.empty() && arr[i] > st.top().first){
      st.pop();
    }
    if(st.empty()) {
      l[i] += abs(i-start);
      if(leftSide) l[i] += 1;
    }
    else {
      l[i] += abs(i - st.top().second);
      if(!leftSide) l[i] -= 1;
    }
    st.push({arr[i], i});
  }
}

vector <int> CountSubarrays(vector <int> arr) {
  int s = arr.size();
  vector<int> l(s, 0);
  getList(0, s, true, arr, l);
  getList(s-1, 0, false, arr, l);
  return l;
}
