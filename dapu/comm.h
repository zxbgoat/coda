#pragma once
#include <set>
#include <map>
#include <cmath>
#include <array>
#include <vector>
#include <iostream>

using std::set;
using std::map;
using std::array;
using std::vector;
using std::unordered_map;

using std::swap;
using std::endl;
using std::cout;

struct TreeNode
{
    int val;
    vector<TreeNode*> children;
};
