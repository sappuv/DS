#include <iostream>

// Define the node structure for the BST
struct Node {
  int data;
  Node *left;
  Node *right;
};

// Function to create a new node
Node* createNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

// Function to insert a new node into the BST
void insert(Node*& root, int data) {
  if (root == nullptr) {
    root = createNode(data);
    return;
  }
  if (data < root->data) {
    insert(root->left, data);
  } else if (data > root->data) {
    insert(root->right, data);
  }
}

// Function to delete a node from the BST
void deleteNode(Node*& root, int data) {
  if (root == nullptr) {
    return;
  }
  if (data < root->data) {
    deleteNode(root->left, data);
  } else if (data > root->data) {
    deleteNode(root->right, data);
  } else {
    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      root = temp;
    } else if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      root = temp;
    } else {
      Node* temp = root->right;
      while (temp->left != nullptr) {
        temp = temp->left;
      }
      root->data = temp->data;
      deleteNode(root->right, temp->data);
    }
  }
}

// Function to search for a value in the BST
bool search(Node* root, int data) {
  if (root == nullptr) {
    return false;
  }
  if (root->data == data) {
    return true;
  }
  if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// Function to perform an in-order traversal of the BST
void inOrder(Node* root) {
  if (root != nullptr) {
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
  }
}

// Function to find the minimum value in the BST
int findMin(Node* root) {
  while (root->left != nullptr) {
    root = root->left;
  }
  return root->data;
}

// Function to find the maximum value in the BST
int findMax(Node* root) {
  while (root->right != nullptr) {
    root = root->right;
  }
  return root->data;
}

int main() {
  Node* root = nullptr;

  // Insert some values into the BST
  insert(root, 5);
  insert(root, 3);
  insert(root, 8);
  insert(root, 1);
  insert(root, 4);
  insert(root, 7);
  insert(root, 10);

  // Delete a value from the BST
  deleteNode(root, 8);

  // Search for a value in the BST
  std::cout << search(root, 4) << std::endl; // Outputs 1 (true)
  std::cout << search(root, 6) << std::endl; // Outputs 0 (false)

  // Perform an in-order traversal of the BST
  std::cout << "In-order traversal: ";
  inOrder(root);
  std::cout << std::endl;

  // Find the minimum and maximum values in the BST
  int min = findMin(root);
  int max = findMax(root);
  std::cout << "Minimum value: " << min << std::endl;
  std::cout << "Maximum value: " << max << std::endl;

  return 0;
}
