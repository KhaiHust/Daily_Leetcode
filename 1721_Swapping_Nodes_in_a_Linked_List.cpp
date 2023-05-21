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

int countNode(ListNode *head)
{
    int count = 0;
    ListNode *curNode = head;
    while (curNode != nullptr)
    {
        count++;
        curNode = curNode->next;
    }
    return count;
}

ListNode *swapNodes(ListNode *head, int k)
{
    int n = countNode(head);
    if (n == 1)
        return head;

    ListNode *curNode1 = head, *curNode2 = head, *preNode1 = head, *preNode2 = head;

    int i = 1;
    while (i < k && curNode1 != nullptr)
    {
        preNode1 = curNode1;
        curNode1 = curNode1->next;
        i++;
    }

    i = 1;
    while (i < (n - k + 1) && curNode2 != nullptr)
    {
        preNode2 = curNode2;
        curNode2 = curNode2->next;
        i++;
    }
    if (k == n)
    {

        preNode1->next = curNode2;
        curNode1->next = preNode2->next;
        return curNode1;
    }
    if (preNode1 != nullptr)
        preNode1->next = curNode2;
    else
        head = curNode2;

    if (preNode2 != nullptr)
        preNode2->next = curNode1;
    else
        head = curNode1;

    ListNode *temp = curNode2->next;
    curNode2->next = curNode1->next;
    curNode1->next = temp;

    return head;
}