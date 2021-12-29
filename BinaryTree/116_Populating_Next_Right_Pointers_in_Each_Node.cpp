/*Using BFS with marker*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*>q; /*Space O(n)*/
        Node* marker = new Node(-1001);
        
        q.push(root);
        q.push(marker);
        
        while(!q.empty()){ /*Time O(n)*/
            Node* top = q.front();
            q.pop();
            if(top->val == -1001) continue;
            if(top->left != NULL && top->right != NULL){
                q.push(top->left);
                q.push(top->right);
            }
            
            if(q.front()->val == -1001) {
                top->next = NULL; /*since as a default, the next always is NULL -> no need to point -> see readable option below*/
                q.push(marker);
            }
            else top->next = q.front();
        }
        return root;
    }
};

/*readable code then previous one*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*>q;
        Node* marker = new Node(-1001);
        
        q.push(root);
        q.push(marker);
        
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            if(top->val == -1001) continue;
            if(top->left != NULL && top->right != NULL){
                q.push(top->left);
                q.push(top->right);
            }
            
            if(q.front()->val != -1001)
                top->next = q.front();
            else q.push(marker);
        }
        return root;
    }
};

/*The BFS without using marker*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*>q;/*Space O(n) <=> max #node for specific level, since it is perfect tree <=> N/2 nodes*/
        q.push(root);
        while(!q.empty()){ /*go through every nodes in the tree => Time O(n)*/
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* top = q.front();
                q.pop();
                if(top->left != NULL && top->right != NULL){
                    q.push(top->left);
                    q.push(top->right);
                }
                
                if(i != size-1) top->next = q.front();
            }
        }
        return root;
    }
};

/*Approach without using extra space*/
