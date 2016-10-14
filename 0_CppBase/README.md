Two websites recommended by students(Thanks to Darien Sokolov):

* Space/Time Complexities: http://bigocheatsheet.com/
* Sorting Algorithms: https://www.toptal.com/developers/sorting-algorithms

**Note: Please use the online materials wisely, depending on the specific situation where you are trying to apply the knowledge from them, you should have your own judgement on whether it is appropriate to use them or trust them.**


https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm

https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm

https://www.tutorialspoint.com/cplusplus/cpp_pointers_vs_arrays.htm



http://www.learncpp.com/cpp-tutorial/713-command-line-arguments/

Using command line arguments

Now that you know how to provide command line arguments to a program, the next step is to access them from within our C++ program. To do that, we use a different form of main() than we’ve seen before. This new form of main() takes two arguments (named argc and argv by convention) as follows:
```
int main(int argc, char *argv[])
```
You will sometimes also see it written as:

```
int main(int argc, char** argv)
```
Even though these are treated identically, we prefer the first representation because it’s intuitively easier to understand.

argc is an integer parameter containing a count of the number of arguments passed to the program (think: argc = argument count). argc will always be at least 1, because the first argument is always the name of the program itself. Each command line argument the user provides will cause argc to increase by 1.

argv is where the actual argument values are stored (think: argv = argument values, though the proper name is “argument vectors”). Although the declaration of argv looks intimidating, argv is really just an array of C-style strings. The length of this array is argc.

Let’s write a short program named “MyArgs” to print the value of all the command line parameters:
```
// Program: MyArgs
#include <iostream>
 
int main(int argc, char *argv[])
{
    std::cout << "There are " << argc << " arguments:\n";
 
    // Loop through each argument and print its number and value
    for (int count=0; count < argc; ++count)
        std::cout << count << " " << argv[count] << '\n';
 
    return 0;
}
```
Now, when we invoke this program (MyArgs) with the command line arguments “Myfile.txt” and “100”, the output will be as follows:
```
There are 3 arguments:

0 C:\MyArgs
1 Myfile.txt
2 100 " "}
```


