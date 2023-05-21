//
// Created by Andreea on 19-May-23.
//

#include "exceptii.h"

exceptie_lista_tari_goala::exceptie_lista_tari_goala(const std::string& message) : message_(message) {}

const char* exceptie_lista_tari_goala::what() const noexcept {
    return message_.c_str();
}

exceptie_index_depaseste::exceptie_index_depaseste(const std::string& message) : message_(message) {}

const char* exceptie_index_depaseste::what() const noexcept {
    return message_.c_str();
}
