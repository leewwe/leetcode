#include <vector>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 112，递归
// bool hasPathSum(TreeNode* root, int sum) {
//     if(!root){
//         return false;
//     }
//     if(!root->left && !root->right){
//         if(!(sum - root->val)){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     return (hasPathSum(root->left, sum - root->val)) || 
//     (hasPathSum(root->right, sum - root->val));
// }

// 迭代
bool hasPathSum(TreeNode* root, int sum) {
    if(!root){
        return false;
    }
    stack<pair<TreeNode*, int>> treeStack;
    treeStack.push({root, sum-root->val});
    while(!treeStack.empty()){
        auto node = treeStack.top().first;
        auto currSum = treeStack.top().second;
        treeStack.pop();
        if(!node->left && !node->right && !currSum){
            return true;
        }
        if(node->left){
            treeStack.push({node->left, currSum - node->left->val});
        }
        if(node->right){
            treeStack.push({node->right, currSum - node->right->val});
        }
    }
    return false;
}

// 杨辉三角形1
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> tri;

    for(int i = 0; i < numRows; ++i){
        if(i == 0){
            tri.push_back(vector<int>{1});
        }
        else if(i == 1){
            tri.push_back(vector<int>{1,1});
        }
        else{
            tri.push_back(vector<int>{1});
            for(auto j = 1; j < tri[i - 1].size(); ++j) {
                tri[i].push_back(tri[i - 1][j - 1] + tri[i - 1][j]);
            }
            tri[i].push_back(1);
        }
    }
    return tri;
}
// 杨辉三角形2
vector<int> getRow(int rowIndex) {

    vector<int> even{1};
    vector<int> odd{1,1};
    if(rowIndex == 0){
        return even;
    }
    if(rowIndex == 1){
        return odd;
    }
    for(int i = 2; i <= rowIndex; i++){
        // 计算奇数行
        if((i%2)){
            odd.clear();
            odd.push_back(1);
            for(int j = 1; j < even.size(); ++j){
                odd.push_back(even[j - 1] + even[j]);
            }
            odd.push_back(1);
            continue;
        }
        // 计算偶数行
        even.clear();
        even.push_back(1);
        for(int j = 1; j < odd.size(); ++j){
            even.push_back(odd[j - 1] + odd[j]);
        }
        even.push_back(1);
    }
    return (rowIndex % 2) ? odd : even;
}

// int maxProfit(vector<int>& prices) {
//     if(prices.empty() || prices.size() == 1){
//         return 0;
//     }
//     int minPrice = prices[0];
//     int maxProfit = 0;
//     for(int i = 1; i < prices.size(); ++i){
//         if(prices[i] < minPrice){
//             minPrice = prices[i];
//         }
//         if(prices[i] - minPrice > maxProfit){
//             maxProfit = prices[i] - minPrice;
//         }
//     }
//     return maxProfit;
// }

// int maxProfit(vector<int>& prices) {
//     if(prices.empty()){
//         return 0;
//     }
//     int max = 0;
//     int valley = prices[0];
//     int peak = prices[0];
//     for(int i = 0; i < prices.size() - 1;){
//         while(i < prices.size() - 1 && prices[i + 1] <= prices[i]){
//             ++i;
//         }
//         valley = prices[i];
//         while(i < prices.size() - 1 && prices[i + 1] >= prices[i]){
//             ++i;
//         }
//         // 这里很关键，这么写会在找不到山顶的时候，将peak和valley等值，最后就不会产生错误的结果
//         peak = prices[i];
//         max += (peak - valley);
//     }
//     return max;
// }

int maxProfit(vector<int>& prices) {
    if(prices.empty()){
        return 0;
    }
    int max = 0;
    for(int i = 0; i < prices.size() - 1; ++i){
        int diff = prices[i + 1] - prices[i];
        if(diff > 0){
            max += diff;
        }
    }
    return max;
}


int main(int argc, char** argv){

    // cout << "test" << endl;

    // auto root = new TreeNode(5);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(8);

    // root->left->left = new TreeNode(11);
    // root->right->left = new TreeNode(13);
    // root->right->right = new TreeNode(4);

    // root->left->left->left = new TreeNode(7);
    // root->left->left->right = new TreeNode(2);
    // root->right->right->left = new TreeNode(1);

    // auto res = hasPathSum(root, 22);


    // auto root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // auto res = hasPathSum(root, 2);

    // auto tri = generate(2);

    // auto row = getRow(3);

    vector<int> stock{7,1,5,3,6,4};
    // vector<int> stock;
    // int res = maxProfit(stock);
    int res = maxProfit(stock);
    return 0;
}