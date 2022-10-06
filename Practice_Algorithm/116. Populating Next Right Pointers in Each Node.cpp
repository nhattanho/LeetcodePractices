class Solution {
public:
    Node* connect(Node* root) {
        Node *move = root;
        while(move != NULL){
            Node *level = move;
            /*this loop checks for specific level*/
            while(level != NULL && level->left != NULL && level->right != NULL){
                /*First connection for children has the same parent*/
                level->left->next = level->right;
                /*Second connnection for children has different parent but their parent has same level*/
                if(level->next!=NULL){
                    level->right->next = level->next->left;
                }
                level = level->next;
            }
            move = move->left;
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* top = q.front();
                q.pop();
                if(i == size-1) top->next = NULL;
                else top->next = q.front();
                if(top->left != NULL) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* level = root, *move = root;
        if(root == NULL) return NULL;
        
        while(level->left){
            move = level;
            while(move){
                if(move->left){
                    move->left->next = move->right;
                }
                if(move->next)
                    move->right->next = move->next->left;
                move = move->next;
            }
            level = level->left;   
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* level = root, *move = root;
        if(root == NULL) return NULL;
        
        while(level->left){
            move = level;
            while(move){
                move->left->next = move->right;
                if(move->next)
                    move->right->next = move->next->left;
                move = move->next;
            }
            level = level->left;   
        }
        return root;
    }
};
