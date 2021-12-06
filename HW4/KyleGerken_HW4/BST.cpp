#include "BST.h"
//*****************************************************
// Function: Binary Search Tree - Default Constructor
// 
// Purpose: Creates an empty binary search tree
// 
// Update Information:
// ------------------------------------------
//*****************************************************


//*****************************************************
// Function: Binary Search Tree - Default Constructor
// 
// Purpose: Creates an empty binary search tree
// 
// Update Information:
// ------------------------------------------
//*****************************************************
BST::BST() {
	root = nullptr;
}



//*****************************************************
// Function: Binary Search Tree - Copy Constructor
// 
// Purpose: This function should make a deep copy of the passed in 
//			binary search tree. The structure of the tree of the copy 
//			should be exactly the same as the original Tree!!
// 
// Update Information:
// ------------------------------------------
//*****************************************************
BST::BST(const BST& rhs) {
	if (rhs.root == nullptr) {
		root = nullptr;
	}
	else {
		CopyTree(this->root, rhs.root);
	}
	
}



//*****************************************************
// Function: Binary Search Tree - Destructor
// 
// Purpose: Uses the Helper function Clear to make the BST empty and 
//			release the memory.
// 
// Update Information:
// ------------------------------------------
//*****************************************************
BST::~BST() {
	Clear();
}



//*****************************************************
// Functions: void BST::Clear(), void BST::Clear(TreeNode*& tree)
// 
// Purpose: Clear() implicitly calls Clear(TreeNode*& tree).
//			Clears the binbary search tree and releases ALL 
//			dynamically allocated memory. When items 
//			are removed you MUST release memory.
// 
// Update Information:
// ------------------------------------------
//*****************************************************
void BST::Clear()
{
	//Make Empty
	Clear(root);
	root = nullptr;

}



void BST::Clear(TreeNode*& tree) {
	//PostOrder Deletion for the Destructor/Clear Methods
	if (tree != nullptr) {
		Clear(tree->left);
		Clear(tree->right);
		delete tree;
	}
}


//*****************************************************
// Functions: void CopyTree(const TreeNode* tree),
//			 void BST::CopyTree(TreeNode*& copyTree, const TreeNode* originalTree)
// 
// Purpose: Implicility calls a Helper Function to copy the passed 
//			in value of the Tree.
// 
//			Second CopyTree is the Explicit Private function.
//			Explicitly Copys the original tree passed in and references 
//			new tree to copy and change the structure to match the original
//			exactly.
// 
// Update Information:
// ------------------------------------------
//*****************************************************
void BST::CopyTree(const TreeNode* tree)
{
	CopyTree(root);
}



void BST::CopyTree(TreeNode*& copyTree, const TreeNode* originalTree)
{
	if (originalTree == nullptr) {
		copyTree = nullptr;
	}
	else
	{

		copyTree = new TreeNode;
		copyTree->info = originalTree->info;
		CopyTree(copyTree->left, originalTree->left);
		CopyTree(copyTree->right, originalTree->right);
	}
}



//*****************************************************
// Functions: void BST::DeleteNode(TreeNode*& tree, Game item),
//			 void BST::FindDeleteNode(Tree*& tree, Game item),
//			 void BST::RemoveNode(TreeNode*& tree),
//			 void BST::GetPredecessorData(TreeNode* tree, Game& data)
// 
// Purpose: Implicit Call of FindDeleteNode(). Deletes specified Game in BST.
//			Helper Functions included:
//			- FindDeleteNode(TreeNode*& tree, Game item)
//			- RemoveNode(TreeNode*& tree) 
//			- GetPredecessorData(TreeNode*& tree, Game& data)
// 
//			-FindDeleteNode()
//			When needed to Delete ONE item in the BST. This function uses 
//			two helper functions alongside itself. Passing in a pointer to
//			 a reference of the BST.
// 
//			-RemoveNode()
//			Called from FindDeleteNode. Searches the subtrees for #
//			of children. If more than ONE child in the subtree. 
//			GetPredecessorData() is called to label a Pred node.
//			Once Pred Node is found, again runs FindDeleteNode() to delete.\
// 
//			- GetPredecessorNode()
//			Finds the node with the highest value in tree. 
//			The rightmost node in the tree contains the data with 
//			the highest values.
// 
// Update Information:
// ------------------------------------------
//*****************************************************
void BST::DeleteNode( Game item) {
	FindDeleteNode(root, item);
}


void BST::FindDeleteNode(TreeNode*& tree, Game item) {
	//Find common values of Game to pass through
	if (item < tree->info) {
		FindDeleteNode(tree->left, item);
	}
	else  if (item > tree->info) {
		FindDeleteNode(tree->right, item);
	}
	else {
		RemoveNode(tree);
	}
}


void BST::RemoveNode(TreeNode*& tree)
{
	
	Game data;
	TreeNode* tempPtr;
	tempPtr = tree;
	if (tree->left == nullptr) {
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == nullptr) {
		tree = tree->left;
		delete tempPtr;
	}
	else {
		GetPredecessorData(tree->left, data);
		tree->info = data;
		FindDeleteNode(tree->left, data);
	}
}



void BST::GetPredecessorData(TreeNode* tree, Game& data)
{
	while (tree->right != nullptr) {
		tree = tree->right;
	}
	data = tree->info;
}



//*****************************************************
// Functions: int BST::Size(), int BST::Size(TreeNode* tree)
// 
// Purpose: Implicit Call of Size(Tree* tree). 
//			Second Function, is the explicit call to return the size of the 
//			BST from root.
//			
//			
// Update Information:
// ------------------------------------------
//*****************************************************
int BST::Size() {
	return Size(root);
}



int BST::Size(TreeNode* tree) {
	if (tree == nullptr) {
		return 0;
	}
	else {
		return Size(tree->left) + Size(tree->right) + 1;
	}
}



//*****************************************************
// Functions: void BST::Add(Game g), void BST::Add(TreeNode*& tree, Game g)
// 
// Purpose: Adds a Game object to the BST. It should be addes to the BST by 'Title'
//			of the game. 
//			Add(Game g) implicitly calls Add(TreeNode*& tree, Game g)
//			
// Update Information:
// ------------------------------------------
//*****************************************************
void BST::Add(Game g)
{
	Add(root, g);
}

void BST::Add(TreeNode*& tree, Game g) {
	if (tree == nullptr) {

		tree = new TreeNode;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->info = g;
	}
	else if (g < tree->info) {
		Add(tree->left, g);
	}
	else {
		Add(tree->right, g);
	}
}



//*****************************************************
// Functions: void BST::PreOrder(), void BST::PreOrder(TreeNode* tree) 
// 
// Purpose: Prints the 'Title' of all the Game objects in the BST. The output
//			uses a PreOrder Traversal of the BST Recursively.
//			PreOrder() implicility calls PreOrder(TreeNode* tree).
//			
//			
// Update Information:
// ------------------------------------------
//*****************************************************
void BST::PreOrder() {
	PreOrder(root);
}

void BST::PreOrder(TreeNode* tree) {
	if (tree != nullptr) {
		std::cout << tree->info << std::endl;
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}



//*****************************************************
// Functions: void BST::InOrder(), void BST::InOrder(TreeNode* tree) 
// 
// Purpose: Prints the 'Title' of all the Game objects in the BST. The output
//			uses a InOrder Traversal of the BST Recursively.
//			InOrder() implicility calls InOrder(TreeNode* tree).
//			
//			
// Update Information:
// ------------------------------------------
//*****************************************************
void BST::InOrder() {
	InOrder(root);
}

void BST::InOrder(TreeNode* tree) {
	if (tree != nullptr) {
		InOrder(tree->left);
		std::cout << tree->info << std::endl;
		InOrder(tree->right);
	}
}



//*****************************************************
// Functions: void BST::PostOrder(), void BST::PostOrder(TreeNode* tree)
// 
// Purpose: Prints the 'Title' of all the Game objects in the BST. The output
//			uses a PostOrder Traversal of the BST Recursively.
//			PostOrder() implicility calls PostOrder(TreeNode* tree).
//			
//			
// Update Information:
// ------------------------------------------
//*****************************************************
void BST::PostOrder() {
	PostOrder(root);
}


void BST::PostOrder(TreeNode* tree) {
	if (tree != nullptr) {
		PostOrder(tree->left);
		PostOrder(tree->right);
		std::cout << tree->info << std::endl;
	}
}



//*****************************************************
// Functions: bool BST::GetScore(std::string name, double& score), 
//			  bool BST::GetScore(TreeNode* tree, std::string name, double& price)
// 
// Purpose: This function finds the score given a Game's Title. It then sends back
//			the Game's Price as a reference when true. Otherwise returns false if
//			title and price are not correct. 
//			GetScore(std::string name, double& price) implicitly calls
//			GetScore(TreeNode* tree, std::string name, double& price), which then
//			uses a "Retrieval Search" to find the correct Game object matching the 
//			string 'name'.
//			
//			
// Update Information:
// ------------------------------------------
//*****************************************************
bool BST::GetGameScore(std::string gameName, double& gamePrice) {
	return GetScore(root ,gameName, gamePrice);
}



bool BST::GetScore(TreeNode* tree, std::string name, double& price) {
	//Bottom of Tree return false
	if (tree == nullptr) {
		return false;
	}
	//Search Left Subtree
	else if (name < tree->info.GetTitle()) {
		GetScore(tree->left, name, price);
	}
	//Search Right Subtree
	else if (name > tree->info.GetTitle()) {
		GetScore(tree->right, name, price);
	}
	else {
		//Return Price Through Reference Parameter?
		price = tree->info.GetPrice();
		return true;
	}
	return false;
}



//*****************************************************
// Function: BST& BST::operator=(const BST& rhs)
// 
// Purpose: Overloaded assignment operator assigns the value of one 
//			binary tree to another. Making a Deep Copy of the binary tree to
//			be assigned using the function CopyTree
//			
//			
// Update Information:
// ------------------------------------------
//*****************************************************
BST& BST::operator=(const BST& rhs)
{
	// TODO: insert return statement here
	if (this != &rhs) {
		if (root != nullptr) {
			Clear(root);
		}
		if (rhs.root == nullptr) {
			root = nullptr;
		}
		else {
			CopyTree(root, rhs.root);
		}
	}

	return *this;

}



//*****************************************************
// Function: std::ostream& operator<<(std::ostream& os, BST& rhs)
// 
// Purpose: Print the values using a non-member operator<< overload.
//			Prints the values of ALL elements on the BST on the given ostream.
//			Show ALL game node data for each node in the BST using an InOrder
//			Traversal.
//			Non-Recursive InOrder Traversal = DepthFirstTraversal
//			using a Stack Data Structure.
//			
//			
// Update Information:
// ------------------------------------------
// Instead of using the Do While loop I used a While loop with a Stack library
// References from 'BST p3.pptx - Slide 25 (Depth First Traversal)
//*****************************************************
std::ostream& operator<<(std::ostream& os, BST& rhs) {
	//Declare Stack for non recursive InOrder traversal
	std::stack<TreeNode* > stack;
	//Declare temp TreeNode 
	TreeNode* temp;
	
	//Assign Rhs.root to temp TreeNode
	temp = rhs.root;

	//Check to see if BST and Stack are not empty.
	while ((temp != nullptr) || (!stack.empty())) {
		if (temp != nullptr) {
			//push root to stack begin down left side of tree
			stack.push(temp);
			temp = temp->left;
		}
		else {
			//Traverse begins 
			temp = stack.top();
			stack.pop();
			//If Game Overloaded properly should print out ENTIRE Game Object.
			os << temp->info << " ";
			temp = temp->right;
		}
	}

	std::cout << std::endl;

	return os;
}





