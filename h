#include "BinarySearchTree.h"


/**
 *This is the copy constructor which is the copy of the original
 * the length of is 0
 * the root is equal to nullptr
 * @tparam DataType this is a temp
 * @param rhs
 */
    template<class DataType>
    BinarySearchTree<DataType>::BinarySearchTree(const BinarySearchTree<DataType> &rhs)
    {
     //Copy Constructor
        length = 0;
        root = nullptr;
        deepCopy (rhs.root);
    }




/**
 * This the the original copy constructor where length is set to 0
 * The root is also set to nullptr
 * @tparam DataType
 */

template<class DataType>
BinarySearchTree<DataType>::BinarySearchTree()
   {
    //This is the deconstructor
    length=0;
    root = nullptr;
   }

/*
 * The purpose of this function is to delete all 3 nodes
 */
template<class DataType>
BinarySearchTree<DataType>::~BinarySearchTree()
   {

    deleteAll(root);
   }


/**
 * The simply tells the value in the length
 * @tparam DataType
 * @return the length
 */

template<class DataType>
int BinarySearchTree<DataType>::getLength()
   {
   // return 0;
   //this returns the value of the length
   return length;
   }


/**
 *
 * @tparam DataType
 * @param item
 * @return true if its found
 */
template<class DataType>
bool BinarySearchTree<DataType>::putItem(const DataType &item)
  {
    if(root ==nullptr)
    {
        root = new Node<DataType>;// a node node is created
        root->value = item; //value gets stores
        length++; //increment
        return true;
    }
    //ending if
    return insert(root,item);
   }


/**
 * The getitem gets searched until found
 * The variable here is set to return the find function
 * @tparam DataType
 * @param item
 * @param found_item
 * @return true if found otherwise false if not found
 */

template<class DataType>
bool BinarySearchTree<DataType>::getItem(const DataType &item, DataType &found_item)
   {

    Node<DataType>* found = find(root, item);
    if (found!= nullptr)
    {
        found_item = found->value; //this here copys the value into found_value
            return true; //it would return true
    }
            else{
                return false; //otherwise not, then returns false
            }
   }


/** This function isFull tells if the BST tree is full or not
*
* @tparam DataType
* @return false if its full
*/
template<class DataType>
bool BinarySearchTree<DataType>::isFull()
  {
    //if the binary search tree is full then it will return false
    return false;
  }


/**The makeempty function empties all the elements
 * In the queue
 * @tparam DataType
 */
template<class DataType>
void BinarySearchTree<DataType>::makeEmpty()
 {
    //this makes the tree empty
    length = 0; //length is set to 0
    deleteAll(root); //deletes all
    root = nullptr;

 }

 /**
  * The resetlist makes the queue in order
  * @tparam DataType
  */

template<class DataType>
void BinarySearchTree<DataType>::resetList() {
    // this is a nice fast way to reset the queue to blank
    // std::queue<int> empty;
    // std::swap( inOrder, empty );
    std::queue<DataType> empty;
    std:swap(inOrder, empty);
    loadQueueInOrder(root);
}

/**
 * This function sets item to the front and it sets in front of queue
 * @tparam DataType
 * @param item
 * @return false if full or deleted then delete
 */
template<class DataType>
bool BinarySearchTree<DataType>::getNextItem(DataType &item) {

        if(inOrder.empty()) {
            return false;
        }
      //item is set at the front of the queue
        item= inOrder.front();

        inOrder.pop(); //deletes
        return true;
    }

//2nd part



//continuing section 1 here
//this is copied from the header
/**
 * inserts item
 * @tparam DataType
 * @param tree
 * @param item
 * @return true if fits
 */
template<class DataType>
bool BinarySearchTree<DataType>::insert(Node<DataType> *tree, const DataType &item) {
    if (tree->value == item) {
        return false;
        //this side is for the left side of the binary search tree
    } else if (item < tree->value) {
        if (tree->left == nullptr) {
            tree->left = new Node<DataType>;
            tree->left->value = item;
            length++;//the length is the number of nodes in the tree
            return true;
        } else {
            return insert(tree->left, item);
        }
    }
    else if(item > tree->value){
        if(tree->right == nullptr){
            tree->right = new Node<DataType>;
            tree->right->value =item; //not sure if its supposed to be there
            tree->right->value = item;
            length++;//the length is the number of nodes in the tree
            return true;
        }else{
            return insert(tree->right, item);
        }
    }
}
//this is copied from the header
/**
 * The fucntion searches for the item through the whole tree
 * @tparam DataType
 * @param tree
 * @param item
 * @return true if found otherwise not
 */
template<class DataType>
Node<DataType>* BinarySearchTree<DataType>::find(Node<DataType>* tree, const DataType &item){
    if(tree==nullptr) {
        return nullptr;

    }
    if(tree->value ==item){
        return tree;

    } else if (item<tree->value) {
        return (find(tree->left, item));

    }else {
        return (find(tree->right, item));
    }

}

//this is copied from the header
/**
 * This functions deletes the whole tree
 * @tparam DataType
 * @param tree
 */
template<class DataType>
void BinarySearchTree<DataType>::deleteAll(const Node<DataType>* tree)
{
    //to delete all this function will delete all of the tree from right and left side

    if(tree==nullptr) {
        return;
    }
    deleteAll(tree->right); //deletes right node
    deleteAll(tree->left);// deletes left node
    delete tree; //if node has 2 children then it deletes the tree
}

/**
 * The loadQueueInorder prints out the tree in order
 * @tparam DataType
 * @param tree
 * it will keep the left side with the minimum and the right to maximum
 */
template<class DataType>
void BinarySearchTree<DataType>:: loadQueueInOrder(Node<DataType>* tree) {
    //if the queue is empty then it will return false
    if (tree == nullptr) {
        return;

    }

    loadQueueInOrder(tree->left);//this goes to the left
     inOrder.push(tree->value);
    loadQueueInOrder(tree->right);//this goes to the right side of the current node
}


/**
 *
 * @tparam DataType
 * @param found_item
 * @return
 */

template<class DataType>
bool BinarySearchTree<DataType>::min(DataType &found_item) {
    if (root == nullptr) {
        return false;
    }

    Node<DataType> *temp = min(root);
    found_item = temp->value;
    return true;
}

//2nd part
template<class DataType>
bool BinarySearchTree<DataType>::max(DataType &found_item) {
    if (root == nullptr) {
        return false;
    }

    Node<DataType>* temp = max(root);
    found_item = temp->value;
    return true;

}

/////////////
//2nd part
template<class DataType>
bool BinarySearchTree<DataType>::deleteItem(const DataType &item)
{
    if(root == nullptr)
        return false;

    Node<DataType>* dead = remove(root,item, nullptr);
    if(dead==nullptr)
    return false;
    else
    {
        delete(dead);
        length--;
        return true;
    }
}

//template<class DataType>
//void BinarySearchTree<DataType>::operator=(const BinarySearchTree<DataType> &rhs) {
//    deleteAll(root);
//    copyTree(rhs);
//}
//


