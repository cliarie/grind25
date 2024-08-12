#include <queue>
#include <vector>
using namespace std;
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

class Compare{
public:
    bool operator()(const ListNode* a, const ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto t : lists){
            if (t) pq.push(t);
        }

        if (pq.empty()) return nullptr;

        ListNode* ans = pq.top();
        auto cur = ans;
        pq.pop();
        // pq.push(ans->next)
        while(!pq.empty()){
            ListNode * temp = cur->next;
            if (temp)pq.push(temp);
            cur->next = pq.top();
            pq.pop();
            //if (temp)pq.push(temp);
            cur = cur->next;
        }

        return ans;
    }
};
