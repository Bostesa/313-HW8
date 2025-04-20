# Matrix Library Implementation in C and C++ 
## AUTHORING 
- Nathan Samson
- UMBC CMSC 313 / Spring 2025 
## PURPOSE OF SOFTWARE: 
Matrix library that solves: D = A + (3 * B) × C^T with given matrices. 
## FILES 
- `Matrix1.h`: C++ Matrix class with operators and methods 
- `Matrix.h/c`: C implementation of matrix operations (C99) 
- `cpp_test.cpp`: Tests C++ implementation 
- `c_test.c`: Tests C implementation 
- `Makefile`: Builds both implementations 
## BUILD INSTRUCTIONS 
```bash 
make all 
``` 
## RUNNING THE CODE 
```bash 
./cpp_test 
```
```bash 
./c_test 
``` 
## TESTING METHODOLOGY: 
Both implementations calculate D = A + (3 * B) × C^T step by step. 
