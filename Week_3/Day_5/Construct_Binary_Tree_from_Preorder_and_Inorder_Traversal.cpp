class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int preIndex = 0;
        return build(preorder, preIndex, 0, inorder.size() - 1, inorderIndex);
    }

private:
    TreeNode* build(vector<int>& preorder, int& preIndex, int left, int right,
                    unordered_map<int, int>& inorderIndex) {
        if (left > right) {
            return nullptr;
        }

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];

        root->left = build(preorder, preIndex, left, mid - 1, inorderIndex);
        root->right = build(preorder, preIndex, mid + 1, right, inorderIndex);

        return root;
    }
};
