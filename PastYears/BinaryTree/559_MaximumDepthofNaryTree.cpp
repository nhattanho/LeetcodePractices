/* Using BFS with time complexity O(n), space O(n) */
class Solution {
public:
    int count = 0;
    queue<Node*>q;
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int sizeq = q.size();
            while(sizeq > 0){
                Node* temp = q.front();
                q.pop();
                sizeq--;
                int size = temp->children.size();
                for(int i = 0; i < size; i++) q.push(temp->children[i]);
            }
            count++;
        }
        return count;
    }
};

/* Using DFS with time Complexity O(n), space O(n) */
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int size = root->children.size();
        if(size == 0) return 1;
        vector<int>saveLev(size,0);
        for(int i = 0; i < size; i++){
            saveLev.push_back(maxDepth(root->children[i]));
        }
        int maxlev = *max_element(saveLev.begin(), saveLev.end());
        return maxlev+1;
    }
};

/* ==> Optimize DFS */
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int size = root->children.size();
        if(size == 0) return 1;
        int maxlev = 0;
        for(int i = 0; i < size; i++)
            maxlev = max(maxDepth(root->children[i]), maxlev);
        return maxlev+1;
    }
};
