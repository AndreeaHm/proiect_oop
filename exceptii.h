//
// Created by Andreea on 19-May-23.
//

#ifndef PRJCT_OOP_EXCEPTII_H
#define PRJCT_OOP_EXCEPTII_H

#include <exception>
#include <string>

class exceptie_baza : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override = 0;
    ~exceptie_baza() override = default;
};

class exceptie_lista_tari_goala : public exceptie_baza {
    std::string message_;

public:
    explicit exceptie_lista_tari_goala(const std::string& message);

    [[nodiscard]] const char* what() const noexcept override;
};

class exceptie_index_depaseste : public exceptie_baza {
    std::string message_;

public:
    explicit exceptie_index_depaseste(const std::string& message);

    [[nodiscard]] const char* what() const noexcept override;
};

#endif //PRJCT_OOP_EXCEPTII_H
