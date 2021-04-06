#include <string>
#include <type_traits>
#include "types.hpp"

template<typename T>
void ValueNode::create_from_primitive(T prim)
{
    // Initialize a node with primitive!
    if (std::is_same<T, int>::value) {
			this->tag = TypeTag::INT;
			this->value = static_cast<int>(prim);

    } else if (std::is_same<T, char>::value) {
			this->tag = TypeTag::CHAR;
			this->value = static_cast<char>(prim);

	} else if (std::is_same<T, char>::value) {
			this->tag = TypeTag::BOOLEAN;
			this->value = static_cast<bool>(prim);

	} else if (std::is_same<T, char>::value) {
			this->tag = TypeTag::STRING;
			this->value = static_cast<std::string>(prim);
	}
}


void ValueNode::accept(NodeVisitor& visitor)
{
	// TODO
}