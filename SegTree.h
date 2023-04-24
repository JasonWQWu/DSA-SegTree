#pragma once

#include <iostream>
#include <vector>


class SegNode{
  private:
    int cars;
    std::string date_time;

  public:
    // Constructor
    SegNode();
    SegNode(int cars, std::string date_time);
    ~SegNode();

    // getters
    int get_cars();
    std::string get_date_time();
    
    // setters
    void set_cars(int cars);
    void set_date_time(std::string date_time);


  friend class SegTree;
};



class SegTree{
private:
  int size;
  std::vector<SegNode> *seg_tree;

public:
  // Constructor
  SegTree(std::vector<SegNode> nodes);
  ~SegTree();

  // Utitly Functions
  SegNode fillTree(std::vector<SegNode> nodes, int seg_start, int seg_end, std::vector<SegNode>* tree, int seg_idx);
  int calcMid(int start, int end);
  SegNode treeMaxUtil(std::vector<SegNode>* tree, int seg_start, int seg_end, int left, int right, int node);
  SegNode treeMax(std::vector<SegNode>* tree, int n, int left, int right);
  void update(std::vector<SegNode> nodes, std::vector<SegNode>* tree, int seg_start, int seg_end, int seg_idx, SegNode value, int node);

  // Getters
  int getSize();
  std::vector<SegNode> *getTree();
  
  // Setters
  void setTree(std::vector<SegNode> *seg_tree);
  void setSize(int size);
  
  // Debug
  void printTree();
  void printDot();
  void genDot();

};