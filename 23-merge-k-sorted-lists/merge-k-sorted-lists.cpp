class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Put first node of every list into heap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (!pq.empty()) {

            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};