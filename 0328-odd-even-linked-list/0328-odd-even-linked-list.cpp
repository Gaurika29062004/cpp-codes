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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;            
        ListNode* even = head->next;      

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        ListNode* temp = odd;
        while(temp){
            curr->next = new ListNode(temp->val);
            curr = curr->next;

            if(temp->next) temp = temp->next->next;
            else break;
        }
        temp = even;
        while(temp){
            curr->next = new ListNode(temp->val);
            curr = curr->next;

            if(temp->next) temp = temp->next->next;
            else break;
        }
        return dummy->next;
    }
};
