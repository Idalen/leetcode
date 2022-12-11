class Solution {
    public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *tailOdd=head, *tailEven=head->next, *headEven=head->next, *tmp=tailEven->next;
        int count = 1;

        while(tmp!=nullptr){
            
            if(count%2){ // if count is odd
                tailOdd->next = tmp;
                tailOdd = tailOdd->next;
            }else{
                tailEven->next=tmp;
                tailEven=tailEven->next;
            }
            count++;
            //cout << tmp->val << " " << tailOdd->val << " "<<tailEven->val << endl;
            tmp = tmp->next;
        }
        
        tailOdd->next = headEven;
        tailEven->next=nullptr;


        return head;


    }
};