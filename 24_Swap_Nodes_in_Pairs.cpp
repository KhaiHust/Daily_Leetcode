#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    ListNode *dump = new ListNode(0, nullptr);

    ListNode *pre = dump, *curr = head;
    while (curr && curr->next)
    {
        // save nodes
        ListNode *nextNode = curr->next->next;
        ListNode *second = curr->next;

        // reverse
        second->next = curr;
        curr->next = nextNode;
        pre->next = second;

        // update ptrs
        pre = curr;
        curr = nextNode;
    }
    return dump->next;
}