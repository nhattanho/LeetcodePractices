/*Classic way*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){/*Space <=> length of q <=> diameter of tree*/
            int size = q.size();
            for(int i = 0; i < size; i++){ /*O(n), n is #node in tree*/
                Node *top = q.front();
                q.pop();
                if(top->left != NULL)
                    q.push(top->left);
                if(top->right != NULL)
                    q.push(top->right);
                if(i != size-1) top->next = q.front();
            }
        }
        return root;
    }
};

/*Approach with no using extra memory*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        Node *left_node = root;
        while(true){
            if(left_node != NULL){
                Node *move = left_node;
                while(move != NULL){
                    if(move->left != NULL && move->right != NULL){
                        move->left->next = move->right;
                        if(move->next != NULL){
                            if(move->next->left != NULL){
                                move->right->next = move->next->left;
                            }else if(move->next->right != NULL){
                                move->right->next = move->next->right;
                            }else{
                                Node *run = move->next;
                                while(run != NULL && run->left == NULL && run->right == NULL){
                                    run = run->next;
                                }
                                if(run != NULL && run->left != NULL) move->right->next = run->left;
                                else if(run != NULL && run->right != NULL) move->right->next = run->right;
                            }
                        }
                    } else if(move->left == NULL && move->right != NULL){
                        if(move->next != NULL){
                            if(move->next->left != NULL){
                                move->right->next = move->next->left;
                            }else if(move->next->right != NULL){
                                move->right->next = move->next->right;
                            }else{
                                Node *run = move->next;
                                while(run != NULL && run->left == NULL && run->right == NULL){
                                    run = run->next;
                                }
                                if(run != NULL && run->left != NULL) move->right->next = run->left;
                                else if(run != NULL && run->right != NULL) move->right->next = run->right;
                            }
                        }
                    }else if(move->left!=NULL && move->right == NULL){
                        if(move->next != NULL){
                            if(move->next->left != NULL){
                                move->left->next = move->next->left;
                            }else if(move->next->right != NULL){
                                move->left->next = move->next->right;
                            }else{
                                Node *run = move->next;
                                while(run != NULL && run->left == NULL && run->right == NULL){
                                    run = run->next;
                                }
                                if(run != NULL && run->left != NULL) move->left->next = run->left;
                                else if(run != NULL && run->right != NULL) move->left->next = run->right;
                            }
                        }
                    }
                    
                    move = move->next;
                }
            }
            if(left_node->left != NULL)
                left_node = left_node->left;
            else if(left_node->right != NULL)
                left_node = left_node->right;
            else left_node = left_node->next;
            if(left_node == NULL) break;
        }
        return root;
    }
};
/*More readable 1*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        Node *left_node = root;
        while(true){
            if(left_node != NULL){
                Node *move = left_node;
                while(move != NULL){
                    if(move->left == NULL && move->right == NULL){
                        move = move->next;
                        continue;
                    }
                    Node *point_right;
                    if(move->right != NULL){
                        if(move->left != NULL) move->left->next = move->right;
                        point_right = move->right;
                        // }else if(move->left!=NULL && move->right == NULL){
                        // }else if(move->right == NULL){
                    }else point_right = move->left;  
                    
                    if(move->next != NULL){
                        if(move->next->left != NULL){
                            point_right->next = move->next->left;
                        }else if(move->next->right != NULL){
                            point_right->next = move->next->right;
                        }else{
                            Node *run = move->next;
                            while(run != NULL && run->left == NULL && run->right == NULL){
                                run = run->next;
                            }
                            if(run != NULL && run->left != NULL) point_right->next = run->left;
                            else if(run != NULL && run->right != NULL) point_right->next = run->right;
                        }
                    }
                    
                    move = move->next;
                }
            }
            if(left_node->left != NULL)
                left_node = left_node->left;
            else if(left_node->right != NULL)
                left_node = left_node->right;
            else left_node = left_node->next;
            if(left_node == NULL) break;
        }
        return root;
    }
};

/*More readable 2*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        Node *left_node = root;
        while(left_node != NULL){
            Node *move = left_node;
            while(move != NULL){
                if(move->left == NULL && move->right == NULL){
                    move = move->next;
                    continue;
                }
                Node *point_right;
                if(move->right != NULL){
                    if(move->left != NULL) move->left->next = move->right;
                    point_right = move->right;
                }else point_right = move->left;  

                Node *run = move->next;
                while(run != NULL && run->left == NULL && run->right == NULL) run = run->next;
                if(run == NULL) break;
                if(run->left != NULL) point_right->next = run->left;
                else if(run->right != NULL) point_right->next = run->right;
                move = run;
            }
            
            if(left_node->left != NULL)
                left_node = left_node->left;
            else if(left_node->right != NULL)
                left_node = left_node->right;
            else left_node = left_node->next;
        }
        return root;
    }
};
/*More readable 3*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *left_node = root;
        while(left_node != NULL){
            Node *move = left_node;
            while(move != NULL){
                if(move->left == NULL && move->right == NULL)
                    break;
                Node *point_right;
                if(move->right != NULL){
                    if(move->left != NULL) move->left->next = move->right;
                    point_right = move->right;
                }else point_right = move->left;  

                Node *run = move->next;
                while(run != NULL && run->left == NULL && run->right == NULL) run = run->next;
                if(run == NULL) break;
                if(run->left != NULL) point_right->next = run->left;
                else if(run->right != NULL) point_right->next = run->right;
                move = run;
            }
            
            if(left_node->left != NULL)
                left_node = left_node->left;
            else if(left_node->right != NULL)
                left_node = left_node->right;
            else left_node = left_node->next;

        }
        return root;
    }
};
/*More readable 4*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *left_node = root;
        while(left_node != NULL){
            Node *move = left_node;
            /*Check for specific level*/
            while(move != NULL && (move->left != NULL || move->right != NULL)) {
                Node *point_right;
                if(move->right != NULL){/*if the right side is not null, then pointer to the right has to be from right side of the move*/
                    if(move->left != NULL) move->left->next = move->right;/*This is a simple connection 1*/
                    point_right = move->right;
                }else point_right = move->left;/*the pointer points to the right has be started from left side of move*/
                
                /*In a specific level, there can have some nodes having no children that could not created a linklist for this leve
                so need to run all node on this level until get the one has child*/
                Node *run = move->next;
                while(run != NULL && run->left == NULL && run->right == NULL) run = run->next;
                if(run == NULL) break;
                if(run->left != NULL) point_right->next = run->left;
                else if(run->right != NULL) point_right->next = run->right;
                move = run;
            }
            /*Go to next level*/
            if(left_node->left != NULL)
                left_node = left_node->left
            else if(left_node->right != NULL)
                left_node = left_node->right;
            else left_node = left_node->next;

        }
        return root;
    }
};
/*More readable 5*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *left_node = root;/*No need to use extra memory => Space O(1)*/
        while(left_node != NULL){ /*Check for every node in the tree only one time ==> Time complexity O(n), n is #node in tree*/
            /*if the left and right of a node are empty, could not build the 
            linklist for the next level from this node ==> need to go the next node*/
            if(left_node->left == NULL && left_node->right == NULL) {
                left_node = left_node->next;
                continue;
            }
            Node *move = left_node;
            /*Check for specific level*/
            while(move != NULL) {   
                Node *point_right;
                if(move->right != NULL){/*if the right side is not null, then pointer to the right has to be from right side of the move*/
                    if(move->left != NULL) move->left->next = move->right;/*This is a simple connection 1*/
                    point_right = move->right;
                }else point_right = move->left;/*the pointer points to the right has be started from left side of move*/
                
                /*In a specific level, there can have some nodes having no children that could not created a linklist for this leve
                so need to run all node on this level until get the one has child*/
                Node *run = move->next;
                while(run != NULL && run->left == NULL && run->right == NULL) run = run->next;
                if(run == NULL) break;
                if(run->left != NULL) point_right->next = run->left;
                else if(run->right != NULL) point_right->next = run->right;
                move = run;
            }
            /*Go to next level*/
            if(left_node->left != NULL)
                left_node = left_node->left;
            else if(left_node->right != NULL)
                left_node = left_node->right;

        }
        return root;
    }
};
