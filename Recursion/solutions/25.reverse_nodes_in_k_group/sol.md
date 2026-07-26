**Time Complexity:** *O(n),* **Space Complexity:** *O(n + k).*
```cpp
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode *> _stack;
        ListNode *node = head;
        for(int i=0; i<k; i++) {
            if(!node) break;
            _stack.push(node);
            node = node->next;
        }
        if(_stack.size() < k) return head;
        ListNode *nextGroup = node;
        ListNode *newHead = _stack.top();
        _stack.pop();
        node = newHead;
        while(!_stack.empty()) {
            node->next = _stack.top();
            _stack.pop();
            node = node->next;
        }
        node->next = nullptr;
        node->next = reverseKGroup(nextGroup, k);
        return newHead;
    }
};
```