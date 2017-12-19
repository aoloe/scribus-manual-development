# Getting started

This chapter is a quick introduction to getting Scribus to compile, for users who already know how to compile code and want to know the few details that are specific to Scribus.

## Requirements

To get Scribus compiled you'll need a Linux distribution with up to date packages (the latest Ubuntu release, Debiant testin or Sid, ...) or Mac OS X with Home Brew.

Compiling on Windows with Visual Studio is possible, but the are no detailed instruction available.

Currently, you can compile Scribus from the command line or use Qt Creator.

## Getting the dependencies

### Linux

According to the Scribus PPA for ubuntu, you'll need the following packages for compiling Scribus:

- build-essential
- cmake (>= 2.4.3),
- gettext,
- libboost-python-dev,
- libcairo2-dev,
- libcdr-dev,
- libcups2-dev,
- libfreehand-dev,
- libgraphicsmagick++1-dev,
- libharfbuzz-dev,
- libhunspell-dev,
- libhyphen-dev,
- libicu-dev,
- liblcms2-dev,
- libmspub-dev,
- libopenscenegraph-dev,
- libpagemaker-dev,
- libpodofo-dev,
- libpoppler-cpp-dev
- libpoppler-dev,
- libpoppler-private-dev,
- libqt5opengl5-dev,
- libqt5webkit5-dev,
- librevenge-dev,
- libtiff-dev,
- libvisio-dev,
- libwpg-dev,
- libxml2-dev,
- python-all,
- qtbase5-dev,
- qttools5-dev,
- qttools5-dev-tools,
- zlib1g-dev

The names for those packages should be pretty similar in Debian and other Linux distributions.

You can get the latest `.dsc` by going to the Launchpad website:

- Go to the "Scribus Team" page on Launchpad: https://launchpad.net/~scribus
- Click on "PPA for Scribus friends" and then click on "View package details"
- You should get a list of "Source" packages. Click on the latest "scribus-trunk" package
- A the end of the page you should see a list of "Package files"
- Click on the link to the .dsc file and you will see a text file

If you have the matching version of Scribus installed through the package management, on Debian and Ubuntu you can do:

```sh
sudo apt-get build-dep scribus-trunk
```

### OS X

TODO: To be done.

## Getting the code

You can get the code from the Scribus own Subversion repository

~~~.sh
svn co svn://scribus.net/trunk/Scribus scribus
~~~

or from the Github mirror

~~~.sh
git clone git@github.com:scribusproject/scribus.git
~~~

or

~~~.sh
git clone https://github.com/scribusproject/scribus.git
~~~

### Getting the code for development

If you plan to work on the Scribus code, you will probably want to clone your own fork of the [scribus repository](https://github.com/scribusproject/scribus):

- Propbably, you will want to make sure that your have configured your system and your Github account with ssh keys: https://help.github.com/articles/connecting-to-github-with-ssh/
- Use the "Fork" button at the top of the [scribus repository](https://github.com/scribusproject/scribus) to create your own fork.
- Clone your own copy of Scribus: `git clone https://github.com/your-username/scribus.git`

For more details please read [Github's forkin manual](https://help.github.com/articles/fork-a-repo/).



## Compiling from the command line

You should compile Scribus out of source and install it inside of your home directory.

We will assume that you have your source code in `~/src/` and your own binaries in `~/bin/` (where `~/` is your home). You will have to adapt the instructions if your paths are different.

We will first do a test run of `cmake`:

~~~.sh
cd ~/src/scribus
mkdir build/
cd build/
cmake ..
cmake -DCMAKE_INSTALL_PREFIX:PATH=~/bin/scribus -DWANT_DEBUG=1 -DWANT_GUI_LANG="en_GB;de;fr;it;en" ..
~~~

If you get errors, it's very likely that they're due to missing development packages (you need the `-dev` header files on top of the usual packages).  
In the case the packages are installed but the version is too old, you'd better consider retrying with a distribution that provides more up to date packages (Debian Testing and the latest Ubuntu are generally speaking fine).

You can retry until `cmake` runs successfully. In some cases you will have to delete the `build/` directory and restart from scratch.

Once `cmake` has run successfully, you can now _make_ Scribus.

~~~.sh
make -j4
~~~

The `-j4` tells `make` to use 4 threads. Use `-j2` or no `-j` at all on older machines.

Before being able to run Scribus, you will need to install it.

~~~.sh
make install
cd ~/bin/scribus/bin/
./scribus
~~~

You can create a symlink in `/usr/local/bin` if you want to be able to run it from the terminal or the launcher.  
You will have to use a different name (like `scribus-dev`) if you already have Scribus installed.

~~~.sh
cd /usr/local/bin/
sudo ln -s ~/bin/scribus/bin/scribus scribus-dev
~~~

## If the compilation fails

### It does not `cmake`

- Is the `cmake` version new enough?
- Get the output from `cmake` by redirecting it to a file:
  ~~~.sh
  cmake .. >> cmake-log.txt 2>&1
  ~~~

## Compiling with Qt Creator

If you're using Qt Creator, you can simply create a new project and use the Github address of the mirror:

~~~.sh
git@github.com:scribusproject/scribus.git
~~~

As long as the dependencies are met, Qt Creator will be able to figure everything you need.

## Adding a plugin from a Github repository

If you want to use or improve a plugin that has its own Github repository, you can download its code and add it to the Scribus code.

We suggest you to first carefully read the plugin's README file.  

On top of the specific instructions you get in the README files, this section explains with two examples -- the API and Epub plugins -- how to get the plugins to be compiled with Scribus.

First you'll have to clone the repository in the directory where you're storing the code you compile (as previously stated we assume here that it's `~/src/~).  
Then, you'll clone the API plugin into it:

~~~.sh
cd ~/src/
git clone https://github.com/aoloe/scribus-plugin-API.git
~~~

Now, the tricky part: in the Scribus sources you don't need the full repository, but only the files that are in the plugin's `src/` directory. 

We will create a symlink in the Scribus' `plugins/` directory that points to the plugin's `src/` directory:

~~~.sh
cd ~/src/scribus/
cd scribus/plugins/
ln -s ~/src/scribus-plugin-API/src scribusAPI
~~~

Instead of symlinking the `src/` directory, you can also copy -- and rename -- it to the Scribus' `plugins` directory. If you don't plan to change the code and don't want to get updates through git this is good enough. Otherwise, using the symlink will make things much easier for you.

Finally, you need to tell Cmake that you've added a new plugin. Make sure that you're in the same directory where you have added the plugin and add the following line:

~~~.cmake
ADD_SUBDIRECTORY(scribusAPI)
~~~

If you prefer, you can run this shell command instead, which will add the line for you:

~~~.sh
echo "ADD_SUBDIRECTORY(scribusAPI)" >> CMakesLists.txt
~~~

You have to repeat this instructions for each plugin you want to add from Github.  
As an exapmle for adding the Epub plugin you need to:

~~~.sh
cd ~/src/
git clone https://github.com/aoloe/scribus-plugin-export-epub.git
cd ~/src/scribus/
cd scribus/plugins/export/
ln -s ~/src/scribus-plugin-export-epub/src epub
echo "ADD_SUBDIRECTORY(epub)" >> CMakesLists.txt
~~~

In order to get the new plugins to be compiled you need to rerun cmake (with all parameters you have been using the first time) first:

~~~.sh
cd ~/src/scribus/build/
cmake -DCMAKE_INSTALL_PREFIX:PATH=~/bin/scribus -DWANT_DEBUG=1 -DWANT_GUI_LANG="en_GB;de;fr;it;en" ..
make
make install
~~~
