#include <iostream>
#include <string>


// ������� ��� ������ ��������� � �������������� ����������� ��������� ������-�����
int find_substring_light_rabin_karp(const std::string& source, const std::string& substring) 
{
    int n = source.length();
    int m = substring.length();

    if (m > n) 
    {
        return -1; // ��������� ������� ������
    }

    // ���������� ���-�������: ����� ASCII-����� ��������
    auto hashFunction = [](const std::string& s) 
        {
        int hash = 0;
        for (char c : s)
        {
            hash += int(c);
        }
        return hash;
        };

    int substringHash = hashFunction(substring); // ��� ���������

    for (int i = 0; i <= n - m; i++) {
        std::string currentSubstring = source.substr(i, m); // ������� ���������
        int currentHash = hashFunction(currentSubstring); // ��� ������� ���������

        if (currentHash == substringHash) 
        {
            // ���� ���� �������, ��������� �������
            if (currentSubstring == substring) 
            {
                return i; // ������� ����������
            }
        }
    }

    return -1; // ���������� �� �������
}

int main() 
{
    setlocale(LC_ALL, "rus");

    std::string source;
    std::cout << "������� ������, � ������� ����� �������������� �����: ";
    getline(std::cin, source); // ��������� ������ ��� ������

    while (true) 
    {
        std::string substring;
        std::cout << "������� ���������, ������� ����� �����: ";
        getline(std::cin, substring); // ��������� ���������

        if (substring == "exit")
        {
            // ��������� ��������� "exit" ����� �����������
            int result = find_substring_light_rabin_karp(source, substring);
            if (result != -1) 
            {
                std::cout << "��������� exit ������� �� ������� " << result << std::endl;
            }
            else 
            {
                std::cout << "��������� exit �� �������" << std::endl;
            }
            break; // ��������� ���������
        }

        // ���� ��������� � ������
        int result = find_substring_light_rabin_karp(source, substring);
        if (result != -1)
        {
            std::cout << "��������� " << substring << " ������� �� ������� " << result << std::endl;
        }
        else 
        {
            std::cout << "��������� " << substring << " �� �������" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}