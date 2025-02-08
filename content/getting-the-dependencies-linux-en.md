# Getting the dependencies

First, you prepare your computer for C++ development:

## Packages needed for compiling Scribus


According to the Scribus PPA for ubuntu, you'll need the following packages for compiling Scribus:

- build-essential
- cmake (>= 3.12.0)
- gettext
- libcairo2-dev
- libcdr-dev
- libcups2-dev
- libfreehand-dev
- libgraphicsmagick++1-dev
- libharfbuzz-dev
- libhunspell-dev
- libhyphen-dev
- libicu-dev
- liblcms2-dev
- libmspub-dev
- libopenscenegraph-dev
- libpagemaker-dev
- libpodofo-dev
- libpoppler-cpp-dev
- libpoppler-dev
- libpoppler-private-dev
- libqt5opengl5-dev
- libqt5webkit5-dev
- librevenge-dev
- libtiff-dev
- libvisio-dev
- libwpg-dev
- libxml2-dev
- python3-all-dev
- qtbase5-dev
- qttools5-dev
- qttools5-dev-tools
- zlib1g-dev

The names for those packages should be pretty similar in Debian and other Linux distributions.

Qt 6:

- libqt6core5compat6
- linguist-qt6

cf. the docker file in the main branch

## Debian, Ubuntu and their derivates

```sh
sudo apt install subversion g++ cmake extra-cmake-modules libpoppler-dev libpoppler-cpp-dev libpoppler-private-dev qtbase5-dev qttools5-dev libopenscenegraph-dev libgraphicsmagick-dev libcairo2-dev librevenge-dev python3-all-dev libhunspell-dev libcups2-dev libpodofo-dev libcdr-dev libfreehand-dev libpagemaker-dev libmspub-dev libqxp-dev libvisio-dev libzmf-dev libgraphicsmagick++1-dev
```

If you have the matching version of Scribus installed through the package management, on Debian and Ubuntu you can do:

```sh
sudo apt-get build-dep scribus-trunk
```

## OpenSuse

```sh
sudo zypper install subversion cmake extra-cmake-modules libqt5-qttools-devel GraphicsMagick-devel libfreehand-devel librevenge-devel libvisio-devel libqxp-devel libmspub-devel libcdr-devel libpagemaker-devel cups-devel libtiff-devel libzmf-devel libpoppler-qt5-devel libqt5-qtbase-devel libOpenSceneGraph-devel python3-devel libjpeg62-devel liblcms2-devel harfbuzz-devel libopenssl-devel hunspell-devel
```

## Arch

```
sudo pacman -S subversion gcc make cmake extra-cmake-modules qt5-base qt5-tools openscenegraph python pkgconfig hunspell podofo boost graphicsmagick poppler librevenge harfbuzz-icu libfreehand libpagemaker libcdr libmspub libqxp libvisio libzmf
```

## Solus

```sh
sudo eopkg install -c system.devel
sudo eopkg install subversion qt5-tools-devel graphicsmagick-devel openscenegraph-devel poppler-qt5-devel qt5-base-devel librevenge-devel libfreehand-devel libvisio-devel libqxp-devel libhunspell-devel libmspub-devel libcdr-devel libpagemaker-devel podofo-devel cups-devel libjpeg-turbo-devel libtiff-devel libzmf-devel libboost-devel
```

## Keeping up to date with the dependencies

From time to time, Scribus adds new dependencies. Since the Ubuntu PPAs tend to be the most up to date, the `.dsc` in their Launchpad website is the place to go for kwnoing which packages Scribus needs:

- Go to the "Scribus Team" page on Launchpad: https://launchpad.net/~scribus
- Click on "PPA for Scribus friends" and then click on "View package details"
- You should get a list of "Source" packages. Click on the latest "scribus-trunk" package
- A the end of the page you should see a list of "Package files"
- Click on the link to the .dsc file and you will see a text file
