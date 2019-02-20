#pragma once

#include "matrix_struct.h"
class Forest
{
public:
    Forest(const size_t height, const size_t width);
    Forest Update();
    Matrix GetForest() const;
private:
    Matrix forest_;
};
    
enum tree_state { NORMAL_TREE, TREE_IN_FIRE, BURNT_TREE };

struct Tree
{
    tree_state curr_state;
    int elapsed_time;
};

std::ostream& operator<<(std::ostream& output_stream, const Forest& forest);