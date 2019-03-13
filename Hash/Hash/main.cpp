#include "hashtable.h"

#include <fstream>

std::string TrimWord(const std::string& raw_word)
{
    size_t begin_pos = 0;
    size_t word_length = raw_word.npos;

    for (size_t i = 0; i < raw_word.size(); i++)
    {
        if (isalpha(raw_word[i]))
        {
            begin_pos = i;
            break;
        }
    }

    for (size_t i = begin_pos; i < raw_word.size(); i++)
    {
        if (!isalpha(raw_word[i]))
        {
            word_length = i - begin_pos;
            break;
        }
    }

    return raw_word.substr(begin_pos, word_length);
}

int main()
{
    HashTable hash_table;

    std::ifstream input_file("cano.txt");
    for (std::string word; input_file >> word; )
    {
        hash_table.Add(TrimWord(word));
    }

    std::ofstream output_file("output.txt");
    for (size_t i = 0; i < hash_table.GetSize(); ++i)
    {
        output_file << hash_table.GetData()[i].size() << std::endl;
    }
    return 0;
}