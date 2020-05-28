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
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode *oddHead = head, *oddCurrent = head;
        ListNode *evenHead = head->next, *evenCurrent = head->next;
        ListNode *current = head->next;
        ListNode *next = current->next;
        bool oddTurn = true;
        while (next != NULL){
            current = next;
            next = next->next;
            if (oddTurn) oddCurrent->next = current, oddCurrent = current;
            else         evenCurrent->next = current, evenCurrent = current;
            oddTurn = !oddTurn;
        }
        oddCurrent->next = evenHead;
        evenCurrent->next = NULL;
        return oddHead;
    }
    
};