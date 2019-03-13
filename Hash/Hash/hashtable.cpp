#include "hashtable.h"

#include <vector>
#include <string>
#include <iostream>

int GetHash1(const std::string value)
{
    //Возвращает 1
    return 1;
}

int GetHash2(const std::string value)
{
    //Возвращает ASCII код первой буквы строки
    return (int)value[0];
}

int GetHash3(const std::string value)
{
    //Возвращает длину строки
    return (int)value.size();
}

int GetHash4(const std::string value)
{
    //Возвращает сумму ASCII кодов букв строки
    int hash = 0;
    for (size_t i = 0; i < value.size(); ++i)
    {
        hash += (int)value[i];
    }
    return hash;
}

int GetHash5(const std::string value)
{
    int hash = 0;
    for (size_t i = 0; i < value.size(); ++i)
    {
        hash += (value[i] << 2) * 179;
    }
    return hash;
}

int GetHash6(const std::string value)
{
    int hash = 0;
    if (value.size() == 0)
    {
        hash = 0;
    }
    else if (value.size() == 1)
    {
        hash = (int)value[0];
    }
    else
    {
        for (size_t i = 2; i < value.size(); ++i)
        {
            hash = (hash << 1) ^ value[i];
        }
    }
    return hash;
}

HashTable::HashTable()
{
    data_.reserve(size_);
}

size_t HashTable::GetSize()
{
    return size_;
}

int HashTable::GetHash(const std::string& value) const
{
    return GetHash1(value) % (int)size_;
}

bool HashTable::Has(const std::string value) const
{
    int is_there = 0;
    int string_hash = this->GetHash(value);
    std::vector<std::string> container = this->GetData()[string_hash];
    for (size_t i = 0; i < container.size(); ++i)
    {
        if (container[i] == value)
        {
            return true;
        }
    }
    return false;
}

void HashTable::Add(const std::string& value)
{
    int string_hash = this->GetHash(value);
    if (!this->Has(value))
    {
        this->data_[string_hash].push_back(value);
    }
}

std::vector<std::vector<std::string>> HashTable::GetData() const
{
    return data_;
}

void HashTable::Remove(const std::string& value)
{
    int string_hash = this->GetHash(value);
    std::vector<std::string> container = this->GetData()[string_hash];
    for (size_t i = 0; i < container.size(); ++i)
    {
        if (container[i] == value)
        {
            container.erase(container.begin() + i);
        }
    }
}