# Compiling on Mac OS

This chapter is a quick introduction to getting Scribus to compile on Mac OS. It's written for users who already know how to compile code and want to know the few details that are specific to Scribus.

If Scribus is the first software you're compiling, this chapter can still be very useful, but you will need to look up a few things (or ask question in the community) while reading it.

## Requirements

To get Scribus compiled you'll need a recent version of Mac OS and Home Brew.

Currently, you can compile Scribus from the command line or use Qt Creator.

## Getting the code

You can get the code from the Scribus own Subversion repository

```sh
svn co svn://scribus.net/trunk/Scribus scribus
```

or from one of the community maintained mirrors:

- From the Github mirror:  
  `git clone git@github.com:scribusproject/scribus.git` or
  `git clone https://github.com/scribusproject/scribus.git`
- From the Gitlab mirror:   
  `git@gitlab.com:scribus/scribus.git` or
  `https://gitlab.com/scribus/scribus.git`

### Forking the code for development

If you plan to work on the Scribus code and are using Git, you should create and clone your own fork of the [scribus repository](https://github.com/scribusproject/scribus):

- Most likely, you will need to setup your system and your Github account to use ssh keys: https://help.github.com/articles/connecting-to-github-with-ssh/
- Use the "Fork" button at the top of the [scribus repository](https://github.com/scribusproject/scribus) to create your own fork.
- Clone your own copy of Scribus: `git clone https://github.com/your-username/scribus.git`

For more details please read [Github's forkin manual](https://help.github.com/articles/fork-a-repo/).

## Compiling from the command line

Historically, compiling from the command line has been the most straighforward and common way for compiling Scribus. The alternative is to use Qt Creator, as explained in a separate chapter.

Four _simple_ steps are needed for compiling Scribus from the command line:

- Setup the directory structure for an _out of source_ build.
- Configure and run CMake.
- Run make.
- Make install.

You should compile Scribus out of source and install it inside of your home directory.

We will assume that you have your source code in `~/src/` and your own binaries in `~/bin/` (where `~/` is your home). You will have to adapt the instructions if your paths are different.

First we need to create a `build` directory inside of the Scribus sources:

```sh
$ cd ~/src/scribus
$ mkdir build/
$ cd build/
```

From the `build` directory, run the `cmake` command:

```sh
$ cmake -DCMAKE_INSTALL_PREFIX:PATH=~/bin/scribus -DWANT_DEBUG=1 -DWANT_GUI_LANG="en_GB;de;fr;it;en" ..
```
```

With these options, CMake will prepare a build that:

- will be installed in `~/bin/scribus`,
- has the debug symbols enabled,
- will only install a smaller set of languages (pick the ones are useful to you).

If you get any error, it's very likely that they're due to missing development packages (you need the `-dev` header files on top of the usual packages).  
In the case the packages are installed but the version is too old, you'd better consider retrying with a distribution that provides more up to date packages (Debian Testing and the latest Ubuntu are generally speaking fine).

You can retry until `cmake` runs successfully. In some cases you will have to delete the `build/` directory, recreate it, and restart from scratch.

Once `cmake` has run successfully, you can now _make_ Scribus.

```sh
make -j4
```

The `-j4` tells `make` to use 4 threads. Use `-j2` or no `-j` at all on older machines.

Before being able to run Scribus, you will need to install it.

```sh
make install
cd ~/bin/scribus/bin/
./scribus
```

## If the compilation fails

### It does not `cmake`

- Is the `cmake` version new enough?
- Get the output from `cmake` by redirecting it to a file:
  `cmake .. >> cmake-log.txt 2>&1`  
  upload it to a pastebin and show it to the _experts_ in the community.
