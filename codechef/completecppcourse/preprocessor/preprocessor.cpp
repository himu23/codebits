/*
Preprocessor directives are special commands that start with a hash symbol (#).
They are processed by the preprocessor before the compilation of the program begins. 

They are used to perform various tasks like including header files, defining macros, and conditional compilation.
*/
/*

//    #include <header>: This directive includes the content of the specified header file in the code.
    For example: #include <stdio.h> includes the standard input/output library.
//    #define identifier value: This directive defines a macro where identifier is replaced by value throughout the code.
    For example: #define PI 3.14159.
//    #ifdef identifier: Checks if the identifier is defined.
    If it is, the code between #ifdef and #endif is included during compilation.
//    #ifndef identifier: Checks if the identifier is not defined.
    If it is not, the code between #ifndef and #endif is included during compilation.
//    #if condition: Conditionally compiles code based on the given condition.
    For example: #if X > Y.
//    #else and #endif: Used in combination with #ifdef, #ifndef, and #if to define alternate code paths.

*/