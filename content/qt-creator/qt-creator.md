# Using Qt Creator with Scribus

## Getting and compiling Scribus

### Getting the Scribus project

Qt Creator can _automatically_ fetch and compile the Scribus code from the Github mirror.

When creating the new project, just give the address:

```
git@github.com:scribusproject/scribus.git
```
Qt Creator will detect the `cmake` configuration and start compiling Scribus.

## Using multiple cores

By default Qt Creator compiles with only one core. If you want to improve the compilation speed, you can edit the project's configuration to ask gcc to build in parallel.

On Linux and OS X, look for the "Build" settings of the current "Project" , and ensure that in the "Build environment" you have a `MAKEFLAGS` Environment variable that says `-j4`.

![Set MAKEFLAGS to -j4](images/qt-creator-make-j4.png)


You can change the `4` to a value gives you nice compile times, while matching the number of the cores in your computer.

## Installing Scribus before running it

Once Qt Creator has built Scribus, you can run it with the "Run" command.

Before being able to run Scribs, you need to install it (otherwise it won't find its resources). In order to install it, you need to add a "Deploy Step" to the Deployment configuration of the Run settings.

In the "Add deploy step" action, pick the "Build" option and the `install` "Tool argument" for the "install" target: 

![Set the `CMAKE_INSTALL_PREFIX` ](images/qt-creator-cmake-install-step.png)


## The target install directory

By default, Qt Creator installs Scribus in `/usr/local`, which on most systems needs the user to be `root` (and that's not a good idea...).

You can change the target in the "Project"'s "Build and Run" configuration:

![Set the `CMAKE_INSTALL_PREFIX` ](images/qt-creator-cmake-install-prefix.png)

Personally, I mostly use a `bin/scribus` directory in my home, but you can also use a `bin` directory in the build directory created by Qt Creator (`~/src/build-scribus-qt-creator-Desktop-Default/bin`).