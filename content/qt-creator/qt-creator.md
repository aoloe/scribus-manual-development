# Using Qt Creator with Scribus

## Getting and compiling Scribus

Qt Creator can _automatically_ fetch and compile the Scribus code from the Github mirror.

When creating the new project, just give the address:

```
git@github.com:scribusproject/scribus.git
```

## Using multiple cores

By default Qt Creator compiles with only one core. If you want to improve the compilation speed, you can edit the project's configuration to ask gcc to build in parallel.

On Linux and OS X, look for the "Build" settings of the current "Project" , and ensure that in the "Build environment" you have a `MAKEFLAGS` Environment variable that says `-j4`.

![Set MAKEFLAGS to -j4](images/qt-creator-make-j4.png)


You can change the `4` to a value gives you nice compile times, while matching the number of the cores in your computer.
