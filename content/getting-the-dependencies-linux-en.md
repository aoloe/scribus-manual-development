# Getting the dependencies

First, you prepare your computer for C++ development:

## Packages needed for compiling Scribus

From the Docker images used to create the Appimage on Gitlab:

- build-essential
- gettext
- cmake
- libboost-dev
- libcups2-dev
- libhunspell-dev
- libhyphen-dev
- liblcms2-dev
- libpodofo-dev
- libpng-dev
- libjpeg-dev
- libtiff-dev
- libpython3-dev
- python3-tk
- zlib1g-dev
- libxml2-dev
- qt6-base-dev
- qt6-base-private-dev
- qt6-declarative-dev
- qt6-tools-dev
- qt6-wayland-dev
- libqt6core5compat6-dev
- qt6-svg-dev
- libqt6svg6-dev
- linguist-qt6
- qt6-base-dev-tools
- qt6-image-formats-plugins
- qt6-l10n-tools
- qt6-tools-dev-tools
- qt6-translations-l10n
- qt6-gtk-platformtheme
- libgraphicsmagick++1-dev
- libopenscenegraph-dev
- libpoppler-dev
- libpoppler-cpp-dev
- libpoppler-qt6-dev
- libpoppler-dev
- libpoppler-private-dev
- libcairo2-dev
- libfreetype6-dev
- libwpg-dev
- libmspub-dev
- libcdr-dev
- libvisio-dev
- libharfbuzz-dev
- libharfbuzz-icu0
- libgtk2.0-dev

The names for those packages should be pretty similar in Debian based and other Linux distributions.

## Debian, Ubuntu and their derivates

```sh
sudo apt install build-essential gettext cmake libboost-dev libcups2-dev \
libhunspell-dev libhyphen-dev liblcms2-dev libpodofo-dev libpng-dev libjpeg-dev \
libtiff-dev libpython3-dev python3-tk zlib1g-dev libxml2-dev qt6-base-dev \
qt6-base-private-dev qt6-declarative-dev qt6-tools-dev qt6-wayland-dev \
libqt6core5compat6-dev qt6-svg-dev libqt6svg6-dev linguist-qt6 qt6-base-dev-tools \
qt6-image-formats-plugins qt6-l10n-tools qt6-tools-dev-tools qt6-translations-l10n \
qt6-gtk-platformtheme libgraphicsmagick++1-dev libopenscenegraph-dev libpoppler-dev \
libpoppler-cpp-dev libpoppler-qt6-dev libpoppler-dev libpoppler-private-dev \
libcairo2-dev libfreetype6-dev libwpg-dev libmspub-dev libcdr-dev libvisio-dev \
libharfbuzz-dev libharfbuzz-icu0 libgtk2.0-dev
```

If you have the matching version of Scribus installed through the package management, on Debian and Ubuntu you can do:

```sh
sudo apt build-dep scribus
```

## Other distribution

You're welcome to contribute the command for installing the packages needed for other distributions.

## Keeping up to date with the dependencies

From time to time, Scribus adds new dependencies. Since the Ubuntu PPAs tend to be the most up to date, the `.dsc` in their Launchpad website is the place to go for kwnoing which packages Scribus needs:

- Go to the "Scribus Team" page on Launchpad: https://launchpad.net/~scribus
- Click on "PPA for Scribus friends" and then click on "View package details"
- You should get a list of "Source" packages. Click on the latest "scribus-trunk" package
- A the end of the page you should see a list of "Package files"
- Click on the link to the .dsc file and you will see a text file
