## _printf()
> In this project, we tried to create a mini-verison of the ```printf``` function found in
> the `stdio.h` library in the C programming language. This function allows
> us to print some arguments given to the standard output or terminal and similar
> printing functions can be found in any programming language. This means we can
> print any combinations of strings, intergers, and other different data types.

### Synopsis
> This repository holds all the code necessary for our custom ```_printf```
> function to run. Our mini-version currently handles conversion specifiers:
> ```c```, ```s```, ```%```, ```d```, ```i```, ```b```, ```o``` and does not yet
> support field width, precision, flag characters, or length modifiers.  

### Description of what each file shows:
```
basic_printf.c ---------------------------- holds custom _printf function
main.h ------------------------ holds prototypes of functions spread across all files
_putchar.c ------------------------------ holds custom putchar function 
```
### Environment
* Language: C
* OS: Ubuntu 20.04 LTS
* Compiler: gcc 
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

### To Do
* The main _printf function can be separated into more modular shorter functions
* More functionality can still be added (e.g. support field width specifiers, etc)

---
### Authors
* James Wachira
* Neemoh Muigai
