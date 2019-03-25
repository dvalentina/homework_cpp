#pragma once

#include <iostream>
#include "hashtable.h"

std::string EncodeString(const std::string& string_to_encode);
std::string DecodeString(const std::string& string_to_decode);

/*struct StorageEntry
{
    std::string login;
    std::string password;
};*/

class PasswordStorage
{
public:
    PasswordStorage(const size_t size);
    void PrintStorage() const;
    void TellPassword() const;
    void ChangeStoragePassword();
    void Add(const StorageEntry& user);
    int GetPasswordHash6() const;
private:
    HashTable hashtable_;
    int password_hash6_;
};