#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>

class FileManager {
public:
    FileManager();
    ~FileManager();

    void loadContent(const char* filename, std::vector<std::vector<std::string>> &attributes,
                     std::vector<std::vector<std::string>> &contents);
protected:
private:
    std::vector<std::string> tempAttributes;
    std::vector<std::string> tempContent;
};

#endif // FILEMANAGER_H
