#include <iostream>
#include "Forest.h"
#include "matrix_struct.h"

std::ostream& operator<<(std::ostream& output_stream, const Forest& forest)
{
    output_stream << forest.GetForest();
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
    for (size_t i = 0; i < this->forest_.GetHeight(); ++i)
    {
        for (size_t j = 0; i < this->forest_.GetWidth(); ++j)
        {
            switch (this->forest_.GetState(i, j))
            {
            case NORMAL_TREE:
                int fire_quantity = 0;
                for (size_t m = -1; m < 2; ++m)
                {
                    for (size_t n = -1; n < 2; ++n)
                    {
                        switch (this->forest_.GetState(i + m, j + n))
                        {
                        case TREE_IN_FIRE:
                            fire_quantity += 1;
                            break;
                        case NORMAL_TREE:
                            break;
                        case BURNT_TREE:
                            break;
                        }
                    }
                }
                this->forest_.SetElapsedTime(i, j, this->forest_.GetElapsedTime(i, j) - fire_quantity);

                if (this->forest_.GetElapsedTime(i, j) == 0)
                {
                    this->forest_.SetState(i, j, TREE_IN_FIRE);
                    this->forest_.SetElapsedTime(i, j, 12);
                }

                break;
            case TREE_IN_FIRE:
                this->forest_.SetElapsedTime(i, j, this->forest_.GetElapsedTime(i, j) - 1);

                if (this->forest_.GetElapsedTime(i, j) == 0)
                {
                    this->forest_.SetState(i, j, BURNT_TREE);
                    this->forest_.SetElapsedTime(i, j, 20);
                }

                break;
            case BURNT_TREE:
                this->forest_.SetElapsedTime(i, j, this->forest_.GetElapsedTime(i, j) - 1);

                if (this->forest_.GetElapsedTime(i, j) == 0)
                {
                    this->forest_.SetState(i, j, NORMAL_TREE);
                    this->forest_.SetElapsedTime(i, j, 10);
                }
                break;
            }
        }
    }
}