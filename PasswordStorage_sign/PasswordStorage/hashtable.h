#pragma once

#include <iostream>
#include <vector>
#include <string>

struct StorageEntry;

int GetHash1(const std::string& value);
int GetHash2(const std::string& value);
int GetHash3(const std::string& value);
int GetHash4(const std::string& value);
int GetHash5(const std::string& value);
int GetHash6(const std::string& value);

class HashTable
{
public:
    HashTable(const size_t size);
    int GetHash(const StorageEntry& encoded_value) const;
    int GetHash(const std::string& login) const;
    bool Has(const StorageEntry& encoded_value) const;
    bool Has(const std::string& login) const;
    void Add(const StorageEntry& encoded_value);
    const std::vector<std::vector<StorageEntry>>& GetData() const;
    size_t GetSize() const;
private:
    std::vector<std::vector<StorageEntry>> data_;
    size_t size_ = 0;
};