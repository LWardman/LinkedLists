//
// Created by Wardy on 08/05/2023.
//

#ifndef LINKEDLISTS_SOLUTION_H
#define LINKEDLISTS_SOLUTION_H

#include <vector>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    explicit ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution
{
public:
    /**
     * Reverses a linked list.
     * Provides a way of iterating over the linked list in the opposite order,
     * which is usually done in doubly linked lists.
     *
     * @param Head The first node of the list to be reversed.
     * @returns The first node in the reversed list.
     */
    static ListNode* ReverseList(ListNode* Head);

    /**
     * Merges two SORTED lists into one sorted list.
     * Sorted meaning both lists are in ascending order.
     *
     * @param ListHead1 The first node in the first list.
     * @param ListHead2 The first node in the second list.
     * @returns The head of the merged sorted list.
     */
    ListNode* MergeTwoLists(ListNode* ListHead1, ListNode* ListHead2);

    /**
     * Determines whether there is a cycle in a given list.
     * Useful to make sure Node->next isn't always true.
     * e.g while (Node->next) will cause an infinite loop if a cycle exists in the list.
     *
     * @param Head The first node in the list.
     * @returns true or false depending on if there exists a cycle or not. true = cycle exists.
     */
    static bool ListHasCycle(ListNode* Head);

    /**
     * Reorders a list in the following fashion.
     * 1 -> 2 -> ... -> N - 1 -> N
     * ....
     * 1 -> N -> 2 -> N -1 -> 3 -> N-2 ...
     *
     * @param Head The first node to start reordering from.
     */
    void ReorderList(ListNode* Head);

    /**
     * Determines how many links are remaining in the list.
     *
     * @param Head The node to start counting from.
     * @returns The integer value of the number of links left.
     */
    static int GetNumLinksRemaining(ListNode* Head);

    /**
     * Removes the node from the list which has n remaining links.
     *
     * @param Head The node to start counting from.
     * @param n The reverse index of the node to remove (counting from the size of the list downwards).
     * @returns The list with the node removed.
     */
    static ListNode* RemoveNthFromEnd(ListNode* Head, int n);

    /**
     * Adds two linked lists together, as long as each represents a number.
     * e.g 1->2->3 + 2->5->3 = 3->7->6.
     *
     * @param l1 The first number represented as a linked list.
     * @param l2 The second number represented as a linked list.
     *
     * @returns The head of the linked list which represents the integer value of the sum.
     */
    ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2);

    /**
     * Merges any number of sorted lists together into one big sorted linked list.
     * Uses MergeTwoLists k - 1 times to achieve this.
     * 
     * @param lists A vector of sorted linked lists.
     * @returns The head of the merged linked list.
     */
    ListNode* MergeKLists(std::vector<ListNode*>& lists);
};


#endif //LINKEDLISTS_SOLUTION_H
