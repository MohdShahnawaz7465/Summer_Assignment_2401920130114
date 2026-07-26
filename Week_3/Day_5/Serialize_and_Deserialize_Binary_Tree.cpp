class Codec {
public:

    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }

private:
    void serializeHelper(TreeNode* node, string& result) {
        if (node == nullptr) {
            result += "#,";
            return;
        }

        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    TreeNode* deserializeHelper(const string& data, int& pos) {
        int commaPos = data.find(',', pos);
        string token = data.substr(pos, commaPos - pos);
        pos = commaPos + 1;

        if (token == "#") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(data, pos);
        node->right = deserializeHelper(data, pos);

        return node;
    }
};
