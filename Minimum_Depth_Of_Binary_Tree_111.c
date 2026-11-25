#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static void minDepthRunner(const struct TreeNode *node, int *gottenMinDepthPtr, int gottenDepth)
{
    if (!node)
        return;

    if (gottenDepth > *gottenMinDepthPtr)
        return;

    if (!node->left && !node->right){
        *gottenMinDepthPtr = gottenDepth;
        return;
    }

    minDepthRunner(node->left, gottenMinDepthPtr, gottenDepth + 1);
    minDepthRunner(node->right, gottenMinDepthPtr, gottenDepth + 1);
}

int minDepth(struct TreeNode* root) {
    int minDepth = INT_MAX;
    if (!root)
        return 0;

    minDepthRunner(root, &minDepth, 1);


    return minDepth;
}
