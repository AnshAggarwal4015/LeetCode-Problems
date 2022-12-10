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
    ListNode* partition(ListNode* head, int x) {
        vector<int> left, right;
        
        ListNode* temp = head;
        
        while( temp != NULL ){
            if( temp->val < x ){
                left.push_back(temp->val);
            } else {
                right.push_back(temp->val);
            }
            temp = temp->next;
        }
        
        temp = head;
        int i=0, j=0;
        while( temp ){
            if( i < left.size() ){
                temp->val = left[i];
                i++;
            } else {
                temp->val = right[j];
                j++;
            }
            temp = temp->next;
        }
        return head;
    }
};