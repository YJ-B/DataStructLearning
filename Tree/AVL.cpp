//
// Created by 鲍伟 on 2022/8/26.
// 平衡二叉树
//

typedef int E;
typedef struct AVLTreeNode {
    E element;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height; // 记录当前子树的高度，用来计算平衡因子
} *AVLTNode;

AVLTNode createNode(E element) {
    auto node = (AVLTNode)malloc(sizeof(struct AVLTreeNode));
    node->left = node->right = nullptr;
    node->element = element;
    node->height = 1;   // 初始高度为1
    return node;
}

int maxAVL(int a, int b) {
    return a > b ? a : b;
}

int getHeightAVL(AVLTNode root) {
    if (root == nullptr) return 0;
    return root->height;
}

AVLTNode leftRotation(AVLTNode root) { // 传入原本的根节点，返回新的根节点
    AVLTNode newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    root->height = maxAVL(getHeightAVL(root->left), getHeightAVL(root->right)) + 1;
    newRoot->height = maxAVL(getHeightAVL(newRoot->left), getHeightAVL(newRoot->right)) + 1;

    return newRoot;
}

AVLTNode rightRotation(AVLTNode root) {
    AVLTNode newRoot = root->left;
    root->left = newRoot->left;
    newRoot->right = root;
    root->height = maxAVL(getHeightAVL(root->left), getHeightAVL(root->right)) + 1;
    newRoot->height = maxAVL(getHeightAVL(newRoot->left), getHeightAVL(newRoot->right)) + 1;
    return newRoot;

}

AVLTNode leftRightRotation(AVLTNode root){
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

AVLTNode rightLeftRotation(AVLTNode root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}


AVLTNode insertAVL(AVLTNode root, E element) {
    if (root == nullptr) {
        root = createNode(element); // 如果是第一个节点，直接生成
    } else if (root->element > element) {   // 判断节点值的大小，看是插在左边还是右边，大于在左边
        root->left = insertAVL(root->left, element);    // 递归插入正确的位置
        if (getHeightAVL(root->left) - getHeightAVL(root->right) > 1) { // 计算平衡因子
            if (root->left->element > element) {    // 左边LL，右边LR
                root = rightRotation(root);     // LL -> Right Rotation
            } else {
                root = leftRightRotation(root); // LR -> Left Rotation & Right Rotation
            }
        }
    } else if (root->element < element) {
        root->right = insertAVL(root->right, element);
        if (getHeightAVL(root->left) - getHeightAVL(root->right) > 1) {
            if (root->left->element > element) {    // 左边RL，右边RR
                root = rightLeftRotation(root); // RL -> Right Rotation & Left Rotation
            } else {
                root = leftRotation(root);      // RR -> Left Rotation
            }
        }
    }
    // 完成旋转操作后需要更新树的高度
    root->height = maxAVL(getHeightAVL(root->left), getHeightAVL(root->right)) + 1;
    return root;
}

void testForAVL() {

}
