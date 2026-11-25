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
        if(lists.empty()) return nullptr;

        //create a min heap (priority queue)
        auto compare = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // for each non empty linked list - push its head node into the heap
        for(ListNode* list: lists){
            if(list != nullptr){
                minHeap.push(list);
            }
        }

        //create a dummy node to start the result list and pointed curr to it
        ListNode* res = new ListNode(0);
        ListNode* curr = res;


        while(!minHeap.empty()){
            //pop the node with the smallest value from the top
            ListNode* node = minHeap.top();
            minHeap.pop();

            //attach this node to curr.next and move curr forward
            curr->next = node;
            curr = curr->next;
            node = node->next;
            
            //if this node has a next node then push that next node into the heap
            if(node != nullptr){
                minHeap.push(node);
            }
        }

        return res->next;
    }
};
