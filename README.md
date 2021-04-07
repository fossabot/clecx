# clecx
🚀 Clecx -  A compiled language inspired by C and Rust. Current Stage: Bootstrapping

# What even is Clecx?

There currently is a great war (not really): C/C++ vs Rust.
Why not combine them? Why not combine C/C++s great (in my opinion) Memory Managment with Rusts safety and all the other great features that it has?
This is why this was created!

## Credits

I learned a lot by reading the source of [Ceres](https://github.com/charpointer/ceres-lang). There are a lot of similarities.

## Types

`str`: Do not worry, there is no `String` and no `&str` do not panic!
`int`: Numbers
`bool`: Booleans

## Progress

The stage0 currently supports these things:

```cpp
#import std::io; // Colons, Doublecolons, sharps, identifiers, ...
// Single Line Comments!

/* Multiline
    Comments
*/

[perms: io] // These cool braces exist too
int main() { // maybe i will add fn main() -> int later :)
    res_print_DO_NOT_USE(); // A reserved print function (You should use io::println)
    res_print_DO_NOT_USE("Hello, World"); // Strings 
    res_print_DO_NOT_USE(`HEllo, WOrld`); // These funny strings

    let x: int; // Keywords like 'let' and 'res_print_DO_NOT_USE'
    x = 20; // Numbers
}
```
It currently only has a lexer, the parser will be added later :)

Good looking errors:
```
Analyzer error[E001]: Something went wrong!
    --> hello.clx:20:4
     |
  20 |     TODO: Get file contents
     |
     |
     | Fix this like this
```


# Current Status:

I am currently making a so-called stage0 compiler
### Where is the stage0 compiler?
[/stage0](/stage0)

### What is a stage0 compiler?
https://en.wikipedia.org/wiki/Bootstrapping_(compilers)#Process


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
