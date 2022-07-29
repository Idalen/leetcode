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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int> v1, v2;
        stack<int> v3;
        int carryout=0, temp;
        
        
        while(l1!=nullptr){
            v1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2!=nullptr){
            v2.push(l2->val);
            l2 = l2->next;
        }
        
        while(!(v1.empty() && v2.empty())){
            if(v1.empty()){
                temp = (v2.front()+carryout);
                v2.pop();
            }
            else if(v2.empty()){
                temp = (v1.front()+carryout);
                v1.pop();
            }
            else{ 
                temp = (v1.front()+v2.front()+carryout);
                v1.pop(); v2.pop();
            }

            cout << temp;
            carryout = int(temp>=10);
            temp = temp%10;
            v3.push(temp);
            
            
        }
        
        if (carryout)
            v3.push(carryout);

        ListNode* ret = nullptr;
        while(!v3.empty()){
            ret = new ListNode(v3.top(), ret);
            v3.pop();
        }
        
        return ret;
        
    }
};