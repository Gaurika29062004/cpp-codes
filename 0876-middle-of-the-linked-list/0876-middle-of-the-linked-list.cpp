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
    ListNode* middleNode(ListNode* head) {
       int count = 0;
       ListNode* temp = head;
       if(head == NULL || head->next == NULL) return head;
       while(temp){
        count++;
        temp = temp->next;
       } 
       int mid = (count)/2+1;
       int cnt = 0;
       temp = head;
       while(cnt < mid){
        cnt++;
        if(cnt == mid){
            head = temp;
            return head;
        }
        temp = temp->next;
       }
        return head;
    }
};