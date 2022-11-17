/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    bool check(ListNode* head, queue<int> *q){
        
        bool res=true; 
        int val;
        q->push(head->val);
        
        if(head->next!=nullptr)
            res = check(head->next, q);
        
        val = q->front();
        q->pop();
        
        
        return res&&(val==head->val) ? true : false;
        
    }
    
    bool isPalindrome(ListNode* head) {
        queue<int> q;
        return check(head, &q);
    }
};