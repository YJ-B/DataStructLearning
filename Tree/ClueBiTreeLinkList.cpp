//
// Created by 鲍伟 on 2022/8/26.
// 线索二叉树 链表
//

typedef char C;

typedef struct ClueBiTreeNode {
    C element;
    ClueBiTreeNode *left, *right;
    int leftTag, rightTag;
} *CBTNode;

CBTNode createNode(C element) {
    auto node = (CBTNode)malloc(sizeof(struct ClueBiTreeNode));
    node->left = node->right = nullptr;
    node->rightTag = node->leftTag = 0;
    node->element = element;
    return node;
}


CBTNode pre = nullptr;
// 前序遍历线索化函数
void preOrderThreaded(CBTNode root) {
    if (root == nullptr) return;
    if (root->left == nullptr) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == nullptr) {
        pre->right = root;
        pre->rightTag = 1;
    }

    pre = root;
    if (root->leftTag == 0) preOrderThreaded(root->left);
    if (root->rightTag == 0) preOrderThreaded(root->right);

}

void preOrderClueBiTree(CBTNode root) {
    while (root) {
        printf("%c ", root->element);
        if (root->leftTag == 0) {
            root = root->left;
        } else {    // import
            root = root->right;
        }
    }
}


void inOrderClueBiThreaded(CBTNode root) {
    if (root == nullptr) return;
    if (root->leftTag == 0) inOrderClueBiThreaded(root->left);
    if (root->left == nullptr) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == nullptr) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    if (root->rightTag == 0) inOrderClueBiThreaded(root->right);
}

// 中序遍历
void inOrderClueBiTree(CBTNode root) {
    while (root) {
        // 中序遍历先找到最左边的节点
        while (root && root->leftTag == 0) {
            root = root->left;
        }
        printf("%c", root->element);

        while (root && root->rightTag == 1) {
            root = root->right;
            printf("%c", root->element);
        }
        root = root->right;
    }
}

void postOrderClueBiThreaded(CBTNode root) {
    if (root == nullptr) return;
    if (root->leftTag == 0) inOrderClueBiThreaded(root->left);
    if (root->rightTag == 0) inOrderClueBiThreaded(root->right);
    if (root->left == nullptr) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == nullptr) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
}

void postOrderClueBiTree(CBTNode root) {
    // 结构中需要添加指向父亲节点的指针
}


void testForClueBiTree() {
    CBTNode a = createNode('A');
    CBTNode b = createNode('B');
    CBTNode c = createNode('C');
    CBTNode d = createNode('D');
    CBTNode e = createNode('E');

    a->left = b;
    b->left = d;
    a->right = c;
    b->right = e;

//    preOrderThreaded(a);
//    preOrderClueBiTree(a);

    inOrderClueBiThreaded(a);
    inOrderClueBiTree(a);
}