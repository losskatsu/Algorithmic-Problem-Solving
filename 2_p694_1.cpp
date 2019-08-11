#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

typedef struct _treeNode{
	vector<_treeNode*> children;
} TreeNode; 

int n, y[100], x[100], radius[100]; 
int longest;

int sqr(int x){
	return x*x; 
}

int sqrdist(int a, int b){
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]); 
}


bool encloses(int a, int b){
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}


bool isChild(int parent, int child){
	if(!encloses(parent, child)) return false; 
	for(int i=0; i<n; ++i){
		if(i!=parent && i!=child && encloses(i, child))
			return false;
	return true;
	}
}


int height(TreeNode* root){
	vector<int> heights;
	for(int i=0; i < root->children.size(); ++i){
		heights.push_back(height(root->children[i])); 
	}
	if(heights.empty()) return 0;
	sort(heights.begin(), heights.end());
	if(heights.size() >= 2){
		longest=max(longest, 2+heights[heights.size()-2] + heights[heights.size()-1]); 
	}
	return heights.back() + 1;
}

int solve(TreeNode* root){
	longest=0;
	int h = height(root); 
	return max(longest, h); 
}

TreeNode* getTree(int root){
	TreeNode* ret = new TreeNode(); 
	for(int ch=0; ch<n; ++ch)
		if(isChild(root, ch))
			ret->children.push_back(getTree(ch));
	return ret;
}




int main()
{
	int n = 3;
	int x[] = {5,5,5}; 
	int y[] = {5,5,5};
	int radius[] = {15,10,5}; 

	TreeNode *T = getTree(0);
	cout << solve(T) << endl;

	return 0;

}
