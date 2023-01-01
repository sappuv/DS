// construct an expression tree from postfix and prefix expression perform recursive and non recursive in pre and postorder traversals
#include <iostream>
#include <stack>
#include <string>

struct Node
{
    char value;
    Node *left;
    Node *right;
    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

Node *createExpressionTreeFromPostfix(const std::string &expression)
{
    std::stack<Node *> stack;
    for (char ch : expression)
    {
        if (isdigit(ch))
        {
            stack.push(new Node(ch));
        }
        else
        {
            Node *right = stack.top();
            stack.pop();
            Node *left = stack.top();
            stack.pop();
            Node *node = new Node(ch);
            node->left = left;
            node->right = right;
            stack.push(node);
        }
    }

    return stack.top();
}

void preorderTraversalRecursive(Node *root)
{
    std::cout << root->value << " ";
    if (root->left)
    {
        preorderTraversalRecursive(root->left);
    }

    if (root->right)
    {
        preorderTraversalRecursive(root->right);
    }
}

void preorderTraversalNonRecursive(Node *root)
{
    std::stack<Node *> stack;
    stack.push(root);

    while (!stack.empty())
    {
        Node *node = stack.top();
        stack.pop();
        std::cout << node->value << " ";

        if (node->right)
        {
            stack.push(node->right);
        }
        if (node->left)
        {
            stack.push(node->left);
        }
    }
}

Node *createExpressionTreeFromPrefix(const std::string &expression)
{
    std::stack<Node *> stack;

    for (int i = expression.length() - 1; i >= 0; i--)
    {
        char ch = expression[i];
        if (isdigit(ch))
        {
            stack.push(new Node(ch));
        }
        else
        {
            Node *left = stack.top();
            stack.pop();
            Node *right = stack.top();
            stack.pop();
            Node *node = new Node(ch);
            node->left = left;
            node->right = right;
            stack.push(node);
        }
    }
    return stack.top();
}

void postorderTraversalRecursive(Node *root)
{
    if (root->left)
    {
        postorderTraversalRecursive(root->left);
    }
    if (root->right)
    {
        postorderTraversalRecursive(root->right);
    }

    std::cout << root->value << " ";
}

void postorderTraversalNonRecursive(Node *root)
{
    std::stack<Node *> stack;
    stack.push(root);
    Node *lastVisited = nullptr;

    while (!stack.empty())
    {
        Node *node = stack.top();

        if (!node->left && !node->right || (lastVisited && (lastVisited == node->left || lastVisited == node->right)))
        {
            std::cout << node->value << " ";
            stack.pop();
            lastVisited = node;
        }
        else if (node->right)
        {
            stack.push(node->right);
        }
        else
        {
            stack.push(node->left);
        }
    }
}
int main()
{
    std::string postfixExpression = "23+5*";
    Node *postfixTree = createExpressionTreeFromPostfix(postfixExpression);

    std::cout << "Postfix expression tree (recursive preorder): ";
    preorderTraversalRecursive(postfixTree);
    std::cout << std::endl;

    std::cout << "Postfix expression tree (non-recursive preorder): ";
    preorderTraversalNonRecursive(postfixTree);
    std::cout << std::endl;

    std::cout << "Postfix expression tree (recursive postorder): ";
    postorderTraversalRecursive(postfixTree);
    std::cout << std::endl;

    std::cout << "Postfix expression tree (non-recursive postorder): ";
    postorderTraversalNonRecursive(postfixTree);
    std::cout << std::endl;

    std::string prefixExpression = "*+235";
    Node *prefixTree = createExpressionTreeFromPrefix(prefixExpression);

    std::cout << "Prefix expression tree (recursive preorder): ";
    preorderTraversalRecursive(prefixTree);
    std::cout << std::endl;

    std::cout << "Prefix expression tree (non-recursive preorder): ";
    preorderTraversalNonRecursive(prefixTree);
    std::cout << std::endl;

    std::cout << "Prefix expression tree (recursive postorder): ";
    postorderTraversalRecursive(prefixTree);
    std::cout << std::endl;

    std::cout << "Prefix expression tree (non-recursive postorder): ";
    postorderTraversalNonRecursive(prefixTree);
    std::cout << std::endl;

    return 0;
}
