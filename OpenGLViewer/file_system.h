#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include "root_directory.h"
#include <stdexcept>

class FileSystem
{
private:
    typedef std::string(*Builder) (const std::string& path);

public:
    static std::string getPath(const std::string& path)
    {
        static std::string(*pathBuilder)(std::string const&) = getPathBuilder();
        return (*pathBuilder)(path);
    }
    static std::string const& getRoot2() {
        return getRoot();
    }


private:
    static std::string const& getRoot()
    {
        if (logl_root == "") {
            std::cerr<<"Please configure root path in root_directory.h"<<std::endl;
            return "";
        }
        static char const* givenRoot = logl_root;
        static std::string root = (givenRoot != nullptr ? givenRoot : "");
        return root;
    }

    //static std::string(*foo (std::string const &)) getPathBuilder()
    static Builder getPathBuilder()
    {
        if (getRoot() != "")
            return &FileSystem::getPathRelativeRoot;
        else
            return &FileSystem::getPathRelativeBinary;
    }

    static std::string getPathRelativeRoot(const std::string& path)
    {
        return getRoot() + std::string("/") + path;
    }

    static std::string getPathRelativeBinary(const std::string& path)
    {
        return "../../../" + path;
    }


};

// FILESYSTEM_H
#endif