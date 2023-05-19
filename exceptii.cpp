//
// Created by Andreea on 19-May-23.
//

#include "exceptii.h"

exceptie1::exceptie1(const std::string& message) : message_(message) {}

const char* exceptie1::what() const noexcept {
    return message_.c_str();
}

exceptie2::exceptie2(const std::string& message) : message_(message) {}

const char* exceptie2::what() const noexcept {
    return message_.c_str();
}
