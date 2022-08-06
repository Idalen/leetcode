class Node{
    public:
    int start, end;
    Node *right, *left;
    
    Node(int start, int end){
        this->start = start;
        this->end = end;
        this->right = nullptr;
        this->left =  nullptr;
    }
};

class MyCalendar {
public:
    
    Node* root;
    
    MyCalendar() { 
        this->root=nullptr;
    }
    
    bool book(int start, int end) {
        
        if(this->root==nullptr)
            this->root = new Node(start, end);
        
        else{
            
            Node* aux;
            aux = this->root;
            
            while(true){
                
                if(start>=aux->end){
                    if(aux->right==nullptr){
                        aux->right = new Node(start, end);
                        break;
                    }else
                        aux = aux->right;
                        
                }else if(end<=aux->start){
                    if(aux->left==nullptr){
                        aux->left = new Node(start, end);
                        break;
                    }
                    else
                        aux = aux->left;
                }else{
                    return false;
                }
            }
        }  
        
        return true;
    }
    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */