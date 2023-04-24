#include "SegTree.h"
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

/*********************** SegNode *************************/

SegNode::SegNode(){
  this->cars = -1;
  this->date_time = "Null";
}

SegNode::SegNode(int cars, std::string date_time){
    this->cars = cars;
    this->date_time = date_time;
}

SegNode::~SegNode(){
}

// getters
int SegNode::get_cars(){
  return this->cars;
}

std::string SegNode::get_date_time(){
  return this->date_time;
}

// setters
void SegNode::set_cars(int cars){
  this->cars = cars;
}

void SegNode::set_date_time(std::string date_time){
  this->date_time = date_time;
}


/*********************** SegTree *************************/

/* Constructor */
// Creates SegTree and uses utility fillTree to populate it
SegTree::SegTree(std::vector<SegNode> nodes){

  // Tree Height
  int h = (int)(ceil(log2(nodes.size())));
  //std::cout << "h : " << h << std::endl;
  // Max size of segment tree
  int max_size = 2 * (int)pow(2, h) -1;

  // node array
  std::vector<SegNode> *tree = new std::vector<SegNode>;
  tree->resize(max_size);
  this->size = max_size;

  // Fill tree
  fillTree(nodes, 0, nodes.size()-1, tree, 0);

  this->seg_tree = tree;
}

// Destructor
SegTree::~SegTree(){
}

/* Utiltiy */

// Recursive function to populate the tree 
SegNode SegTree::fillTree(std::vector<SegNode> nodes, int seg_start, int seg_end, std::vector<SegNode>* tree, int seg_idx){

  // If array size is 1 store it in current node of segment tree and return
  if(seg_start == seg_end){
      tree->at(seg_idx) = nodes[seg_start];
      return nodes[seg_start];
  }

  // If there are more than one elements, then recur for the left and right
  // subtrees and store the max of the values in this node

  int mid = calcMid(seg_start, seg_end); // prob use int mid for index tree nodes

  SegNode n1 = fillTree(nodes, seg_start, mid, tree, seg_idx * 2 + 1);
  SegNode n2 = fillTree(nodes, mid+1, seg_end, tree, seg_idx * 2 + 2);

  // set node at index to the max of the two nodes
  n1.cars > n2.cars ? tree->at(seg_idx) = n1 : tree->at(seg_idx) = n2;

  return tree->at(seg_idx);
}

// Calc middle of indexs
int SegTree::calcMid(int start, int end){
  return start + (end - start) / 2;
}

// Recursive function retreiving max
SegNode SegTree::treeMaxUtil(std::vector<SegNode>* tree, int seg_start, int seg_end, int left, int right, int node){
  // If segment of this node is completely part of the given range,
  // then return the max of the segment

  if(left <= seg_start && right >= seg_end){
    return tree->at(node);
  }

  // If segment of this node does not belong to given range
  if(seg_end < left || seg_start > right){
    return SegNode();
  }

  // If segment of this node is partially the part of the given range
  int mid = calcMid(seg_start, seg_end);

  SegNode n1 = treeMaxUtil(tree, seg_start, mid, left, right, 2 * node + 1);
  SegNode n2 = treeMaxUtil(tree, mid + 1, seg_end, left, right, 2 * node + 2); 
  return (n1.cars > n2.cars ? n1 : n2);
}

// Initial call validation for max within range of tree
SegNode SegTree::treeMax(std::vector<SegNode>* tree, int n, int left, int right){

  // Check for erroreous input values
  if(left < 0 || right > n - 1 || left > right){
    std::cout << "Invalid Input: ";
    return SegNode();
  }

  return treeMaxUtil(tree, 0, n - 1, left, right, 0);
}

// Recursive function to update the given index with new SegNode
void SegTree::update(std::vector<SegNode> nodes, std::vector<SegNode>* tree, int seg_start, int seg_end, int seg_idx, SegNode value, int node){
  if(seg_idx < seg_start || seg_idx > seg_end){
    std::cout << "Invalid Input" << std::endl;
    return;
  }
  if(seg_start == seg_end){
    nodes[seg_idx] = value;
    tree->at(node) = value;
  }
  else{
    int mid = calcMid(seg_start, seg_end);
    if(seg_idx >= seg_start && seg_idx <= mid){
      update(nodes, tree, seg_start, mid, seg_idx, value, 2 * node + 1);
    }
    else{
      update(nodes, tree, mid + 1, seg_end, seg_idx, value, 2 * node + 2);
    }
    SegNode n1 = tree->at(2 * node + 1);
    SegNode n2 = tree->at(2 * node + 2);

    tree->at(node) = (n1.cars > n2.cars ? n1 : n2);
  }
  return;
}

/* Getters */
int SegTree::getSize(){
  return this->size;
}

std::vector<SegNode>* SegTree::getTree(){
  return this->seg_tree;
}

/* Setters */
void SegTree::setSize(int size){
  this->size = size;
}

void SegTree::setTree(std::vector<SegNode> *seg_tree){
  this->seg_tree = seg_tree;
}

/* Debug */
void SegTree::printTree(){

  std::cout << "print tree size: " << this->seg_tree->size() << std::endl;

  std::vector<SegNode>::iterator it = this->seg_tree->begin();
  std::cout << "[";
  for(int i = 0; i < this->getSize(); i++){
    std::cout << it->cars;
    i < this->getSize()-1 ? std::cout << ", " : std::cout << "]\n\n";
    it++;
  }
}

void SegTree::printDot(){

  std::cout << "print tree size: " << this->seg_tree->size() << std::endl;
  
  std::vector<std::string> valid;

  std::vector<SegNode>::iterator it = this->seg_tree->begin();
  for(int i = 0; i < this->getSize(); i++){
    std::cout << "Node" << i << "[label=" << it->cars << "]\n";
    valid.push_back("Node" + std::to_string(i));
    it++;
    while(it->cars == -1){
      i++;
      it++;
    }
  }

  for(int i = 0; i < this->getSize(); i++){
    for(int j = i * 2; j < i * 2 + 2; j++){
      if(std::find(valid.begin(), valid.end(), "Node" + std::to_string(j+1)) != valid.end()){
        std::cout << "Node" << i << " -> " << "Node" << j+1 << std::endl;
      }
      if(j*2+2 == this->getSize()){
        break;
      }
    }
  }
}

// Dot File
void SegTree::genDot(){
  std::ofstream dotFile("output.dot");
  dotFile << "digraph G {" << std::endl;
  
  std::vector<std::string> valid;

  std::vector<SegNode>::iterator it = this->seg_tree->begin();
  for(int i = 0; i < this->getSize(); i++){
    dotFile << "Node" << i << "[label=" << it->cars << "]\n";
    valid.push_back("Node" + std::to_string(i));
    it++;
    while(it->cars == -1){
      i++;
      it++;
    }
  }

  dotFile << std::endl;

  for(int i = 0; i < this->getSize(); i++){
    for(int j = i * 2; j < i * 2 + 2; j++){
      if(std::find(valid.begin(), valid.end(), "Node" + std::to_string(j+1)) != valid.end()){
        dotFile << "Node" << i << " -> " << "Node" << j+1 << std::endl;
      }
      if(j*2+2 == this->getSize()){
        break;
      }
    }
  }

  dotFile << "}" << std::endl;
  dotFile.close();
}