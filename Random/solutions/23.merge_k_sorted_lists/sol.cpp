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
            priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> min_pq([](ListNode *a, ListNode *b) -> bool {
                return (a->val > b->val);
            });

            for(ListNode *list: lists) {
                if(list) {
                    min_pq.push(list);
                }
            }
            ListNode *head = nullptr;
            ListNode *p;
            while(!min_pq.empty()) {
                if(!head) {
                    head = min_pq.top();
                    p = head;
                } else {
                    p->next = min_pq.top();
                    p = p->next;
                }
                min_pq.pop();
                if(p->next) {
                    min_pq.push(p->next);
                }
            }
            if(p) p->next = nullptr;
            return head;
        }
    };