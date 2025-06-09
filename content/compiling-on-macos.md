# Compiling on MacOS

This chapter is a quick introduction to getting Scribus to compile on Mac OS. It's written for users who already know how to compile code and want to know the few details that are specific to Scribus.

If Scribus is the first software you're compiling, this chapter can still be very useful, but you will need to look up a few things (or ask question in the community) while reading it.

## Requirements

To get Scribus compiled you'll need a recent version of Mac OS and Home Brew.

Currently, you can compile Scribus from the command line or use Qt Creator.

### Installing Qt 6

- If you don't plan to write iOS apps with Qt, you can speed up the installation and save lot of disk space (about 15 GB).
- Make sure you download the freee open source version of Qt, and NOT the free to try commercial version.

#### Get the Qt installer

- Go to https://www.qt.io/download-open-source
- Hit "Download Qt Online Installer" button, which takes you to https://www.qt.io/download-qt-installer-oss
- "Download Qt for open source use": Choose your OS: macOS.
- Hit button "Qt Online Installer for macOS". This will point to the DMG disk image the macOS installer file, for example "qt-online-installer-macOS-x64-4.9.0.dmg".

#### Run the Qt online installer app.

- Run the DMG you just downloaded.
- You will need to login with your Qt account: If you do not have any, Create new Qt account, email required.
- If you have already installed Qt, Start Qt MaintenanceTool.app.

- Login, choose Qt then choose the most recent version that is supported by Scribus (At the time of writing Qt 6.8.3).
- Select [x] Desktop 6.8.3 and [x] Qt 5 Compatibility module. (Also Qt Shader Tools was selected, but unsure if needed)
- Select [x] Build Tools, [x] CMake 3.30.5 (Optionally also Ninja).
- Select [x] Qt Creator 16.0.2 (was pre selected)

Hit next and let the tool download and install Qt.

You can change these settings at anytime afterwards with the Qt MaintenanceTool.app tool.

### Installing the dependencies with Homebrew

Homebrew is a Package Manager for macOS.

If you not have brew installed, install it. See https://brew.sh/

```sh
% brew install boost podofo hunspell
```


### Installing the dependencies with Macports

## Getting the Scribus source code

You will probably want to use Git to get the Scribus code:

```sh
% mkdir src
% cd src
% git clone https://github.com/scribusproject/scribus.git scribus
```

If Git is not installed yet, you can install it with Homebrew or Macports.

This is a community mirror of the official SVN Scribus repository.

If you want to get Scribus from the official server, you need to install svn (also with Homebrew or Macports) and then:

```sh
% mkdir src
% cd src
% svn co svn://scribus.net/trunk/Scribus scribus
```

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

MrB's cmake command:

```sh
cmake -DQT_PREFIX="/Users/craig/Qt/6.9.0/macos"
    -DWANT_DEBUG=ON
    -DOSXMINVER="11.00"
    -DLIBPODOFO_DIR_PREFIX:PATH=/opt/local/libexec/podofo-0.10/
    -DWANT_NOEXAMPLES=ON
    -DWANT_GRAPHICSMAGICK=ON
    -DCMAKE_OSX_ARCHITECTURES="arm64"
    -DBUILD_OSX_BUNDLE=ON
    -DWANT_UNIVERSAL_BUNDLE=OFF
    -DWANT_SVNVERSION=ON
    -DWITH_BOOST=ON
    -DWANT_PCH=ON
    -DPython3_ROOT_DIR=/opt/local/Library/Frameworks/Python.framework/Versions/3.13/
    -DCMAKE_INSTALL_PREFIX:PATH=/Users/craig/Applications/ScribusTrunk.app/
    ../trunk/Scribus/
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
