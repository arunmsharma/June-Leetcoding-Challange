/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
//     int calcsumfromvec(vector<int>&v){
//         int n=v.size();
//         int res=0;
//         for(int i=0;i<v.size();i++){
//             res+=(v[i]*pow(10,n-1));
//             n--;
//         }
//         cout<<res<<endl;
//         return res;
//     }
//     void storevectors(TreeNode *root,vector<vector<int>>&v,vector<int>&p){
//         if(root==NULL){
//             return;
//         }
//         if(root->left == NULL and root->right == NULL){
//             p.push_back(root->val);
//             v.push_back(p);
//             return;
//         }
//         if(root->left){
//             vector<int>v1=p;
//             v1.push_back(root->val);
//             storevectors(root->left,v,v1);
//         }
//          if(root->right){
//             vector<int>v1=p;
//             v1.push_back(root->val);
//             storevectors(root->right,v,v1);
//         }
        
//     }
//     int sumNumbers(TreeNode* root) {
//         vector<vector<int>>v;
//         vector<int>p;
//         storevectors(root,v,p);
        
//         int ans=0;
//         for(int i=0;i<v.size();i++){
//             ans+=calcsumfromvec(v[i]);
//         }
//         return ans;
//     }
        void fun(TreeNode *root,int curr,int &res){
            if(root==NULL){
                return;
            }
            curr=curr*10+root->val;
            if(root->left==NULL && root->right==NULL){
                res+=curr;
                return;
            }
            fun(root->left,curr,res);
            fun(root->right,curr,res);
        }
    
        int sumNumbers(TreeNode *root){
            int res=0;
            fun(root,0,res);
            return res;
        }
};
