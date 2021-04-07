#[path = "token.rs"]
mod token;

pub struct NodeVisitor {

}

pub struct Node {

}

// Node Trait
pub trait NodeT {
    fn accept(visitor: NodeVisitor);
}

enum ASTType {
    INT,
    BOOL,
    STRING,
    CHAR,
}

pub struct IdentNode {
    pub value: String,
}

impl IdentNode {
    pub fn new(value: String) {
        let node = IdentNode {
            value: value,
        };
    }
}


// Primitive Values
pub struct ValNode<T> {
    val_type: ASTType,
    pub value: T,
}

impl NodeT for ValNode<i32> {
    fn accept(visitor: NodeVisitor) {

    }
}

impl NodeT for ValNode<String> {
    fn accept(visitor: NodeVisitor) {
        
    }
}

impl NodeT for ValNode<char> {
    fn accept(visitor: NodeVisitor) {
        
    }
}

impl NodeT for ValNode<bool> {
    fn accept(visitor: NodeVisitor) {
        
    }
}


impl ValNode<i32> {
    pub fn new(val: i32) -> ValNode<i32> {
        let node = ValNode {
            value: val,
            val_type: ASTType::INT,
        };
        return node;
    }
}

impl ValNode<bool> {
    pub fn new(val: bool) -> ValNode<bool> {
        let node = ValNode {
            value: val,
            val_type: ASTType::BOOL,
        };
        return node;
    }
}

impl ValNode<String> {
    pub fn new(val: String) -> ValNode<String> {
        let node = ValNode {
            value: val,
            val_type: ASTType::STRING,
        };
        return node;
    }
}

impl ValNode<char> {
    pub fn new(val: char) -> ValNode<char> {
        let node = ValNode {
            value: val,
            val_type: ASTType::CHAR,
        };
        return node;
    }
}

// Expression Nodes
pub struct ExprNode {
    left: Node,
    right: Node,
    opc: token::Token,
}

impl NodeT for ExprNode {
    fn accept(visitor: NodeVisitor) {
        
    }
}

// Variable Deceleration Node
pub struct VarDeclNode<T> {
    constant: bool,
    name: String,
    val: ValNode<T>,
}

impl<T> VarDeclNode<T> {
    pub fn new(constant: bool, name: String, val: ValNode<T>) -> VarDeclNode<T> {
        let result = VarDeclNode {
            constant: constant,
            name: name,
            val: val
        };
        return result;
    }
}

pub struct VarAssNode<T> {
    name: String,
    val: ValNode<T>
}

impl<T> VarAssNode<T> {
    pub fn new(val: ValNode<T>, name: String) -> VarAssNode<T> {
        let result = VarAssNode<T> {
            name: name,
            val: val,
        };
        return result;
    }
}