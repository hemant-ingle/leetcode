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
        return addTwoNumbers(l1, l2, 0);
    }
    ListNode * addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
        if(!l1 && !l2) {
            return carry ? new ListNode(carry, nullptr) : nullptr;
        }
        int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode *s = addTwoNumbers(
            (l1 ? l1->next : nullptr),
            (l2 ? l2->next : nullptr),
            sum/10
        );
        ListNode *r = new ListNode(sum%10, s);
        return r;
    }
};