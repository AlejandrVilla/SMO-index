#ifndef __K2_TREE_H__
#define __K2_TREE_H__

#include <string>
#include <vector>

class K2Tree
{
private:
    std::vector<int> tree;
    std::vector<int> leaves;
    std::vector<int> labels;
    int n;
public:
    K2Tree(std::vector<std::vector<int>> matrix);
    void insert(int x, int y);

    int rank(int p, int i);
    int select(int p, int i);

    void direct(int n, int p, int q, int x);
    void reverse(int n, int p, int q, int x);

    int build(std::vector<std::vector<int>> a, std::vector<std::vector<int>> & T, int m, int l, int p, int q);
    void print_data();
};

#endif  // __K2_TREE_H__