#include <iostream>
#include <string>


// Функция для поиска подстроки с использованием упрощённого алгоритма Рабина-Карпа
int find_substring_light_rabin_karp(const std::string& source, const std::string& substring) 
{
    int n = source.length();
    int m = substring.length();

    if (m > n) 
    {
        return -1; // Подстрока длиннее строки
    }

    // Упрощённая хеш-функция: сумма ASCII-кодов символов
    auto hashFunction = [](const std::string& s) 
        {
        int hash = 0;
        for (char c : s)
        {
            hash += int(c);
        }
        return hash;
        };

    int substringHash = hashFunction(substring); // Хеш подстроки

    for (int i = 0; i <= n - m; i++) {
        std::string currentSubstring = source.substr(i, m); // Текущая подстрока
        int currentHash = hashFunction(currentSubstring); // Хеш текущей подстроки

        if (currentHash == substringHash) 
        {
            // Если хеши совпали, проверяем символы
            if (currentSubstring == substring) 
            {
                return i; // Найдено совпадение
            }
        }
    }

    return -1; // Совпадение не найдено
}

int main() 
{
    setlocale(LC_ALL, "rus");

    std::string source;
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    getline(std::cin, source); // Считываем строку для поиска

    while (true) 
    {
        std::string substring;
        std::cout << "Введите подстроку, которую нужно найти: ";
        getline(std::cin, substring); // Считываем подстроку

        if (substring == "exit")
        {
            // Проверяем подстроку "exit" перед завершением
            int result = find_substring_light_rabin_karp(source, substring);
            if (result != -1) 
            {
                std::cout << "Подстрока exit найдена по индексу " << result << std::endl;
            }
            else 
            {
                std::cout << "Подстрока exit не найдена" << std::endl;
            }
            break; // Завершаем программу
        }

        // Ищем подстроку в строке
        int result = find_substring_light_rabin_karp(source, substring);
        if (result != -1)
        {
            std::cout << "Подстрока " << substring << " найдена по индексу " << result << std::endl;
        }
        else 
        {
            std::cout << "Подстрока " << substring << " не найдена" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
