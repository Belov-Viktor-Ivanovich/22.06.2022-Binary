#pragma once
template<typename T>
class TreeNode
{
public:
	T date;
	TreeNode* left=nullptr;
	TreeNode* right=nullptr;
	int id=0;
	bool operator ==(TreeNode& node)
	{
		return date == node.date;
	}
	bool operator >(TreeNode& node)
	{
		return date > node.date;
	}
	bool operator <(TreeNode& node)
	{
		return date < node.date;
	}
	friend ostream& operator<<(ostream& out, TreeNode& node)
	{
		out << node.date << " ";
		return out;
	}

};

template<typename T>
class BinaryTree
{
	TreeNode<T>* root = nullptr;
	int sizeTree = 0;
public:
	BinaryTree(){
	}
	BinaryTree(T date) {
		TreeNode<T>* node = new TreeNode<T>{ date };
		root = node;
		sizeTree ++;
		node->id = sizeTree;
	}
	~BinaryTree() {

	}


	void addToTree(T date)
	{
		TreeNode<T>* node = new TreeNode<T>{ date };
		if (sizeTree !=0)
		{
			TreeNode<T>* buf = root;
			while (true) 
			{
				if (*node < *buf)
				{
					if (buf->left == nullptr) {
						buf->left = node;
						sizeTree++;
						node->id = sizeTree;
						break;
					}
					else buf = buf->left;
				}
				else if (*node > *buf)
				{
					if (buf->right == nullptr) {
						buf->right = node;
						sizeTree++;
						node->id = sizeTree;
						break;
					}
					else buf = buf->right;
				}
				else break;

			}
		}
		else
		{
			root = node;
			sizeTree++;
			node->id = sizeTree;
		}
	}

	int poisk(int id)
	{
		TreeNode<T>* buf = root;
		while (true)
		{
			if (id == buf->date)return buf->id;
			else if (buf->left == nullptr && buf->right == nullptr) return -1;
			else if (id < buf->date) buf = buf->left;
			else if (id > buf->date) buf = buf->right;

		}
	}

	void showTree(TreeNode<T>* buf=nullptr)
	{
		if (buf == nullptr)buf = root;
		cout << *buf<<" ";
		if (buf->left != nullptr)showTree(buf->left);
		if (buf->right != nullptr)showTree(buf->right);
	}



private:

};

//BinaryTree::BinaryTree()
//{
//}
//
//BinaryTree::~BinaryTree()
//{
//}

