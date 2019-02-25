#include <iostream>
#include "Forest.h"
#include "matrix_struct.h"

std::ostream& operator<<(std::ostream& output_stream, const Forest& forest)
{
    output_stream << forest.GetForest();
    return output_stream;
}

Forest::Forest(const size_t height, const size_t width)
    : forest_(height, width)
{
}

Matrix Forest::GetForest() const
{
    return this->forest_;
}

Forest Forest::Update()
{
    int forest_height = int(this->forest_.GetHeight());
    int forest_width = int(this->forest_.GetWidth());
    for (int y = 0; y < forest_height; y++)
    {
        for (int x = 0; x < forest_width; x++)
        {
            int burn_neighbours_count = 0;
            for (int i = y - 1; i <= y + 1; i++)
            {
                for (int j = x - 1; j <= x + 1; j++)
                {
                    if (i < 0 || i >= forest_height || j < 0
                        || j >= forest_width || (j == x && i == y))
                    {
                        continue;
                    }
                    else
                    {
                        if (this->forest_.GetState(i, j) == TREE_IN_FIRE)
                        {
                            burn_neighbours_count++;
                        }
                    }
                }
            }
            int time = this->forest_.GetElapsedTime(y, x);
            int new_time = 0;
            tree_state state = this->forest_.GetState(y, x);

            if (state == NORMAL_TREE)
            {
                new_time = time - burn_neighbours_count; 
            }
            else if (state == TREE_IN_FIRE)
            {
                new_time = time - 1;
            }
            else if (state == BURNT_TREE)
            {
                new_time = time - 1;
            }

            if (new_time <= 0)
            {
                if (state == NORMAL_TREE)
                {
                    this->forest_.SetState(y, x, TREE_IN_FIRE);
                    this->forest_.SetElapsedTime(y, x, 12);
                }
                else if (state == TREE_IN_FIRE)
                {
                    this->forest_.SetState(y, x, BURNT_TREE);
                    this->forest_.SetElapsedTime(y, x, 6);
                }
                else if (state == BURNT_TREE)
                {
                    this->forest_.SetState(y, x, NORMAL_TREE);
                    this->forest_.SetElapsedTime(y, x, 10);
                }
            }
            else
            {
                this->forest_.SetElapsedTime(y, x, new_time);
            }
        }
    }
    return *this;
}