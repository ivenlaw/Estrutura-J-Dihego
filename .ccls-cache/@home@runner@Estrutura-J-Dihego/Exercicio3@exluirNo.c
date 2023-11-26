#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Função auxiliar para encontrar o nó mínimo em uma árvore
TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Função auxiliar para remover um nó da árvore
TreeNode* removeNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Caso 1: Nó a ser removido está na subárvore esquerda
    if (key < root->data) {
        root->left = removeNode(root->left, key);
    }
    // Caso 2: Nó a ser removido está na subárvore direita
    else if (key > root->data) {
        root->right = removeNode(root->right, key);
    }
    // Caso 3: Nó a ser removido é encontrado
    else {
        // Nó com apenas um filho ou nenhum filho
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Nó com dois filhos: encontrar o sucessor in-order (menor nó na subárvore direita)
        TreeNode* temp = findMin(root->right);

        // Copiar o valor do sucessor para este nó
        root->data = temp->data;

        // Remover o sucessor
        root->right = removeNode(root->right, temp->data);
    }

    return root;
}

// Função para exibir a árvore em ordem
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    // Suponha que você tenha uma função createSampleTree() para criar uma árvore de exemplo.
    TreeNode* root = createSampleTree();

    // Exibir a árvore antes da remoção
    printf("Árvore antes da remoção: ");
    inOrderTraversal(root);
    printf("\n");

    // Remover um nó específico (por exemplo, o nó com valor 10)
    int keyToRemove = 10;
    root = removeNode(root, keyToRemove);

    // Exibir a árvore após a remoção
    printf("Árvore após a remoção do nó com valor %d: ", keyToRemove);
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
