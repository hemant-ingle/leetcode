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
    ListNode * swapPairs(ListNode *first, ListNode *second) {
        if(!first) return nullptr;
        if(!second) return first;
        first->next = swapPairs(second->next, second->next ? second->next->next : nullptr);
        second->next = first;
        return second;
    }
    ListNode* swapPairs(ListNode* head) {
        return swapPairs(head, head ? head->next : nullptr);
    }
};