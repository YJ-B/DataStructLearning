//
// Created by 鲍伟 on 2022/8/26.
// 二叉查找树
//

typedef int E;

typedef struct BiSearchTreeNode {
    E element;
    BiSearchTreeNode* left;
    BiSearchTreeNode* right;
} *BSTNode;

BSTNode createBiSearchNode(E element) {
    auto node = (BSTNode)malloc(sizeof(struct BiSearchTreeNode));
    node->left = node->right = nullptr;
    node->element = element;
    return node;
}

BSTNode insertBiSearchTree(BSTNode root, E element) {
    if (root) {
        if (root->element > element) {
            root->left = insertBiSearchTree(root->left, element);
        } else if (root->element < element) {
            root->right = insertBiSearchTree(root->right, element);
        }
    } else {
        root = createBiSearchNode(element);
    }
    return root;
}

void inOrderBiSearchTree(BSTNode root) {
    if (root == nullptr) return;
    inOrderBiSearchTree(root->left);
    printf("%d ", root->element);
    inOrderBiSearchTree(root->right);
}

BSTNode findBiSearchTree(BSTNode root, E target) {
    while(root) {
        if (root->element > target) root = root->left;
        else if (root->element < target) root = root->right;
        else return root;
    }
    return nullptr;
}

BSTNode findMAXBiSearchTree(BSTNode root) {
    while (root && root->right) {
        root = root->right;
    }
    return root;
}

// 删除节点
BSTNode deleteBiSearchTree(BSTNode root, E target) {
    if (root == nullptr) return nullptr;
    if (root->element > target) {
        root->left = deleteBiSearchTree(root->left, target);
    } else if (root->element < target) {
        root->right = deleteBiSearchTree(root->right, target);
    } else {
        if (root->left && root->right) {
            BSTNode max = findMAXBiSearchTree(root->left);
            root->element = max->element;
            root->left = deleteBiSearchTree(root->left, root->element);
        } else {
            BSTNode tmp = root;
            if (root->right) {
                root = root->right;
            } else {
                root = root->left;
            }
            free(tmp);
        }
    }
    return root;
}


void testForBiSearchTree() {
    BSTNode root = insertBiSearchTree(nullptr, 18);
    insertBiSearchTree(root, 10);
    insertBiSearchTree(root, 20);
    insertBiSearchTree(root, 7);
    insertBiSearchTree(root, 5);
    insertBiSearchTree(root, 22);
    insertBiSearchTree(root, 9);
    inOrderBiSearchTree(root);

    printf("\n%p\n", findBiSearchTree(root, 17));
    printf("%p\n", findBiSearchTree(root, 9));
    printf("%p\n", findMAXBiSearchTree(root));

    deleteBiSearchTree(root, 18);
    inOrderBiSearchTree(root);

}