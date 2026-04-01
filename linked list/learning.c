#include <stdio.h>
#include <stdlib.h> // malloc 和 free 必须包含这个库

// ==========================================
// 1. 图纸车间：定义节点的结构
// ==========================================
typedef struct Node {
    int data;           // 抽屉：存真实数据
    struct Node* next;  // 路牌：存下一个柜子的地址
} Node;


// ==========================================
// 2. 零件车间：专门打造一个完美的新节点
// ==========================================
Node* createNode(int value) {
    // 步骤 A：向操作系统申请一个 Node 大小的物理内存
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // 步骤 B：防爆安全检查（如果内存满了，操作系统会拒绝，返回 NULL）
    if (newNode == NULL) {
        printf("内存分配失败，程序崩溃！\n");
        exit(1); 
    }
    
    // 步骤 C：往新柜子的抽屉里放数据，并且把路牌擦干净（置空）
    newNode->data = value;
    newNode->next = NULL; 
    
    return newNode; // 把这个造好的新柜子的地址交出去
}


// ==========================================
// 3. 组装车间：把新节点挂到链表的最末尾（尾插法）
// ==========================================
// 参数 head 是当前链表的头指针，value 是我们要新插入的数字
Node* insertAtTail(Node* head, int value) {
    // 先去零件车间提货，拿到一个全新的独立节点
    Node* newNode = createNode(value);

    // 情况 A：如果这是一片荒地（链表是空的）
    if (head == NULL) {
        // 这个新节点就是全村的希望，它就是新的头节点！
        return newNode; 
    }

    // 情况 B：链表里已经有东西了，我们需要找到最后那个人
    Node* curr = head; // 派出一个替身指针去跑腿
    
    // 只要当前柜子的路牌上还有下一个地址，就顺着地址往下走
    while (curr->next != NULL) {
        curr = curr->next;
    }

    // 当 while 循环结束时，curr 绝对停在了最后一个柜子上！
    // 此时，把最后一个柜子的路牌，改写成新柜子的地址，就成功连上了！
    curr->next = newNode;
    
    // 头节点的位置没变，原样返回
    return head; 
}


// ==========================================
// 4. 质检车间：顺藤摸瓜打印链表
// ==========================================
void printList(Node* head) {
    Node* curr = head;
    printf("当前链表形态: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}


// ==========================================
// 5. 环保车间：C 语言程序员的终极素养 —— 释放内存
// ==========================================
void freeList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;       // 先拿个小本本记下当前柜子的地址
        curr = curr->next;       // curr 赶紧跑到下一个柜子去安全避难
        free(temp);              // 呼叫拆迁队，把刚才记下地址的那个柜子无情炸毁！
    }
    printf("链表内存已全部释放，打扫战场完毕！\n");
}


// ==========================================
// 终极 Boss：main 函数发号施令
// ==========================================
int main() {
    // 1. 初始化一个绝对的空链表（极其重要，不要留野指针）
    Node* head = NULL; 

    // 2. 开始疯狂组装
    printf("开始创建链表...\n");
    head = insertAtTail(head, 10);
    printList(head); // 看一眼效果
    
    head = insertAtTail(head, 20);
    printList(head); // 再看一眼
    
    head = insertAtTail(head, 30);
    printList(head); // 最后看一眼

    // 3. 游戏结束，打扫战场（Python 会帮你做这件事，但 C 必须你亲自动手）
    freeList(head);

    return 0;
}