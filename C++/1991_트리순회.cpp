#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;

	string root, left, right;
	cin >> root >> left >> right;

	string preorder = root + left + right;
	string inorder = left + root + right;
	string postorder = left + right + root;

	for (int i = 1; i < num; i++) {
		cin >> root >> left >> right;
		int index_pre=preorder.find(root);
		int index_in = inorder.find(root);
		int index_post = postorder.find(root);
		preorder.replace(index_pre, 1, root + left + right);
		inorder.replace(index_in, 1, left + root + right);
		postorder.replace(index_post, 1, left + right + root);
	}

	for (int i = 0; i < preorder.size(); i++) {
		if(preorder[i]!='.')cout << preorder[i];
	}
	cout << endl;
	for (int i = 0; i < inorder.size(); i++) {
		if (inorder[i] != '.')cout << inorder[i];
	}
	cout << endl;
	for (int i = 0; i < postorder.size(); i++) {
		if (postorder[i] != '.')cout << postorder[i];
	}

	return 0;
}
