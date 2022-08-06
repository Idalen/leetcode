class Node{
public:
    
    int val;
    Node *left=nullptr, *right=nullptr;
    
    Node(int val){
        this->val = val;
    }
    
};


class SegmentTree{
public:
    
    Node* root=nullptr;
    int left0, right0;
    
    void build(Node** node, vector<int> *nums, int left, int right){
        
        int sum = 0;
        for(int i=left; i<right; i++)
            sum += nums->at(i);
        
        *node = new Node(sum);
        
        
        if (left+1 == right)
            return;
        
        int middle = (left+right)/2;
        build(&(*node)->left,nums,left, middle);
        build(&(*node)->right,nums,middle, right);
        
    }
    
    SegmentTree(vector<int> nums){
        this->left0  = 0;
        this->right0 = nums.size();
        
        build(&(this->root), &nums, this->left0, this->right0);
        
        
    }
    
    void rec_update(Node* node, const int index, const int new_val, int left, int right, int* old_val){
        
        if(left+1==right){
            *old_val = node->val;
            node->val = new_val;
            return;
        }
        
        int middle = (left+right)/2;
        if (index < middle)
            rec_update(node->left, index, new_val, left, middle, old_val);
        else
            rec_update(node->right, index, new_val, middle, right, old_val);
        
        node->val+=(new_val - *old_val);
    }
    
    void update(int index, int new_val){
        int old_val;
        rec_update(this->root, index, new_val, this->left0, this->right0, &old_val);
    }
    
    void rec_rangeSum(Node* node, int left, int right, int curr_left, int curr_right, int* sum){
         
        if(left==curr_left && right == curr_right){
            *sum+=node->val;
            return;
        }
        
        int curr_middle = (curr_left + curr_right)/2;
        
        if(left < curr_middle && right>curr_middle){
            rec_rangeSum(node->left , left,  curr_middle,   curr_left, curr_middle, sum);
            rec_rangeSum(node->right, curr_middle, right,  curr_middle, curr_right, sum);
        }else if(right<=curr_middle){
            rec_rangeSum(node->left , left,  right,   curr_left, curr_middle, sum);
        }else{
            rec_rangeSum(node->right, left, right,  curr_middle, curr_right, sum);
        }
    }
    
    int rangeSum(int left, int right){
        int sum=0;
        rec_rangeSum(this->root, left, right+1, this->left0, this->right0, &sum);
        return sum;
    }
        
};

class NumArray {
public:

    SegmentTree* tree;
    
    NumArray(vector<int>& nums) {
        this->tree = new SegmentTree(nums);
    }
    
    // ~NumArray() {
    //     delete this->tree;
    // }
    
    void update(int index, int val) {
        this->tree->update(index,val);
    }
    
    int sumRange(int left, int right) {
        return this->tree->rangeSum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */