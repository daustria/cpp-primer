#include <string>
#include <iostream>

class TreeNode
{

	friend std::ostream &operator<<(std::ostream &out, const TreeNode &);

	public:
		TreeNode(const std::string s = std::string()):
			value(s), count(1), left(nullptr), right(nullptr)
		{

		}

		void setLeft(TreeNode *node)
		{
			left = node;
			updateCount();
		}

		void setRight(TreeNode *node)
		{
			right = node;
			updateCount();
		}



	private:
		std::string value; //some value
		int count; //stores the number of nodes in the tree
		TreeNode *left; 
		TreeNode *right;

		void updateCount()
		{
			int numLeft = 0;
			int numRight = 0;

			if (left)
				numLeft = left->count;
			if (right)
				numRight = right->count;

			count = 1 + numLeft + numRight;
		}
};

class BinStrTree
{
	private:
		TreeNode *root;

};


std::ostream &operator<<(std::ostream &out, const TreeNode &node)
{
	out << node.value << " " << node.count;
	return out;
}

int main()
{

	TreeNode root("root");
	TreeNode node1("somenode");
	TreeNode node2("someother");
	TreeNode node3("0101010101");


	node1.setLeft(&node3);
	root.setLeft(&node1);
	root.setRight(&node2);


	std::cout << root << std::endl;
}
