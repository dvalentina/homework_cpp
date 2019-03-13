#pragma once

#include <iostream>
#include <vector>
#include <string>

int GetHash1(const std::string value);
int GetHash2(const std::string value);
int GetHash3(const std::string value);
int GetHash4(const std::string value);
int GetHash5(const std::string value);
int GetHash6(const std::string value);

class HashTable
{
public:
    HashTable();
    int GetHash(const std::string& value) const;
    bool Has(const std::string value) const;
    void Add(const std::string& value);
    std::vector<std::vector<std::string>> GetData() const;
    void Remove(const std::string& value);
    size_t GetSize();
private:
    std::vector<std::vector<std::string>> data_;
    size_t size_ = 1013;
};