#pragma once
#include <LinkedList.h>

template <typename T>
class Pattern {
public:
    Pattern() : _size(0), _name(nullptr), _pattern(0) {} // Constructeur par défaut

    Pattern(int size, const char *name) :
        _size(size),
        _name(name),
        _pattern(0b1111111111111111)
    {}

    // Constructeur de copie
    Pattern(const Pattern<T>& other) :
        _size(other._size),
        _name(other._name),
        _pattern(other._pattern)
    {}

    // Opérateur d'affectation
    Pattern<T>& operator=(const Pattern<T>& other) {
        if (this != &other) {
            _size = other._size;
            _name = other._name;
            _pattern = other._pattern;
        }
        return *this;
    }

    const char* getName()
    {
        return this->_name;
    }

    void setPattern(const T& data)
    {
        this->_pattern = data;
    }

    T getPattern()
    {
        return this->_pattern;
    }

    void setPatternAt(int index, int value)
    {
        if (index >= this->_size) {
            return;
        }
        this->_pattern |= (value << index);
    }

    int getPatternAt(int index)
    {
        if (index >= this->_size) {
            return -1;
        }
        return (this->_pattern >> index) & 1;
    }

    void clear()
    {
        this->_pattern = 0;
    }

private:
    int _size;
    const char *_name;
    T _pattern;
};