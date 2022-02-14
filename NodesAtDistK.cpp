/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // step1: get parents of all nodes
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> par;
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->left){
                par[root->left] = root;
                q.push(root->left);
            }
            if(root->right){
                par[root->right] = root;
                q.push(root->right);
            }
        }
        // step2: perform bfs from target and get the distance
        vector<int> ans;
        int dist=0;
        unordered_set<TreeNode*> mp; // visited count
        mp.insert(target);
        q.push(target);
        while(!q.empty()){
            int sz=q.size();
            if(dist==k){
                break;
            }
            for(int i=0; i<sz; i++){
                root = q.front();
                q.pop();
                if(root->left && !mp.count(root->left)){
                    q.push(root->left);
                    mp.insert(root->left);
                }
                if(root->right && !mp.count(root->right)){
                    q.push(root->right);
                    mp.insert(root->right);
                }
                if(par[root] && !mp.count(par[root])){
                    q.push(par[root]);
                    mp.insert(par[root]);
                }
            }
            dist++;
        }
        if(dist!=k) return {};
        while(!q.empty()) {
            TreeNode* cur = q.front(); 
            q.pop();
            ans.push_back(cur->val);
        }
                
        return ans;
    }
};