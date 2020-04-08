class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        string mutation = "ACGT";
        vector<string>::iterator it;
        queue<pair<string, int>>qsave; //string, count
        qsave.push({start,0});
        while(qsave.size() != 0){
            pair<string, int>pset = qsave.front();
            qsave.pop();//pset.second is saving the number of mutation
            string word = pset.first;
            if(word == end) return pset.second;
            //Finding mutation by changing, checking each character
            for(int i = 0; i < 8; i++){
                char backup = word[i];
                for(auto x: mutation){
                    word[i] = x;
                    it = find(bank.begin(), bank.end(), word);
                    if(it != bank.end()){
			//Found the mutation ==> saving for the next checking
			//If we have two mutation, first is A and then is B.
			//Assume both of them have the same target "end",
			//that means A or B has just only one different
			//character with end,==> with this checking operation,
			//A has to have the shorter path to reach the target
			//than B, so that why we're using queue to save them.
			//As the result, in the next checking, A comes to first
			//and we will have the shortest path to the end or we
			//have the minimum genetic mutation. 
                        qsave.push({word,pset.second+1});
                        bank.erase(it);
                    }
                    word[i] = backup;
                } 
            }
        }
        return -1;
    }
};
