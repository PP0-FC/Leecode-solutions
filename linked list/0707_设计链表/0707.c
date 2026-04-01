/**
 * @problem: 设计链表
 * @approach: 链表
 * @time_complexity: O(n) --- IGNORE ---
 * @space_complexity: O(1) --- IGNORE ---
 * @note: 函数名称和参数列表已经在题目中给出，直接按照要求实现就行了，不要修改函数名称和参数列表，否则会导致编译错误。
 */

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct 
{
    Node* sentinel;
    int size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    obj->sentinel = (Node*)malloc(sizeof(Node));
    obj->sentinel->data = 0;
    obj->sentinel->next = NULL;

    obj->size = 0;    

    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) 
{
    if(index < 0 || index >= obj->size)
    {
        return -1;
    }

    Node* curr = obj->sentinel->next;
    for(int i = 0; i < index; i++)
    {
        curr = curr->next;
    }

    return curr->data;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) 
{
    if(index < 0 || index > obj->size)  return;

    Node* pre = obj->sentinel;
    for(int i = 0; i < index; i++)
    {
        pre = pre->next;
    } 

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = pre->next;
    pre->next = newNode;

    obj->size++;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) 
{
    if(index < 0 || index >= obj->size)  return;

    Node* pre = obj->sentinel;
    for(int i = 0; i < index; i++)
    {
        pre = pre->next;
    }

    Node* temp = pre->next;
    pre->next = temp->next;

    free(temp);

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) 
{
    Node* curr = obj->sentinel;
    while(curr != NULL)
    {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }    
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/