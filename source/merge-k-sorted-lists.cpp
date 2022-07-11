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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *res = new ListNode();
        ListNode* aux = res;
        bool flag = true;
        int min, min_index;
        while(flag){
            
            min = INT_MAX;
            flag = false;
            for(int i=0; i<lists.size(); i++){
                if(lists[i] != NULL && lists[i]->val < min){
                    min_index = i;
                    min = lists[i]->val;
                    flag= true;
                   
                }
            }
            
            if(flag){
                
                aux->next = new ListNode();
                aux = aux->next;
                aux->val = min;

                lists[min_index] = lists[min_index]->next; 
            }
        }
        
        
        return res->next;
    }
};