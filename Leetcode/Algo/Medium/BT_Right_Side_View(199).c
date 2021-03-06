/***************************************
199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
***************************************/
int ht(struct TreeNode* root){
    if(!root) return 0;
    
    int left=ht(root->left);
    int right=ht(root->right);
    
    if(left>right) return left+1;
    
    return right+1;
}

void dfs(struct TreeNode* root, int level, int** ret,int* size, bool* flag){
    if(!root) return;
    
    if(level==0){
        (*size)++;
        *ret=(int*)realloc(*ret,(*size)*sizeof(int));
        (*ret)[(*size)-1]=root->val;
        *flag=1;
    }else{
        dfs(root->right,level-1,ret,size,flag);
        if(*flag) return;
        dfs(root->left,level-1,ret,size,flag);
        if(*flag) return;
    }
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    if(!root) return NULL;
    int* ret=NULL;
    bool flag=0;
    
    int tree_ht=ht(root);
    for(int i=0;i<=tree_ht;i++){
        flag=0;
        dfs(root,i,&ret,returnSize,&flag);
    }
    
    return ret;
    
}
