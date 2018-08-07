# Ft_printf
Ft_printf is the first project in the Algorithms and Artificial Intelligence branch at 42 School Silicon Valley. In this project, I was asked to create a function which replicates the Stdio library "Printf" function. In this function, we needed to take care of almost all the specifiers (excluding the floating type), all the flags, the lengths, the different widths, and precisions. The common structure for printf is:

%[flags][width][.precision][length]specifier

## My Approach
In order to do this project, I worked all the time with pointers to my data so it runs faster because I am not actually sending the data, just the address to it. The algorithm that I prepared runs inside a while loop which goes character by character through the format string printing the chars, but when it founds a '%' it triggers the arguments functions. After this is triggered I run the following logic: 

##### 1. Get all the possible information
The first step to print a function argument is to know what you are going to print and in which format. So I go through the chars after '%' one by one checking for flags, width, precision, length and storing this information in a structure which will be useful later.

##### 2. Prepare a string to print
In this part of the program, the algorithm is branched into different processes depending on the type of specifier read, this is done with the objective of making the program run faster. Once the program knows which specifier was sent it is sent into a special function which will create a string with the argument given and the format specified. After creating the string, it is manipulated to apply precision, width, and flags. Then this string is returned and to print.

##### 3. Printing
The process of printing is divided into two paths, one for normal char strings and other for wide chars (Unicode), but the process is basically the same: go through the whole string printing each char and each time it prints a char it adds to the count variable which is returned at the end of the function.

##### BONUS
Like in most 42 School Projects there is always the possibility to go further and in this case, my bonus was to create an extra specifier which prints numbers in binary. It also supports all the flags, width, lengths and precisions in order to make as any other specifier. 

## Prerequisites
There is no prerequisite to using these functions. All the files needed are included.

## Installing and Running
There are two options to use this repo, one is to use a test file that I already created or the other is to get the library and the header file and include it in any other project of your own. 
##### To run the test file I made use:
1. Clone the repository
```
git clone https://github.com/JuanCasian/42-Ft_printf.git
```
2. Go into the cloned folder and execute the following command, which will compile the files, create the library and the test program.
```
make test
```
3. Run the executable
```
./test
```
4. If you wish you can modify the test.c file and print anything else. After doing so just use the same command as before.
5. In order to clean the test files run
```
make testclean
```
##### If you wish to use the function in your own file:
1. Compile the library
```
make all
```
2. Copy the libftprintf.a library which is located inside the libs folder and ft_printf.h header file which is inside the includes folder.
3. Paste wherever in your project folder and compile using
```
gcc -[flags] -L./[library directory] -lftprintf -I./[includes directory]
```
[flags] = Any compilation flags you use
[library directory] = path to the directory in which the libftprintf.a file is located
[includes directory] = path to the directory in which the ft_printf.h file is located

## Information Sources
- http://www.cplusplus.com/reference/cstdio/printf/
- man printf(3)

## Author
Juan Pedro Casian - Github: [@JuanCasian](https://github.com/JuanCasian) - Email: juanpedrocasian@gmail.com
