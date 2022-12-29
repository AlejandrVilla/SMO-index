#ifndef __K2_TREE_H__
#define __K2_TREE_H__

#include <string>
#include <vector>

class K2Tree
{
public:
    std::vector<int> tree;
    std::vector<int> leaves;
    std::vector<int> labels;
    int n;
    int k;
public:
    K2Tree(std::vector<std::vector<int>> matrix, int _k);
    void insert(int x, int y);
    bool child_i(int i, int& x);

    int rank(int p, int i);
    int select(int p, int i);

    void direct(int n, int p, int q, int x);
    void reverse(int n, int p, int q, int x);

    int build(std::vector<std::vector<int>> a, std::vector<std::vector<int>> & T, int m, int l, int p, int q);
    void print_data();
};

#endif  // __K2_TREE_H__