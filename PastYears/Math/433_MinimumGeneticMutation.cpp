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
			/*Found the mutation ==> saving for the next checking*/
			//If we have two mutation, first is start->A and the
			//second is start->B.Because A and B are different, and
			//they also have only one different character with the
			//start gene, so A and B have to have at 2 different
			//character.Now, we need to find how many mutation from
			//A->end and B->end. To find the minimum of mutations, we
			//do the sequential operation for A and B. Whenever
			//A or B reaches the end, the minimum of mutations will base
			//on the number of step from A or B to the end.
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
/* For example:
 * start: AACCGGTT
 * end  : AACCGGCA
 *
 * bank : AACCGGTA, AACCGCTT, AACCGGCA, AACCGCTA, AACCGCCA
 *
 * first:  start = AACCGGTT -> AACCGCTT (A)
 *                      `           `
 * second: start = AACCGGTT -> AACCGGTA (B)
 *                        `           `
 * Continue checking for A and B, we will have:
 * A: AACCGCTT -> AACCGCTA (C)
 *
 * B: AACCGGTA -> AACCGCTA (C)
 * B: AACCGGTA -> AACCGGCA (D)
 * We can see B can connect to 2 mutation, however, if A and B
 * have the same mutation for C, they will have the same steps
 * to go to the end, so that why whenever A get one mutation, we
 * don't need to check it for B again, so we can delete C from the
 * bank when C was found by A. Then we only check B for D. As a result,
 * we continue checking for C and D and so on. Finally, we can simulate
 * the analysis:
 *       A(1) --> C(2)                 --> AA CC GC CA(3)     --> AA CC GG CA ==> len = 4
 *      /
 * start
 *      \
 *       B(1)     --> D(2) = AA CC GG CA (END) ==> len: 2
 *
 * So, the process must be run alterantely between A and B to continuously check the
 * minimum steps, and then we come up with queue to do this process*/
