//
// Created by Andreea on 19-May-23.
//

#ifndef PRJCT_OOP_EXCEPTII_H
#define PRJCT_OOP_EXCEPTII_H

#include <exception>
#include <string>

class exceptie1 : public std::exception {
    std::string message_;
public:
    explicit exceptie1(const std::string& message);

    [[nodiscard]] const char* what() const noexcept override;
};

class exceptie2 : public std::exception {
    std::string message_;
public:
    explicit exceptie2(const std::string& message);

    [[nodiscard]] const char* what() const noexcept override;
};

#endif //PRJCT_OOP_EXCEPTII_H
