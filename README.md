# c_cxx_training
This is the main repository for CRT's C/C++ Training. Please see [the tutorial on Confluence](https://confluence.cornell.edu/pages/viewpage.action?pageId=452394372) for instructions

## Prerequisites
For instructions on how to install the prerequisites, see [the preface](https://confluence.cornell.edu/display/crt/Preface%3A+Setting+Up+Your+Environment)
 - **GNU Make** -  Version 3 or higher (might work with lower, idk)
 - **GCC (GNU Compiler Collection)** - Version 5 or higher
 - **Git** - Version 2.17 or higher
 
## Usage
First, clone the repo and check out the branch for the chapter you're working on
```bash
git clone git@github.com:cornellrocketryteam/c_cxx_training.git
git checkout remotes/origin/chptxx # chptxx substituted for the correct chapter
```
All tasks are labeled and explained with comments titled ```PRACTICE TASK``` (or, in the case of Chapter 9, ```PROJECT TASK```). You should complete these for the chapter you're working on.

Once that is completed, you can compile the code by returning to the main directory:
 - ```make <main>``` will compile the code contained in ```<main>.c``` or ```<main>.cc```, depending on whether you're working in C or C++ (with ```<main>``` being substituted for the name of your file). This assumes that ```<main>.c```/```<main>.cc``` contains a ```main``` function, and is therefore located in the ```app``` folder
 - ```make all``` will compile all of the programs in the ```app``` folder
 - All code is compiled to a ```build``` directory
 
## Author
This code was written by [Aidan McNay](https://github.com/Aidan-McNay). If you have any questions, feel free to reach out. Happy programming!
