/*
** EPITECH PROJECT, 2022
** day11
** File description:
** Toy
*/

#include "Toy.hpp"
#include <iostream>

Toy::Toy() : _name {new std::string("toy")}, _picture {new Picture()}, _type {BASIC_TOY}
{
}

Toy::Toy(ToyType type, const std::string &name, const std::string &fp)
{
    this->_type = type;
    this->_name = new std::string(name);
    this->_picture = new Picture(fp);
}

Toy::Toy(const Toy &toy)
{
    this->_type = toy.getType();
    this->_name = new std::string(toy.getName());
    this->_picture = new Picture(*toy._picture);
    this->_err = new Error("", "", Error::UNKNOWN);
}

Toy &Toy::operator=(const Toy &toy)
{
    if (this != &toy) {
        // delete this->_picture;
        // delete this->_name;
        this->_picture = new Picture(*toy._picture);
        this->_type = toy.getType();
        this->_name = new std::string(toy.getName());
    }
    return *this;
}

Toy::ToyType Toy::getType() const
{
    return this->_type;
}

std::string Toy::getName() const
{
    return *this->_name;
}

void Toy::setName(const std::string &name)
{
    this->_name = new std::string(name);
}

bool Toy::setAscii(const std::string &file)
{
    bool test = this->_picture->getPictureFromFile(file);
    if (!test)
        this->_err = new Error("bad new illustration", "setAscii", Error::PICTURE);
    return test;
}

std::string Toy::getAscii() const
{
    return *this->_picture->data;
}

bool Toy::speak(const std::string &sentence)
{
    std::cout << *this->_name << " \"" << sentence << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(const std::string &sentence)
{
    (void)sentence;
    _err = new Error("wrong mode", "speak_es", Error::SPEAK);
    return false;
}

Toy &Toy::operator<<(const std::string &name)
{
    this->_picture->data = new std::string(name);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    return os << toy.getName() << std::endl << toy.getAscii() << std::endl;
}


std::string Toy::Error::what() const
{
    return *this->message;
}

std::string Toy::Error::where() const
{
    return *this->func;
}

Toy::Error Toy::getLastError()
{
    if (this->_err == nullptr)
        return (*new Error("", "", Error::UNKNOWN));
    return *this->_err;
}