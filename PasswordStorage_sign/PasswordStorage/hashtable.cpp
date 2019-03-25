#include "hashtable.h"
#include "passwordstorage.h"

#include <vector>
#include <string>
#include <iostream>

struct StorageEntry;

int GetHash1(const std::string& value)
{
    //Возвращает 1
    return 1;
}

int GetHash2(const std::string& value)
{
    //Возвращает ASCII код первой буквы строки
    return (int)value[0];
}

int GetHash3(const std::string& value)
{
    //Возвращает длину строки
    return (int)value.size();
}

int GetHash4(const std::string& value)
{
    //Возвращает сумму ASCII кодов букв строки
    int hash = 0;
    for (size_t i = 0; i < value.size(); ++i)
    {
        hash += (int)value[i];
    }
    return hash;
}

int GetHash5(const std::string& value)
{
    int hash = 0;
    for (size_t i = 0; i < value.size(); ++i)
    {
        hash += (value[i] << 2) * 179;
    }
    return hash;
}

int GetHash6(const std::string& value)
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

HashTable::HashTable(const size_t size)
{
    size_ = size;
    data_.reserve(size_);
    for (int i = 0; i < size_; ++i)
    {
        std::vector<StorageEntry> empty_vector;
        data_.push_back(empty_vector);
    }
}

size_t HashTable::GetSize() const
{
    return size_;
}

int HashTable::GetHash(const StorageEntry& encoded_value) const
{
    return GetHash6(DecodeString(encoded_value.login)) % (int)size_;
}

int HashTable::GetHash(const std::string& login) const
{
    return GetHash6(login) % (int)size_;
}

bool HashTable::Has(const StorageEntry& encoded_value) const
{
    int is_there = 0;
    const int string_hash = this->GetHash(encoded_value);
    std::vector<StorageEntry> container = this->GetData()[string_hash];
    for (size_t i = 0; i < container.size(); ++i)
    {
        if (container[i].login == encoded_value.login)
        {
            return true;
        }
    }
    return false;
}

bool HashTable::Has(const std::string& login) const
{
    int is_there = 0;
    const int string_hash = this->GetHash(login);
    std::vector<StorageEntry> container = this->GetData()[string_hash];
    for (size_t i = 0; i < container.size(); ++i)
    {
        if (DecodeString(container[i].login) == login)
        {
            return true;
        }
    }
    return false;
}

void HashTable::Add(const StorageEntry& encoded_value)
{
    const int string_hash = this->GetHash(encoded_value);
    if (!this->Has(encoded_value))
    {
        this->data_[string_hash].push_back(encoded_value);
    }
}

const std::vector<std::vector<StorageEntry>>& HashTable::GetData() const
{
    return data_;
}