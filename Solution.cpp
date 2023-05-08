//
// Created by Wardy on 08/05/2023.
//

#include "Solution.h"

ListNode* Solution::ReverseList(ListNode *Head)
{
    // Initialise a Prev ListNode to simulate a doubly linked list.
    ListNode* Prev = nullptr;

    // Keeps track of the current node in the iteration process.
    ListNode* Curr = Head;

    // When Curr reaches nullptr, the list has been reversed and no more operation need to be done.
    while (Curr)
    {
        // Get the next node in the list.
        ListNode* Forward = Curr->next;

        // Set the current nodes "next" pointer to the previous node. If this is nullptr, then Curr is the first node.
        Curr->next = Prev;

        // Moving the iterator forward by one.
        Prev = Curr;
        Curr = Forward;
    }

    // Prev will eventually be the last node in the original linked list, so it is the first node in the reversed list.
    return Prev;
}

ListNode* Solution::MergeTwoLists(ListNode *ListHead1, ListNode *ListHead2)
{
    // Check if either list is non-existent.
    if (!ListHead1) return ListHead2;
    if (!ListHead2) return ListHead1;

    if (ListHead1->val <= ListHead2->val)
    {
        ListHead1->next = MergeTwoLists(ListHead1->next, ListHead2);
        return ListHead1;
    }
    else
    {
        ListHead2->next = MergeTwoLists(ListHead1, ListHead2->next);
        return ListHead2;
    }
}

bool Solution::ListHasCycle(ListNode *Head)
{
    // If any of these checks fail a cycle is not present.
    if (!Head || !Head->next || !Head->next->next) return false;

    // This method uses slow and a fast pointer. If they are ever pointing to the same object then a cycle exists.
    ListNode* SlowPtr = Head->next;
    ListNode* FastPtr = Head->next->next;

    while(FastPtr->next && FastPtr->next->next)
    {
        if (SlowPtr == FastPtr) return true;

        SlowPtr = SlowPtr->next;
        FastPtr = FastPtr->next->next;
    }

    // If the code reaches here then the loop is broken out of, meaning FastPtr is not in a cycle.
    return false;
}

void Solution::ReorderList(ListNode *Head)
{
    // Needs three or more nodes to be able to reorder.
    if (!Head || !Head->next || !Head->next->next) return;

    // Get the Penultimate node in the list (second to last node).
    ListNode* Penultimate = Head;
    while (Penultimate->next->next) Penultimate = Penultimate->next;

    // We access the last node in the list by using Penultimate->next.

    // The last node now points to the second node in the list.
    Penultimate->next->next = Head->next;

    // The first node now points to the last node in the list.
    Head->next = Penultimate->next;

    // Penultimate is now the last node in the list, so it should point to nothing.
    Penultimate->next = nullptr;

    // Recursively call the function, the new head is the element after the old last node.
    ReorderList(Head->next->next);
}

int Solution::GetNumLinksRemaining(ListNode *Head)
{
    // If the list doesn't exist, return 0.
    if (!Head) return 0;

    // Initialise a counter.
    int NumLinksLeft = 1;

    // While the current node points to another valid node.
    while (Head->next)
    {
        NumLinksLeft++; // Increment counter.
        Head = Head->next; // Iterate to the next node.
    }

    return NumLinksLeft;
}

ListNode* Solution::RemoveNthFromEnd(ListNode *Head, int n)
{
    // If the list does not exist then immediately exit.
    if (!Head) return Head;

    // If the number of links remaining is n on the first node. return the rest of the list.
    if (n == GetNumLinksRemaining(Head)) return Head->next;

    // Keep a copy of the first node to return later.
    ListNode* FirstNode = Head;

    // Get the node which points to the node to remove.
    while (n + 1 != GetNumLinksRemaining(Head)) Head = Head->next;

    Head->next = Head->next->next;

    return FirstNode;
}

ListNode* Solution::AddTwoNumbers(ListNode *l1, ListNode *l2)
{
    // If neither list exists then return nothing.
    if (!l1 && !l2) return nullptr;

    // If l1 doesn't exist then return l2.
    if (!l1) return l2;

    //If l2 doesn't exist then return l1.
    if (!l2) return l1;

    // Calculate the sum of the two (necessarily existing) nodes.
    int sum = l1->val + l2->val;

    // Create a new node with val = sum.
    auto* SumNode = new ListNode(sum % 10);

    // Recursively call this function to add the rest of the lists together.
    SumNode->next = AddTwoNumbers(l1->next, l2->next);

    // If we need to carry a 1 forward.
    if (sum >= 10)
    {
        SumNode->next = AddTwoNumbers(SumNode->next, new ListNode(1));
    }

    return SumNode;
}

ListNode *Solution::MergeKLists(std::vector<ListNode *> &lists)
{
    // If no lists are provided, no merging can be done.
    if (lists.empty()) return nullptr;

    // Check to make sure there are two or more lists to merge.
    while (lists.size() > 1)
    {
        // Update the second list in the vector to be the merged list.
        lists[1] = MergeTwoLists(lists[0], lists[1]);

        // Erase the first list in the vector, since it has been merged into the second list of the vector.
        lists.erase(lists.begin());
    }

    // When only one list remains, return it.
    return lists.front();
}
