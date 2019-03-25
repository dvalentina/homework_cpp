#include <iostream>

#include "passwordstorage.h"
#include "hashtable.h"


std::string EncodeString(const std::string& string_to_encode)
{
    std::string encoded_string = string_to_encode;

    for (int i = 0; i < encoded_string.size(); i++)
    {
        encoded_string[i] += (i + 1);
    }

    return encoded_string;
}

std::string DecodeString(const std::string& string_to_decode)
{
    std::string decoded_string = string_to_decode;

    for (int i = 0; i < decoded_string.size(); i++)
    {
        decoded_string[i] -= (i + 1);
    }

    return decoded_string;
}

PasswordStorage::PasswordStorage(const size_t size) : hashtable_(size)
{
    password_hash6_ = 4481;
}

int PasswordStorage::GetPasswordHash6() const
{
    return password_hash6_;
}

void PasswordStorage::Add(const StorageEntry& user)
{
    hashtable_.Add(user);
}

void PasswordStorage::PrintStorage() const
{
    std::cout << "The Password Storage";
    bool is_first = true;
    for (size_t i = 0; i < hashtable_.GetSize(); ++i)
    {
        const std::vector<StorageEntry> container = hashtable_.GetData()[i];
        if (container.size() != 0)
        {
            if (is_first == true)
            {
                std::cout << ":" << std::endl;
                is_first = false;
            }
            std::cout << "Login: " << DecodeString(container[0].login) << " Password: " << DecodeString(container[0].password) << std::endl;
        }
    }
    if (is_first == true)
    {
        std::cout << " is empty." << std::endl;
    }
}

void PasswordStorage::TellPassword() const
{
    std::cout << "Enter the login:" << std::endl;
    std::string login;
    std::cin >> login;
    if (hashtable_.Has(login) == true)
    {
        int login_hash = hashtable_.GetHash(login);
        std::cout << "Password: " << DecodeString(hashtable_.GetData()[login_hash][0].password) << std::endl;
    }
    else
    {
        std::cout << "I haven't found this login." << std::endl;
    }
}

void PasswordStorage::ChangeStoragePassword()
{
    std::cout << "Enter new password:" << std::endl;
    std::string new_password;
    std::cin >> new_password;
    password_hash6_ = GetHash6(new_password);
}