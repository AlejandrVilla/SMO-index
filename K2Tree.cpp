#include "K2Tree.h"
#include <math.h>
#include <iostream>
#include <algorithm>

K2Tree::K2Tree(std::vector<std::vector<int>> matrix)
{
    this->n = matrix.size();
    std::vector<std::vector<int>> T(std::ceil(std::log2(n)) + 1);
    this->build(matrix,T,n,1,0,0);

    for (int i = 1; i < std::ceil(std::log2(n)); i++)
    {
        this->tree.insert(this->tree.end(), T[i].begin(), T[i].end());
    }
    this->leaves = T[std::ceil(std::log2(n))];
}   

int K2Tree::build(std::vector<std::vector<int>> a, std::vector<std::vector<int>> & T , int m, int l, int p, int q)
{
    std::vector<int> C;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (l == std::ceil(std::log2(n)) || m == 1)
            {
                if (a[p + i][q + j] != 0) 
                {
                    C.push_back(1);
                    this->labels.push_back(a[p + i][q + j]);
                }
                else C.push_back(0);
            }
            else
            {
                C.push_back(build(a, T, m / 2, l + 1, p + i * (m / 2), q + j * (m / 2)));
            }
        }
    }
    if (C == std::vector<int>({0,0,0,0})) return 0;
    T[l].insert(T[l].end(), C.begin(), C.end());

    return 1;
}

void K2Tree::insert(int x, int y)
{
    int div = 1;
    int start_level = 0;
    int end_level = 4;
    int varmys = 0;
    int aa = 0;
    int offset = 0;
    int prev_of = 0;
    while (div < this->n)
    {
        varmys = 0;


        if (this->n <= x && this->n <= y)
        {
            aa = start_level + offset * 4 + 1;
        }
        else if (this->n <= x && this->n > y)
        {
            aa = start_level + offset * 4 + 3;
        }
        else if (this->n > x && this->n <= y)
        {
            aa = start_level + offset * 4 + 0;
        }
        else
        {
            aa = start_level + offset * 4 + 2;
        }
        for (int i = start_level; i <=  aa; i++)
        {
            offset += tree[i] - '0';
        }
        
        // Counting all ones in a level
        for (int i = start_level; i < end_level; i++)
        {
            varmys += tree[i] - '0';
        }
        start_level = end_level;
        end_level = end_level + 4 * varmys;

    }
}

int K2Tree::rank(int p, int i)
{
    int count = 0;
    for (int j = 0; j <= i; j++)
    {
        if (p == this->tree[j]) count++;
    }
    return count;
}

int K2Tree::select(int p, int i)
{
    int count = 0;
    for (int j = 0; j <= this->tree.size(); j++)
    {
        if (this->tree[j] == p) count++;
        if (count == i) return j;
    }
    return -1;
}


void K2Tree::direct(int n, int p, int q, int x)
{
    if (x >= this->tree.size())
    {
        if (this->leaves[x - this->tree.size()] == 1)
        {
            std::cout << q << ' ';
        }
    }
    else
    {
        if (x == -1 || this->tree[x] == 1)
        {
            int y = rank(1,x) * 4 + 2 * std::floor(p / (n / 2));
            for (int i = 0; i <= 1; i++)
            {
                this->direct(n/2, p % (n/2), q + (n/2) * i, y + i);
            }
        }
    }
}


void K2Tree::reverse(int n, int q, int p, int x)
{
    if (x >= this->tree.size())
    {
        if (this->leaves[x - this->tree.size()] == 1)
        {
            std::cout << p << ' ';
        }
    }
    else
    {
        if (x == -1 || this->tree[x] == 1)
        {
            int y = rank(1,x) * 4 + std::floor(q / (n / 2));
            for (int i = 0; i <= 1; i++)
            {
                this->direct(n/2, q % (n/2), p + (n/2) * i, y + i * 2);
            }
        }
    }
}


void K2Tree::print_data()
{
    std::cout << "Tree: ";
    for (int i = 0; i < this->tree.size(); i++)
    {
        if (i % 4 == 0) std::cout << ' ';
        std::cout << this->tree[i];
    }

    std::cout << "\nLeaves: ";
    for (int i = 0; i < this->leaves.size(); i++)
    {
        if (i % 4 == 0) std::cout << ' ';
        std::cout << this->leaves[i];
    }

    std::cout << "\nLabels: ";
    for (int i = 0; i < this->labels.size(); i++)
    {
        std::cout << this->labels[i];
    }
}