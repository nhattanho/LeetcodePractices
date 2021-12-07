/*
Each directory name consists of letters, digits, and/or spaces.
file name is of the form name.extension, where name and extension consist of letters, digits, and/or spaces.
we will never have this testcase:
"\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2"

Split the string by \n, then realized that the number of tab will indicate the level of the folder in the path
For every element after splitting, check for #tab and update the maximum len. Then, if the element contains '.'
==> it is a file ==> we need to update the maximum len. Otherwise, it is a folder that we dont need to check
==> go to the next element.
*/


class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);
        string token = "";
        int res = 0;
        unordered_map<int, int>len;
        
        while(getline(ss, token, '\n')){
            int pos = token.find_last_of('\t');
            
            if(pos == string::npos){
                //root dir
                len[0] = token.size();
            }else{
                /*We can do more steps for easier to read*/
                /*
                token = token.substr(pos+1);
                len[pos+1] = len[pos] + 1 + token.length(); 
                //+1 for slash between two levels
                */
                len[pos+1] = len[pos] + token.length() - pos;
            }
            
            if(token.find('.') != string::npos){
                /*"file1.txt\nfile2.txt\nlongfile.txt"*/
                if(pos == string::npos)
                    res = max(res, len[0]);
                else
                    res = max(res, len[pos+1]);
            }
        }
        return res;
    }
};


