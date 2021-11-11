#ifndef __TREE_HEADER__
#define __TREE_HEADER__
#include<cctype>
#include<iostream>
#include<iomanip>

template<class Item>
class binary_tree_node {
private:
	Item data_field;
	binary_tree_node* left_field;
	binary_tree_node* right_field;

public:
	binary_tree_node(const Item& init_data, binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL) {
		this->data_field = init_data;
		this->left_field = init_left;
		this->right_field = init_right;
	}
	Item& data() { return this->data; }
	const Item& data() { return this->data; }
	binary_tree_node*& left() { return this->left_field; }
	const binary_tree_node*& left() { return this->left_field; }
	binary_tree_node* right() { return right_field; }
	const binary_tree_node*& right() { return right_field; }
	void set_data(const Item new_data){this->data_field = new_data;}
	void set_left(binary_tree_node* new_left) { this->left_field = new_left; }
	void set_right(binary_tree_node* new_right) { this->right_field = new_right; }
	bool is_leaf()const {
		return (this->left_field == NULL && this->right_field == NULL);
	}
};

template<class Item>
void tree_clear(binary_tree_node<Item>*& root_node) {
	if (root_node != NULL) {
		tree_clear(root_node->left);
		tree_clear(root_node->right());
		delete root_node;
		root_node = NULL;
	}
}

template<class Item>
binary_tree_node<Item>* tree_copy(binary_tree_node<Item>* root_node) {
	binary_tree_node<Item>* l_node;
	binary_tree_node<Item>* r_node;
	if (root_node == NULL) {
		return NULL;
	}
	else {
		l_node = tree_copy(root_node->left());
		r_node = tree_copy(root_node->right());
		return new binary_tree_node<Item>(root_node->data(), l_node, r_node);
	}
}

template<class Item>
void preorder_print(const binary_tree_node<Item>* root_node) {
	if (root_node != NULL) {
		std::cout << root_node->data() << " ";
		preorder_print(root_node->left());
		preorder_print(root_node->right());
	}
}

template<class Item>
void inorder_print(const binary_tree_node<Item>* root_node) {
	if (root_node != NULL) {
		inorder_print(root_node->left());
		std::cout << root_node->data_field << " ";
		inorder_print(root_node->right());
	}
}

template<class Item>
void postorder_print(const binary_tree_node<Item>* root_node) {
	if (root_node != NULL) {
		postorder_print(root_node->left());
		postorder_print(root_node->right());
		std::cout << root_node->data_field << " ";
	}
}

template<class Item, class SizeType>
void print(const binary_tree_node<Item>* root_node, SizeType depth) {
	if (root_node != NULL) {
		print(root_node->right(), depth + 1);
		std::cout << std::setw(4 * depth) << "" << root_node->data() << std::endl;
		print(root_node->left(), depth + 1);
	}
}

template<class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr) {
	if (node_ptr != NULL) {
		f(node_ptr->data());
		preorder(f, node_ptr->left());
		preorder(f, node_ptr->right());
	}
}

#endif // !__TREE_HEADER__
