# Set up your development environment

The easiest way to get a development environment for contribution is to work on Linux. You can choose to work on a machine with one of the several Linux distributions installed, or install one of the distributions in a virtual machine.

In this chapter we will first go through the configuration of a Linux virtual machine on Mac OS X and Microsoft Windows, then explain how to

Currently, the compilation of 

If you don't plan to contribute by programming code, you can skip the installation of the development tools and install the pre-compiled development versions of Scribus. Currently the biggest set of pre-compiled versions are only for Ubuntu.

## Installing Linux

There are three ways of getting your computer to run Linux:
- Installing it as the main OS of one of your computers.
- Installing it in one of the partitions of your computer, aside of your current OS.
- Installing it in a virtual machine running as a client of your current OS.

In this manual we will only describe the installation in a Virtual Machine. (add references to good ways to install Fedora, OpenSuse or Ubuntu)

If you're starting with Linux, we suggest you to use one of the two mainstream distributions:
- Fedora
- Ubuntu
But you should be able to easily set up any of the modern Linux distribution.

## Installing VirtualBox

VirtualBox is a program that let's you create virtual machines that will be running in a window on your computer.

### OS X

- Download the .iso
- Install it

### Windows 7

- Download the setup file
- Install it

## Installing Linux in a virtual machine

### Downloading the Linux distribution

### Creating a new virtual machine

- Create a new instance
- 32 bit Linux (choose the type according to the distribution you plan to install)
- 20GB of hard disk
- 2GB RAM
- Save it

### Installing Linux 

Running the instance for the first time is a bit like running your computer for the first time: VirtualBox will prompt you for a source where it can get the OS to be installed.
Instead of using a DVD, you can simply let it load the .iso file you've downloaded.

Since the installation will happen inside of the protected environment of the virtual machine, you will install Linux as if it was the only OS in the system and use the whole virtual Hard Disk you have defined when creating the Virtual Machine.
Just take care, that you don't install Linux on your computer but only in the virtual machine. If you're in doubt, don't hesitate to start over, or even stop the installation and ask for help.

### Getting the dependencies

After having installed Linux, the next step is to setup the development environment. Differently than with other Operating Systems, the Linux distribution will provide you with all the software you need in a repository. You will not have to look for software on the Web, but simply use the Package manager provided.

While the process is the same, different distributions have small differences. We will present the procedure for each fo the mainstream distributions


## Setting up with OS X

brew freetype says
LDFLAGS:  -L/usr/local/opt/freetype/lib
CPPFLAGS: -I/usr/local/opt/freetype/include
brew pimxan says
LDFLAGS:  -L/usr/local/opt/pixman/lib
CPPFLAGS: -I/usr/local/opt/pixman/include
brew cairo says
LDFLAGS:  -L/usr/local/opt/cairo/lib
CPPFLAGS: -I/usr/local/opt/cairo/include
brew fontconfig says
LDFLAGS:  -L/usr/local/opt/fontconfig/lib
CPPFLAGS: -I/usr/local/opt/fontconfig/include


	cmake -DBUILD_OSX_BUNDLE=1 -DCMAKE_INSTALL_PREFIX:PATH=/Applications/ ..

	cmake -DFREETYPE_INCLUDE_DIRS=/usr/local/opt/freetype/include/
	set CMAKE_MODULE_PATH=/usr/local/opt/freetype


	cmake -DBUILD_OSX_BUNDLE=1 -DCMAKE_INSTALL_PREFIX:PATH=/Applications/ -DFREETYPE_INCLUDE_DIRS=/usr/local/opt/freetype/include/ ..


	cmake -DBUILD_OSX_BUNDLE=1 -DCMAKE_INSTALL_PREFIX:PATH=/Applications/ -DFREETYPE_INCLUDE_DIRS=/usr/local/opt/freetype/include/ -DWANT_SYSTEM_CAIRO=1-DWANT_PRIVATE_CAIRO=0 -DPREFIX_CAIRO=/usr/local/opt/cairo -DFONTCONFIG_INCLUDE_DIR=/usr/local/opt/fontconfig ..


	cmake -DBUILD_OSX_BUNDLE=1 -DCMAKE_INSTALL_PREFIX:PATH=/Applications/ -DFREETYPE_INCLUDE_DIRS=/usr/local/opt/freetype/include/ -DWANT_SYSTEM_CAIRO=1-DWANT_PRIVATE_CAIRO=0 -DPREFIX_CAIRO=/usr/local/opt/cairo -DFONTCONFIG_INCLUDE_DIRS=/usr/local/opt/fontconfig/include/ -DFONTCONFIG_LIBRARY_DIRS=/usr/local/opt/fontconfig/lib/ --debug-output ..


removing the pkg-config part from the fontconfig cmake file lets me go through cmake...
but, then, make can't find freetype...


	export LDFLAGS="-R/usr/local/opt/fontconfig/lib -L/usr/local/opt/fontconfig/lib"
	export CPPFLAGS="-I/usr/local/opt/fontconfig/include"

	export LDFLAGS="-R/usr/local/opt/fontconfig/lib -L/usr/local/opt/fontconfig/lib -R/usr/local/opt/freetype/lib -L/usr/local/opt/freetype/lib"
	export CPPFLAGS="-I/usr/local/opt/fontconfig/include -I/usr/local/opt/freetype/include"

# Setup your develepment environment on Debian or Ubuntu

## Getting the Dependencies

On Debian and Ubuntu you will need the following packages:

According to the [Scribus PPA dsc file](https://launchpadlibrarian.net/216817551/scribus-ng_1.5.0-0ubuntu15.10.0~ppa1.dsc) you will need the following packages for compiling Scribus:

- cmake (>= 2.4.3),
- debhelper (>= 9),
- gettext,
- libboost-python-dev,
- libcairo2-dev,
- libcdr-dev (>= 0.1),
- libcups2-dev,
- libgraphicsmagick1-dev,
- libhunspell-dev,
- libhyphen-dev,
- liblcms2-dev,
- libmspub-dev (>= 0.1),
- libosgearth-dev,
- libpagemaker-dev,
- libpodofo-dev (>= 0.9.0),
- libpoppler-private-dev,
- libpoppler-qt5-dev,
- libqt5opengl5-dev,
- libqt5webkit5-dev,
- librevenge-dev,
- libtiff-dev,
- libvisio-dev (>= 0.1),
- libwpg-dev,
- libxml2-dev (>= 2.6.16),
- python-all-dev (>= 2.6.6-3~),
- qtbase5-dev,
- qttools5-dev,
- qttools5-dev-tools,
- zlib1g-dev

Some remarks:
- `libosgearth-dev` might lead to some issues: if you encounter any "OSG" related problems when compiling scribus, please try to remove this package.  
- The following packages are not mandatory:
  - libcdr-dev (>= 0.1),
  - libpagemaker-dev,
  - libqt5opengl5-dev,
  - libvisio-dev (>= 0.1),
  - libwpg-dev
- `python-all-dev` seems to be a bit broad (in the future we might want to find out which `python-*-dev` packages are really needed)

You can get the latest `.dsc` by going to the Launchpad website:

- Go to the "Scribus Team" page on Launchpad: https://launchpad.net/~scribus
- Click on "PPA for Scribus friends" and then click on "View package details"
- You should get a list of "Source" packages. Click on the latest "scribus-trunk" package
- A the end of the page you should see a list of "Package files"
- Click on the link to the .dsc file and you will see a text file

In the .dsc file, the "Build depends" section tells you which package this version of Scribus depends. The names for those packages are exactly the same or very similar to the ones used by Debian.

## Getting the Dependencies with the command line

## Debian versions

If possible, use debian testing or unstable.

## Ubuntu

To compile and run scribus without problem in Ubuntu 12.10 you may need to set the  paths to python libs or add them to cmake command line, otherwise python3 libs will be preferred over python2

	cmake ../Scribus -DWANT_SYSTEM_CAIRO=1 -DCMAKE_INSTALL_PREFIX=../Scribus-bin -DPYTHON_LIBRARY=/usr/lib/libpython2.7.so -DPYTHON_INCLUDE_DIR=/usr/include/python2.7

## Fedora

At least on Fedora 20, except for some of the new importers, all of the dependencies are available as RPMs from Fedora's repository.

As a start, run yum groupinstall 'development tools'. Then run "sudo yum install" for the packages below and follow the instructions at http://wiki.scribus.net/canvas/Download and http://wiki.scribus.net/canvas/Building_SVN_versions_with_CMake

~~~
svn cmake gcc gcc-c++ ccache qtchooser
apr-devel apr-util-devel flex-static libXp libXp-devel libexif-devel libtool-ltdl-devel libusb-devel netpbm-progs t1lib openjpeg-devel openjpeg-libs
turbojpeg turbojpeg-devel boost GraphicsMagick fontconfig-devel libX11-devel  libXext-devel libXaw-devel Xaw3d-devel libXt-devel poppler-devel poppler-qt5 
poppler-qt5-devel poppler-qt poppler-qt-devel poppler-cpp poppler-cpp-devel  ncurses-devel freeglut freeglut-devel libpaper libpaper-devel libmspub 
libmspub-devel libvisio libvisio-devel lcms2 lcms2-devel OpenSceneGraph OpenSceneGraph-devel podofo podofo-devel GraphicsMagick-devel 
libjpeg-turbo-devel libtiff-devel python-devel hunspell hunspell-devel  libxml++-devel gtkmm24-devel libgnomecanvasmm26-devel cups-devel libstdc++-devel gcc-c++ 
freetype-devel cairo-devel libxml2-devel lcms-devel libpng-devel libjpeg-devel libwpg-devel boost boost-devel 
openssl-devel git wget 'freeglut*' 'libXmu-*' libXi-devel libXrandr-devel 'qt5-qt*'
~~~

(fedora description based on william bader's email to the scribus mailing list on 7.9.2015)
