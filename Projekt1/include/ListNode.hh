#ifndef LIST_NODE_HH
#define LIST_NODE_HH


/*! \class ListNode
 *  \brief A ListNode class contains definition of Node for singly LinkedList 
*/
template<typename type>
class ListNode
{
    private:
    type elem;
    ListNode* next;

    template<typename CType> friend class LinkedList;
};
#endif