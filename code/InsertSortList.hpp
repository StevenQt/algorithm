#pragma once

#include <iostream>

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* curr = head->next;
        while (curr != NULL) {
            ListNode* next = curr->next;            
            ListNode* tmp = head->next;
            ListNode* prev = head;
            while (tmp != curr)
            {
                if (tmp->val > curr->val)
                {
                    curr->next = tmp;
                    prev->next = curr;
                }

                prev = tmp;
                tmp = tmp->next;
            }
             
            curr = next;
        }

        return head;
    }
};
