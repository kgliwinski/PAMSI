#ifndef LIST_NODE_HH
#define LIST_NODE_HH

template<typename type>
class ListNode
{
    private:
    type elem;
    ListNode* next;

    template<typename CType> friend class LinkedList;
};
#endif