/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *left;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n){

        //if n=0 no trees can be formed
        if (n == 0) return {};

        return generateTreesRec(1, n);
    }

    vector<TreeNode *> generateTreesRec(int start, int end){
        
        vector<TreeNode *> ans;

        if (start > end){
            ans.push_back(NULL);
            return ans;
        }

        for (int i = start; i <= end; i++){

            //generating the all the left and right subtrees for each i
            vector<TreeNode *> leftSubTree = generateTreesRec(start, i - 1);
            vector<TreeNode *> rightSubTree = generateTreesRec(i + 1, end);

            //filling the generated subtrees in the ans vector
            for (auto left : leftSubTree){
                for (auto right : rightSubTree){
                    TreeNode *root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};