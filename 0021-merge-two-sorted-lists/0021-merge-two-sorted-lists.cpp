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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(t1 != NULL && t2 != NULL){
            if(t1->val > t2->val){
                ListNode* newnode = new ListNode(t2->val);
                t2 = t2->next;
                curr->next = newnode;
                curr = curr->next;
            }
            else{
                ListNode* newnode = new ListNode(t1->val);
                t1 = t1->next;
                curr->next = newnode;
                curr = curr->next;
            }
            
        }
        while(t1){
            ListNode* newnode = new ListNode(t1->val);
                t1 = t1->next;
                curr->next = newnode;
                curr = curr->next;
        }
        while(t2){
            ListNode* newnode = new ListNode(t2->val);
                t2 = t2->next;
                curr->next = newnode;
                curr = curr->next;
        }
        return dummy->next;
    }
};