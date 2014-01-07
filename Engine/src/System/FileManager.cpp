#include "System/FileManager.h"

FileManager::FileManager() {
    //ctor
}

FileManager::~FileManager() {
    //dtor
}

enum loadState { ATTRIBUTES, CONTENT };

int state;

void FileManager::loadContent(const char* filename, std::vector<std::vector<std::string>> &attributes,
                              std::vector<std::vector<std::string>> &contents) {
    std::ifstream openFile(filename);
    if (openFile.is_open()) {
        while (!openFile.eof()) {
            std::string line;

            std::getline(openFile, line);

            line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

            if (line.find("Load=") != std::string::npos) {
                state = ATTRIBUTES;
                line.erase(0, line.find('=') + 1);
                tempAttributes.clear();
            } else {
                state = CONTENT;
                tempContent.clear();
            }

            line.erase(std::remove(line.begin(), line.end(), '['), line.end());

            std::stringstream str(line);

            while (str) {
                std::getline(str, line, ']');
                if (line != "") {
                    if (state == ATTRIBUTES)
                        tempAttributes.push_back(line);
                    else
                        tempContent.push_back(line);
                }
            }

            if (state == CONTENT && tempContent.size() > 0) {
                attributes.push_back(tempAttributes);
                contents.push_back(tempContent);
            }


        }
    } else {

    }
}
