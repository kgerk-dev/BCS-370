#pragma once

#include <iostream>
#include "Game.h"
#include <string>
#include <stack>

// Source for Stack
// https://www.cplusplus.com/reference/stack/stack/

struct TreeNode {
	Game info;
	TreeNode* right;
	TreeNode* left;
}; 

class BST
{

public:
	BST();
	BST(const BST& rhs);
	~BST();

	void Clear();
	void CopyTree(const TreeNode* tree);
	void DeleteNode(Game item);
	int	 Size();
	void Add(Game g);
	void PreOrder();
	void InOrder();
	void PostOrder();
	bool GetGameScore(std::string gameName, double& gamePrice);
	



	BST& operator=(const BST& rhs);

	friend std::ostream& operator<<(std::ostream& os, BST& rhs);


private:
	TreeNode* root;

	//*************** HELPERS *********************

	void Clear(TreeNode*& tree);
	void CopyTree(TreeNode*& copyTree, const TreeNode* originalTree);
	void FindDeleteNode(TreeNode*& tree, Game item);
	void RemoveNode(TreeNode*& tree);
	void GetPredecessorData(TreeNode* tree, Game& data);
	int  Size(TreeNode* tree);
	void Add(TreeNode*& tree, Game g);
	void PreOrder(TreeNode* tree);
	void InOrder(TreeNode* tree);
	void PostOrder(TreeNode* tree);
	bool GetScore(TreeNode* tree, std::string name, double& score);
	
};

