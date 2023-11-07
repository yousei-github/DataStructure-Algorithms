<p align="center">
  <h1 align="center"> Data Structures and Algorithms in C++ & Python </h1>
</p>

# About This Project
This project is based on the book ["Data Structures and Algorithms in C++"](https://www.wiley.com/en-sg/Data+Structures+and+Algorithms+in+C%2B%2B%2C+2nd+Edition-p-9780470383278), ["Intro to Python for Computer Science and Data Science: Learning to Program with AI, Big Data and The Cloud"](https://www.pearson.com/store/p/intro-to-python-for-computer-science-and-data-science-learning-to-program-with-ai-big-data-and-the-cloud-global-edition/P200000004063/9781292364902).


# Build and debug the C++ program

Before starting to build or debug this project, you might need to be familiar with [the visual studio code tutorial](https://code.visualstudio.com/docs/cpp/config-linux). Also, a C++11 compiler is required for compilation.

## Build
Build methods are explained below.

### 1. Visual Studio Code-based method.
- You may need to modify the compiler's path in the `tasks.json` file in the `.vscode` directory.
- Click `Run Build Task` in the `Terminal` tab.

### 2. Command line-based method.
By referring the contents of `tasks.json` file in the `.vscode` directory, input the below command,
```
$ [COMPILER] -O3 -g -Wall -fopenmp -I project_directory/inc/ -I project_directory/Cplusplus/include/ -I project_directory/Cplusplus/include/LinkedLists/ 
project_directory/Cplusplus/source/LinkedLists/*.cpp project_directory/Cplusplus/source/*.cpp
-o project_directory/Cplusplus/bin/project_entry_O3
```
where [COMPILER] is the compiler's name, such as g++.

## Debug
Debug methods are explained below.

### 1. Visual Studio Code-based method.
- You may need to modify the debugger's path in the `launch.json` file in the `.vscode` directory.
- Click `Start Debugging` in the `Run` tab.

### 2. Command line-based method.
By referring the contents of `launch.json` file in the `.vscode` directory, input the below command,
```
(waiting for updating)
```

# Run C++ program
According to the build setting in the `/tasks.json` file, input the command like,
```
Cplusplus/bin/project_entry
```
where [project_entry] is the executable file's name.

# Miscellaneous

...
