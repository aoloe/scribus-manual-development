# Compiling on Linux

This chapter is a quick introduction to getting Scribus to compile on Linux. It's written for users who already know how to compile code and want to know the few details that are specific to Scribus.

If Scribus is the first software you're compiling, this chapter can still be very useful, but you will need to look up a few things (or ask question in the community) while reading it.

## Requirements

To get Scribus compiled you'll need a Linux distribution with up to date packages (the latest Ubuntu release, Debiant testing or Sid, ...) or Mac OS X with Home Brew.

Currently, you can compile Scribus from the command line or use Qt Creator.

Before starting compiling Scribus, you should make sure that all dependencies are met.

## Compiling from the command line

Historically, compiling from the command line has been the most straighforward and common way for compiling Scribus. The alternative is to use Qt Creator, as explained in a [separate chapter](compiling-with-qt-creator-en.md).

Four _simple_ steps are needed for compiling Scribus:

- Setup the directory structure for an _out of source_ build.
- Configure and run CMake.
- Run make.
- Make install.

You should compile Scribus out of source and install it inside of your home directory.

At this point we also assume that you have [downloaded the Scribus source code](getting-the-code-en.md) into `~/src/scribus/`.

We will assume that you have your source code in `~/src/` and your own binaries in `~/bin/` (where `~/` is your home). You will have to adapt the instructions if your paths are different.

First we need to create a `build` directory inside of the Scribus sources and switch into it:

```sh
$ cd ~/src/scribus
$ mkdir build/
$ cd build/
```

From inside of the `build` directory, run the `cmake` command:

```sh
$ cmake -DCMAKE_INSTALL_PREFIX:PATH=~/bin/scribus -DWANT_DEBUG=1 ..
```

With these options, CMake will prepare a build that:

- will be installed in `~/bin/scribus`,
- has the debug symbols enabled.

If you get any error, it's very likely that they're due to missing development packages (on Debian derivatives, you need the `-dev` header files on top of the usual packages).  
In the case the packages are installed but the version is too old, you'd better consider retrying with a distribution that provides more up to date packages (Debian Testing and the latest Ubuntu are always fine).

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

You can create a symlink in `/usr/local/bin` if you want to be able to run it from the terminal or the launcher.  
You will have to use a different name (like `scribus-dev`) if you already have Scribus installed.

```sh
sudo ln -s ~/bin/scribus/bin/scribus /usr/local/bin/scribus-dev
```

If you modify the Scribus source code, you will need to run:

```sh
make
make install
```

to compile and install your changes.

## Compiling with Qt Creator

If you are not comfortable with the command line, you can use Qt Creator to compile Scribus.

Please refer to the section below, dedicated to [Qt Creator](compiling-with-qt-creator-en.md).


## If the compilation fails

### It does not `cmake`

- Is the `cmake` version new enough?
- Get the output from `cmake` by redirecting it to a file:  
  `cmake .. >> cmake-log.txt 2>&1`  
  upload it to a pastebin and show it to the _experts_ in the community.

## Adding a plugin from a Github repository

If you want to use or improve a plugin that has its own Github repository, you can download its code and add it to the Scribus code.

We suggest you to first carefully read the plugin's README file.  

On top of the specific instructions you get in the README files, this section explains with two examples -- the API and Epub plugins -- how to get the plugins to be compiled with Scribus.

First you'll have to clone the repository in the directory where you're storing the code you compile (as previously stated we assume here that it's `~/src/~).  
Then, you'll clone the API plugin into it:

```sh
cd ~/src/
git clone https://github.com/aoloe/scribus-plugin-API.git
```

Now, the tricky part: in the Scribus sources you don't need the full repository, but only the files that are in the plugin's `src/` directory. 

We will create a symlink in the Scribus' `plugins/` directory that points to the plugin's `src/` directory:

```sh
cd ~/src/scribus/
cd scribus/plugins/
ln -s ~/src/scribus-plugin-API/src scribusAPI
```

Instead of symlinking the `src/` directory, you can also copy -- and rename -- it to the Scribus' `plugins` directory. If you don't plan to change the code and don't want to get updates through git this is good enough. Otherwise, using the symlink will make things much easier for you.

Finally, you need to tell Cmake that you've added a new plugin. Make sure that you're in the same directory where you have added the plugin and add the following line:

```.cmake
ADD_SUBDIRECTORY(scribusAPI)
```

If you prefer, you can run this shell command instead, which will add the line for you:

```sh
echo "ADD_SUBDIRECTORY(scribusAPI)" >> CMakesLists.txt
```

You have to repeat this instructions for each plugin you want to add from Github.  
As an example for adding the Epub plugin you need to:

```sh
cd ~/src/
git clone https://github.com/aoloe/scribus-plugin-export-epub.git
cd ~/src/scribus/
cd scribus/plugins/export/
ln -s ~/src/scribus-plugin-export-epub/src epub
echo "ADD_SUBDIRECTORY(epub)" >> CMakesLists.txt
```

In order to get the new plugins to be compiled you need to rerun cmake (with all parameters you have been using the first time) first:

```sh
cd ~/src/scribus/build/
cmake -DCMAKE_INSTALL_PREFIX:PATH=~/bin/scribus -DWANT_DEBUG=1 -DWANT_GUI_LANG="en_GB;de;fr;it;en" ..
make
make install
```
