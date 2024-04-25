/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
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
    int getListSize(ListNode* head)
    {
        if(head == nullptr)return 0;
        ListNode* idx = head;
        int ans = 1;
        while(head -> next != nullptr)
        {
            head = head->next;
            ans++;
        }
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int size = getListSize(head);
        if(size == 0)return nullptr;
        
        k %= size;

        if(k == 0)return head;

        int trSize = size - k;
        ListNode* trailer;
        for(int i = 0; i < trSize; i++) // go to trSize'th node
        {
            if(i == 0)trailer = head;
            else trailer = trailer->next;
        }
        ListNode* last;
        for(int i = 0; i < size; i++) // go to last node
        {
            if(i == 0)last = head;
            else last = last->next;
        }
        /*
            if k == 2, n == 6, then trailer = 4
            (1) --- (2) --- (3) --- (4) --- (5) --- (6)
            =>
            (5) --- (6) --- (1) --- (2) --- (3) --- (4)
                   |last|    |        trailer        |
        */
        ListNode* newHead = trailer -> next;
        trailer -> next = nullptr;
        last -> next = head;
        head = newHead;
        return head;
    }
};
// @lc code=end

