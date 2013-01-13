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
