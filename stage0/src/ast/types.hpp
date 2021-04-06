#pragma once
#include <cstddef>
#include <string>

#include "node.hpp"

enum class TypeTag {
    INT,
    CHAR,
    STRING,
    BOOLEAN,
};



struct ValueNode: ASTNode {
public:
    TypeTag tag;
    union {
        int int_val;
        char char_val;
        bool bool_val;
        std::string str_val;
    } value;
    
    virtual void accept(NodeVisitor& visitor);
    
    template<typename T>
    void create_from_primitive(T prim);
};
