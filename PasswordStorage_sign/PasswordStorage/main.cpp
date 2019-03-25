#include <iostream>
#include <string>

#include "passwordstorage.h"
#include "hashtable.h"

void Start();
void FillPasswordStorage(PasswordStorage& password_storage);
void WelcomeToPasswordStorage(PasswordStorage& password_storage);
bool CheckPassword(const std::string& password, const PasswordStorage& password_storage);
void OpenMenu(PasswordStorage& password_storage);

int main()
{
    Start();
    return 0;
}

void Start()
{
    const size_t size_of_storage = 1013;
    PasswordStorage password_storage(size_of_storage);
    FillPasswordStorage(password_storage);
    WelcomeToPasswordStorage(password_storage);
}

void FillPasswordStorage(PasswordStorage& password_storage)
{
    StorageEntry first_user;
    first_user.login = "gkvlmn";
    first_user.password = "x6w7w";
    password_storage.Add(first_user);

    StorageEntry second_user;
    second_user.login = "lkwipg{";
    second_user.password = "n2xw8";
    password_storage.Add(second_user);

    StorageEntry third_user;
    third_user.login = "eqjkt";
    third_user.password = "x23j|67n";
    password_storage.Add(third_user);
}

void WelcomeToPasswordStorage(PasswordStorage& password_storage)
{
    std::cout << "===============================" << std::endl;
    std::cout << "Welcome to Password Storage!" << std::endl;
    std::cout << "Enter the password to access:" << std::endl;
    std::string password;
    std::cin >> password;
    if (CheckPassword(password, password_storage) == true)
    {
        OpenMenu(password_storage);
    }
    else
    {
        std::cout << "Incorrect password." << std::endl;
        WelcomeToPasswordStorage(password_storage);
    }
}

bool CheckPassword(const std::string& password, const PasswordStorage& password_storage)
{
    if (GetHash6(password) == password_storage.GetPasswordHash6())
    {
        return 1;
    }
    return 0;
}

void OpenMenu(PasswordStorage& password_storage)
{
    std::cout << "===============================" << std::endl;
    std::cout << "What do you want me to do?" << std::endl;
    std::cout << "To print all logins and passwords, please enter 1." << std::endl;
    std::cout << "To print the password of exact login, please enter 2." << std::endl;
    std::cout << "To change the password for the Password Storage, please enter 3." << std::endl;
    enum TheChoice { PRINT_STORAGE = 1, TELL_PASSWORD = 2, CHANGE_STORAGE_PASSWORD = 3 };
    int user_input = 0;
    std::cin >> user_input;
    switch (user_input)
    {
    case 1:
        password_storage.PrintStorage();
        OpenMenu(password_storage);
        break;
    case 2:
        password_storage.TellPassword();
        OpenMenu(password_storage);
        break;
    case 3:
        password_storage.ChangeStoragePassword();
        WelcomeToPasswordStorage(password_storage);
        break;
    default:
        std::cout << "Incorrect input." << std::endl;
        OpenMenu(password_storage);
        break;
    }
}