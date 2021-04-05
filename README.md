# There is more code, not all is commited. Much is private as I am having problems with migrating from another VCS


# clecx
🚀 Clecx -  A compiled language inspired by C and Rust. Current Stage: Bootstrapping

# What even is Clecx?

There currently is a great war (not really): C/C++ vs Rust.
Why not combine them? Why not combine C/C++s great (in my opinion) Memory Managment with Rusts safety and all the other great features that it has?
This is why this was created!



# Current Status:

Bootstrapping: I am currently making an interpreter for the language. The bootstrapper is written in python:

### Why Python, the slowest language, a language that should never be used for interpreters?

Prototyping speed. The stage0 compiler will never be used after I finish it. This is why I do not intend to spend much time on this process. Do not worry. I just want to get something up and running.

### Where is the stage0 compiler?
/stage0

### What is a stage0 compiler?

The bootstrapping process has the following stages:
- Stage 0: preparing an environment for the bootstrap compiler to work with. **<- We are here**
- Stage 1: the bootstrap compiler is produced.
- Stage 2: a full compiler is produced by the bootstrap compiler.
- Stage 3: a full compiler is produced by the stage 2 full compiler.


## An example of the syntax
This does not work yet, this is just a dream of what it might look like :)
Syntax is WIP. We are open for suggestions!

```cpp
#import std::io; // Rust Style Imports - Not a C Style Preprocessor
#import "Filename.clx" // C Style Imports - Not a C Style Preprocessor, just looks like one :)
#define HELLO 10 // Another C Thing :)

struct HelloWorldStruct { // Rust Style Structs
    hey: int,
    world: int,
};

impl HelloWorldStruct { // Rust Style Implementations
    [perms: io] // Permissions work here too :)
    void change_hey_to_ten() {
        self.hey = 10; // self instead of this
    }
}


[requires: my_cool_permission | perms: io] // Multiple attributes 
// ^^^^ If a function requires permissions, you can require them like this. If not satisfied, it will throw an error.
void function() {
    io::println("This is my cool function that required a permission");
}


// The entry
[perms: io, my_cool_permission] // You can grant  permissions to a function like this
int main() { // C Style Return Types
    x: int = 10 // Rust Style Variables
    function(); // Calling the function
    var: HelloWorldStruct*; // Pointers :)
    var->hey = 20; // C Style Pointers
    io::println("{}", var->hey); // Rust Style formatting | '20'
    var->set_hey_to_ten();
    io::println("{}", var->hey) // '10'
    return 1;
}
```

Currently, the stage0 is far from finished. Not all code is commited.
