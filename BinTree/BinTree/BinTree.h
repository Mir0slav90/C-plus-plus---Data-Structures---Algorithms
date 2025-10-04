#pragma once
#include<iostream>
using namespace std;

template<class K, class T>
struct node
{
	node<K, T>* left;
	K key;
	T info;
	node<K, T>* right;
};

template<class K, class T>
class BinTree
{
public:
	BinTree();
	bool Insert(K keyData, T data);
	bool Search(K keyData);
	bool GetInfo(K keyData, T& data);
	bool UpdateInfo(K keyData, T data);
	void Print_R_L_R();
	void Print_L_R_R();
	int PrintCount();
	void Print_R_R_L();
private:
	node<K, T>* root;
	bool InsertP(K keyData, T info, node<K, T>*& root);
	node<K, T>* SearchP(K keyData, node<K, T>* root);
	void Root_Left_Right(node<K, T>* root);
	void Left_Root_Right(node<K, T>* root);
	void Right_Root_Left(node<K, T>* root);
	int TreeCount(node<K, T>* root, int& count);
};

template<class K, class T>
BinTree<K, T>::BinTree()
{
	root = nullptr;
}

template<class K, class T>
bool BinTree<K, T>::InsertP(K keyData, T info, node<K, T>*& root)
{
	if (root == nullptr)
	{
		root = new node<K, T>;
		root->key = keyData;
		root->info = info;
		root->left = root->right = nullptr;
		return true;
	}
	else if (root->key == keyData) return false;
	if (keyData < root->key) return InsertP(keyData, info, root->left);
	return InsertP(keyData, info, root->right);
}

template<class K, class T>
bool BinTree<K, T>::Insert(K keyData, T data)
{
	return InsertP(keyData, data, root);
}

template<class K, class T>
node<K, T>* BinTree<K, T>::SearchP(K keyData, node<K, T>* root)
{
	if (root == nullptr || root->key == keyData) return root;
	if (keyData < root->key) return SearchP(keyData, root->left);
	return SearchP(keyData, root->right);
}

template<class K, class T>
bool BinTree<K, T>::Search(K keyData)
{
	return SearchP(keyData, root) != nullptr;
}

template<class K, class T>
bool BinTree<K, T>::GetInfo(K keyData, T& data)
{
	node<K, T>* temp = SearchP(keyData, root);
	if (temp == nullptr) return false;
	data = temp->info;
	return true;
}

template<class K, class T>
bool BinTree<K, T>::UpdateInfo(K keyData, T data)
{
	node<K, T>* temp = SearchP(keyData, root);
	if (temp == nullptr) return false;
	temp->info = data;
	return true;
}

template<class K, class T>
void BinTree<K, T>::Root_Left_Right(node<K,T>*root)
{
	if (root != nullptr)
	{
		if (root->info)
			cout << root->info << " -> ";
		Root_Left_Right(root->left);
		Root_Left_Right(root->right);
	}
}

template<class K, class T>
void BinTree<K, T>::Print_R_L_R()
{
	Root_Left_Right(root);
}

template<class K, class T>
void BinTree<K, T>::Left_Root_Right(node<K, T>* root)
{
	if (root != nullptr)
	{
		Left_Root_Right(root->left);
		if(root->info)
			cout << root->info <<" -> ";
		Left_Root_Right(root->right);
	}
}

template<class K, class T>
void BinTree<K, T>::Print_L_R_R()
{
	Left_Root_Right(root);
}

template<class K, class T>
int BinTree<K, T>::TreeCount(node<K,T>*root, int& count)
{
	if (root != nullptr)
	{
		count++;
		TreeCount(root->left, count);
		TreeCount(root->right, count);
	}
	return count;
}

template<class K, class T>
int BinTree<K, T>::PrintCount()
{
	int count = 0;
	return TreeCount(root, count);
}

template<class K, class T>
void BinTree<K, T>::Right_Root_Left(node<K, T>* root)
{
	if (root != nullptr)
	{
		Right_Root_Left(root->right);
		if (root->info)
			cout << root->info << " -> ";
		Right_Root_Left(root->left);
	}
}

template<class K, class T>
void BinTree<K, T>::Print_R_R_L()
{
	Right_Root_Left(root);
}