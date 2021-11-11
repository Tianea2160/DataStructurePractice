#include"tree/binary_tree_node.h"
#include<iostream>
using namespace std;

template<class Item>
class bag {
public:
	bag() {
		root_node = NULL;
	}
	bag(const binary_tree_node<Item>* source) {
		root_node = tree_copy(source)
	}
	~bag() {
		tree_clear(root_node);
	}
	int size() {
		return size(root_node);
	}
	void insert(const Item* entry) {
		if (root_node == NULL) {
			root_node = new binary_tree_node<Item>(entry, NULL, NULL);
			return;
		}

		binary_tree_node<Item>* cursor = root_node;
		while(root_node != )
	}
private:
	binary_tree_node<Item>* root_node;
};

template<class Item>
int size(binary_tree_node<Item>* root_node) {
	if (root_node == NULL) return 0;
	return 1 + size(root_node->left()) + size(root_node->left());
}

int main(int argc, char const * argv[]) {

}