# Getting started

This chapter is a quick introduction to getting Scribus to compile, for users who already know how to compile code and want to know the few details that are specific to Scribus.

## Requirements

To get Scribus compiled you'll need a Linux distribution with up to date packages (the latest Ubuntu release, Debiant testin or Sid, ...) or Mac OS X with Home Brew.

Compiling on Windows with Visual Studio is possible, but the are no detailed instruction available.

Currently, you can compile Scribus from the command line or use Qt Creator.

## Getting the dependencies

### Linux

According to the Scribus PPA for ubuntu, you'll need the following packages for compiling Scribus:

- cmake (>= 2.4.3),
- gettext,
- libboost-python-dev,
- libcairo2-dev,
- libcdr-dev,
- libcups2-dev,
- libfreehand-dev,
- libgraphicsmagick++1-dev,
- libhunspell-dev,
- libhyphen-dev,
- libicu-dev,
- liblcms2-dev,
- libmspub-dev,
- libopenscenegraph-dev,
- libpagemaker-dev,
- libpodofo-dev,
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

Once `cmake has run successfully, you can now _make_ Scribus.

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
