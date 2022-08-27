//
// Created by 鲍伟 on 2022/8/26.
// 二叉树 链表实现
//


typedef char C;

typedef struct TreeLinkListNode {
    C element;
    struct TreeLinkListNode * left;
    struct TreeLinkListNode * right;
} * TLLNode;


// 访问节点
void visitTreeNodeLinkList(TLLNode node) {
    printf("%c ", node->element);
}


// 前序遍历
void PreOrderTreeLinkList(TLLNode root) {   // 传入根节点
    if (root == nullptr) return;
    visitTreeNodeLinkList(root);
    PreOrderTreeLinkList(root->left);
    PreOrderTreeLinkList(root->right);
}


// 中序遍历
void inOrderTreeLinkList(TLLNode root) {
    if (root == nullptr) return;
    inOrderTreeLinkList(root->left);
    visitTreeNodeLinkList(root);
    inOrderTreeLinkList(root->right);
}

// 后序遍历
void postOrderTreeLinkList(TLLNode root) {
    if (root == nullptr) return;
    postOrderTreeLinkList(root->left);
    postOrderTreeLinkList(root->right);
    visitTreeNodeLinkList(root);
}


// 层序遍历
void levelOrderTreeLinkList(TLLNode root) {
    // 采用一个队列来存储子节点
}


void testForBuildingBiTree() {
    auto a = (TLLNode)malloc(sizeof(struct TreeLinkListNode));
    auto b = (TLLNode)malloc(sizeof(struct TreeLinkListNode));
    auto c = (TLLNode)malloc(sizeof(struct TreeLinkListNode));
    auto d = (TLLNode)malloc(sizeof(struct TreeLinkListNode));
    auto e = (TLLNode)malloc(sizeof(struct TreeLinkListNode));
    auto f = (TLLNode)malloc(sizeof(struct TreeLinkListNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = nullptr;
    d->left = d->right = nullptr;
    e->left = e->right = nullptr;
    f->left = f->right = nullptr;

//    printf("%c", a->left->right->element);
    PreOrderTreeLinkList(a);
    printf("\n");
    inOrderTreeLinkList(a);
    printf("\n");
    postOrderTreeLinkList(a);
}


