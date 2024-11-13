//
// Created by Rylan Cody on 11/11/24. file will contain all relevant code for an AVL Tree
//

#ifndef LIBRARYPROJECT_AVLTREE_HPP
#define LIBRARYPROJECT_AVLTREE_HPP

#endif //LIBRARYPROJECT_AVLTREE_HPP

//Node for AVL Tree
template <typename T>
class AVLNode {
public:
    //Constructors
    AVLNode(void) {
        this->data = nullptr;
        this->height = -1;
        this->left = nullptr;
        this-right = nullptr;
    }

    AVLNode(T data, AVLNode<T>* left, AVLNode<T>* right) {
        this->data = data;
        this->height = 0;
        this->left = left;
        this->right = right;
    }

    AVLNode(const T& data) {
        this->data = data;
        this->height = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    //Destructor
    ~AVLNode() {
        delete left;
        delete right;
    }

    //Accessors
    T& getData(void) {
        return data;
    }

    int getHeight(void) {
        return height;
    }

    AVLNode<T>* getLeft(void) {
        return left;
    }

    AVLNode<T>* getRight(void) {
        return right;
    }

    //Mutators
    void setData(T& newData) {
        this->data = newData;
    }

    void setHeight(int newHeight) {
        this->height = newHeight;
    }

    void setLeft(AVLNode<T>* newLeft) {
        this->left = newLeft;
    }

    void setRight(AVLNode<T>* newRight) {
        this->right = newRight;
    }

private:
    T data; //data being held by node
    int height; //height of node
    AVLNode* left; //nodes left child
    AVLNode* right; //nodes right child
};

//Tree for AVL Tree
template <typename T>
class AVLTree {
public:
    //constructors
    AVLTree(void);
    explicit AVLTree(AVLNode<T>* root);
    explicit AVLTree(AVLTree<T>*& copy);

    //destructors
    ~AVLTree(void);

    //accessors
    AVLNode<T>* getRoot(void);

    //mutators
    void setRoot(AVLNode<T>* newRoot);

    //others
    void deleteTree(AVLNode<T>* root);

    bool contains(const T& x) const;
    void insert(const T& x);
    void remove(const T& x);
    int computeHeight(void) const;
private:
    AVLNode<T>* root; //root for the tree

    //others
    bool contains(const T& x, AVLNode<T>* node) const;
    void insert(const T& x, AVLNode<T>*& node);
    void remove(const T& x, AVLNode<T>*& node);
    void balance(AVLNode<T>*& node);
    int computeHeight(AVLNode<T>* node) const;

    void leftRotate(AVLNode<T>*& k2);
    void rightRotate(AVLNode<T>* k2);
    void leftDouble(AVLNode<T>*& k3);
    void rightDouble(AVLNode<T>* k3);
};

//constructors
template <typename T>
AVLTree<T>::AVLTree(void) {
    this->root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(AVLNode<T>* root) {
    this->root = root;
}

template <typename T>
AVLTree<T>::AVLTree(AVLTree<T>*& copy) {
    this->root = copy->root;
}

//destructors
template <typename T>
AVLTree<T>::~AVLTree() {
    deleteTree(root);
}

template <typename T>
void AVLTree<T>::deleteTree(AVLNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    //delete subtrees
    deleteTree(root->getLeft());
    deleteTree(root->getRight());

    //delete root
    delete root;
}

//accessors
template <typename T>
AVLNode<T>* AVLTree<T>::getRoot() {
    return root;
}

//mutators
template <typename T>
void AVLTree<T>::setRoot(AVLNode<T>* newRoot) {
    this->root = newRoot;
}

//others. public implementation will always go before private implementation
template <typename T>
bool AVLTree<T>::contains(const T& x) const {

}

template <typename T>
bool AVLTree<T>::contains(const T& x, AVLNode<T>* node) const {

}

template <typename T>
void AVLTree<T>::insert(const T& x) {

}

template <typename T>
void AVLTree<T>::insert(const T& x, AVLNode<T>*& node) {

}

template <typename T>
void AVLTree<T>::remove(const T& x) {

}

template <typename T>
void AVLTree<T>::remove(const T& x, AVLNode<T>*& node) {

}


template <typename T>
int AVLTree<T>::computeHeight() const {

}

template <typename T>
int AVLTree<T>::computeHeight(AVLNode<T>* node) const {

}

template <typename T>
void AVLTree<T>::balance(AVLNode<T>*& node) {

}

template <typename T>
void AVLTree<T>::leftRotate(AVLNode<T> *&k2) {

}

template <typename T>
void AVLTree<T>::rightRotate(AVLNode<T> *k2) {

}

template <typename T>
void AVLTree<T>::leftDouble(AVLNode<T> *&k3) {

}

template <typename T>
void AVLTree<T>::rightDouble(AVLNode<T> *k3) {

}

