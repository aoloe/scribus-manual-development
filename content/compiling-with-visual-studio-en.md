# Comppiling with Microsoft Visual Studio

- These instructions are for 1.5.5svn or newer.
- They may be adapted for building 1.4.x but they have not been tested (you will then need Qt 4).
- You will need msvc2015/2017 to compile Scribus (msvc2013 has not been tested).

At the end we will be giving some hints for alternative setups, but this tutorial assume that:

- You're using Windows 10 in english.
- You Install Microsoft Visual Studio 2017 Community Edition with the VC++ 2015 tools.
- You install Qt 5.9.7 for MSVC 2015 64 bit.
- You compile Scribus in Release (and eventually Debug) mode for Windows 10 64 bit.

TODO: check if Qt 5.10.1 also works.

## 1. Prerequisites

1. You will need a recent version of Microsoft Windows (Vista, 7 or newer).
2. Obtain and install Microsoft visual studio 2017 community edition (for free).
  - Among the options you'll need at least the "Desktop development C++" with the "VC++ 2015 tools" and the "Windows 10 SDK".
3. Obtain and install the most recent Qt 5.9.x and make sure to install the msvc2015 component for you PC architecture (32/64 bit).
  - You can skip the creation of a Qt Account
  - Qt is typically installed in `C:\Qt\Qt5.9.7` (in the rest of the document this will be referred to as "qt-install-dir")
  - You will probably not want to "associate common file types with Qt Creator"
  - From the "Qt" (not "Preview") components, pick the latest Qt of the 5.9 serie with (at least) the modules:
    - MSVC 2015 64-bit
    - Qt WebEngine (maybe, for the help...)
4. A Git client (GitAhead, Github client, Git from the command line, ...)
5. The 7-Zip open source archive utility for Windows available at https://www.7-zip.org/

## 2. Get the Scribus sources

1. Create a directory in which you will be building Scribus: `C:\Documents\Development\Scribus-1.5`  
   In the rest of the document this will be referred to as the "scribus-root-path".
2. Obtain the source code of Scribus:
   - From the official Scribus official SVN repository:  
     `svn checkout svn://scribus.net/trunk/Scribus scribus`
   - Or from one of the the community managed Git repository:  
     `git clone https://gitlab.com/scribus/scribus.git`  
     `git clone https://github.com/scribusproject/scribus.git`
3. You should now have a `Documents\Development\Scribus-1.5\scribus` folder containing the Scribus sources.

## 3. Get the third party dependency package

The scribus development team provides packages with all the third party dependencies needed to build scribus. For compiling 1.5.x,you need:

- `scribus-commmon-libs-YYYYMMDD.7z` from <https://sourceforge.net/projects/scribus/files/scribus-libs/>
- `scribus-15x-libs-msvcXXXX-YYYYMMDD.7z` from <https://sourceforge.net/projects/scribus/files/scribus-libs/scribus-1.5.x/>

You should get the latest available files.

## 4. Extracting the third party dependencies

Next extract the two archives. It is important that they both are in the same folder.

- Create the sub folder "Scribus Libs" in the "scribus-root-path" ("scribus-root-path\Scribus Libs").
- Extract the "scribus-common-libs" folder from the scribus-commmon-libs-YYYYMMDD.7z into this directory.
- Extract the "scribus-1.5.x-libs-msvc2015" folder from  scribus-15x-libs-msvcXXXX-YYYYMMDD.7z into the same directory
- The directory structure should look like:

  ```
    scribus-root-path
       Scribus Libs 
           scribus-1.5.x-libs-msvc2015
           scribus-common-libs
  ```

## 5. Compile the Scribus library dependencies

After having extracted the 3rd party dependencies:

- Open with Visua Studio the Visual Studio Solution file (`*.sln`) located in the `scribus-1.5.x-libs-*` directory
  - If you get the question to upgrade the SDK version and the Platform Toolset, pick "No upgrade for both".
- In the toolbar pick the debug or release configurations for the x64 platform, then run _Build > Build Solution_

## 6. Compile Scribus

- Close "Visual Studio" (not strictly needed, but you never know...)
- Open the "scribus" source code folder you have cloned / checked out.
- Open  with a text editor the `Scribus-build-props.props` file from the `Win32\msvc2015` folder.
- Locate the `<SCRIBUS_LIB_ROOT></SCRIBUS_LIB_ROOT>` tag.
- Set its value to the path to `scribus-1.5.x-libs-msvc2015`
- Locate the `<QT5_DIR></QT5_DIR>` tag.
- Set the value for the x64 platform to the path where Qt is installed (`C:\Qt\Qt5.9.7\msvc2015_64`).
- Open "Scribus.sln" with Visual Studio. Choose "no upgrade" for the "Windows SDK" and for "Platform Toolset options"
- In the toolbar pick the debug or release configurations (you should pick the same as for the libraries) for the x64 platform, then run _Build > Build Solution_
- The binaries should be located in `<scribus-build-root>\Scribus-builds\Scribus-Debug-x64-v140`

## 7. Running Scribus

The next step is to install Scribus and get it to run.

Four things are needed:

- The Scribus compiled runtime.
- The Scribus common 3rd party libs.
- The Scribus 1.5.x specific 3rd party libs built in step 5.
- Specific Qt DLLS and Qt Plugins.

Let us now go through each step in detail:

### a. Install Scribus:

First install Scribus. Create a file named `install-scribus.bat` script in the "scribus-root-path" with the following content:

```bat
set SCRIBUS_SRC_PATH=.\scribus
set SCRIBUS_BUILD_PATH=.\Scribus-builds
set SCRIBUS_INSTALL_PATH=.\Scribus-builds\Scribus-Release-x64-v140

if not exist %SCRIBUS_INSTALL_PATH%\libs                mkdir %SCRIBUS_INSTALL_PATH%\libs
if not exist %SCRIBUS_INSTALL_PATH%\share               mkdir %SCRIBUS_INSTALL_PATH%\share
if not exist %SCRIBUS_INSTALL_PATH%\share\doc           mkdir %SCRIBUS_INSTALL_PATH%\share\doc
if not exist %SCRIBUS_INSTALL_PATH%\share\plugins       mkdir %SCRIBUS_INSTALL_PATH%\share\plugins
if not exist %SCRIBUS_INSTALL_PATH%\share\qml           mkdir %SCRIBUS_INSTALL_PATH%\share\qml

 copy %SCRIBUS_SRC_PATH%\AUTHORS                        %SCRIBUS_INSTALL_PATH%\share\doc
 copy %SCRIBUS_SRC_PATH%\COPYING                        %SCRIBUS_INSTALL_PATH%\share\doc
 copy %SCRIBUS_SRC_PATH%\LINKS                          %SCRIBUS_INSTALL_PATH%\share\doc
 copy %SCRIBUS_SRC_PATH%\TRANSLATION                    %SCRIBUS_INSTALL_PATH%\share\doc
xcopy %SCRIBUS_SRC_PATH%\doc                            %SCRIBUS_INSTALL_PATH%\share\doc /s /y /i /D
xcopy %SCRIBUS_SRC_PATH%\resources\dicts                %SCRIBUS_INSTALL_PATH%\share\dicts /s /y /i /D
xcopy %SCRIBUS_SRC_PATH%\resources\editorconfig         %SCRIBUS_INSTALL_PATH%\share\editorconfig /s /y /i /D
xcopy %SCRIBUS_SRC_PATH%\resources\iconsets             %SCRIBUS_INSTALL_PATH%\share\icons /s /y /i /D
 copy %SCRIBUS_SRC_PATH%\resources\iconsets\1_5_0\*.xml %SCRIBUS_INSTALL_PATH%\share\icons /y
 copy %SCRIBUS_SRC_PATH%\resources\iconsets\1_5_1\*.xml %SCRIBUS_INSTALL_PATH%\share\icons /y
xcopy %SCRIBUS_SRC_PATH%\resources\keysets              %SCRIBUS_INSTALL_PATH%\share\keysets /s /y /i /D
xcopy %SCRIBUS_SRC_PATH%\resources\loremipsum           %SCRIBUS_INSTALL_PATH%\share\loremipsum /s /y /i /D
xcopy %SCRIBUS_SRC_PATH%\resources\profiles             %SCRIBUS_INSTALL_PATH%\share\profiles /s /y /i /D
xcopy %SCRIBUS_SRC_PATH%\resources\swatches             %SCRIBUS_INSTALL_PATH%\share\swatches /s /y /i /D
xcopy %SCRIBUS_SRC_PATH%\resources\templates            %SCRIBUS_INSTALL_PATH%\share\templates /s /y /i /D
 copy %SCRIBUS_SRC_PATH%\scribus\scribus.css            %SCRIBUS_INSTALL_PATH%\libs\scribus.css /y
 copy %SCRIBUS_SRC_PATH%\scribus\plugins\tools\pathcut\*.png      %SCRIBUS_INSTALL_PATH%\share\icons\1_5_1 /y
 copy %SCRIBUS_SRC_PATH%\scribus\plugins\tools\pathfinder\*.png   %SCRIBUS_INSTALL_PATH%\share\icons\1_5_1 /y
xcopy %SCRIBUS_SRC_PATH%\scribus\plugins\scriptplugin\scripts     %SCRIBUS_INSTALL_PATH%\share\scripts /s /y /i /D
xcopy %SCRIBUS_SRC_PATH%\scribus\plugins\scriptplugin\samples     %SCRIBUS_INSTALL_PATH%\share\samples /s /y /i /D
copy  %SCRIBUS_SRC_PATH%\scribus\plugins\import\ps\import.prolog  %SCRIBUS_INSTALL_PATH%\libs\import.prolog
copy  %SCRIBUS_SRC_PATH%\scribus\plugins\barcodegenerator\barcode.ps %SCRIBUS_INSTALL_PATH%\share\plugins\barcode.ps
xcopy %SCRIBUS_SRC_PATH%\scribus\ui\qml                           %SCRIBUS_INSTALL_PATH%\share\qml /s /y
copy  %SCRIBUS_SRC_PATH%\scribus\unicodemap\unicodenameslist.txt  %SCRIBUS_INSTALL_PATH%\share\unicodenameslist.txt

del   %SCRIBUS_BUILD_PATH%\*CMake* /s
del   %SCRIBUS_BUILD_PATH%\*MakeFile* /s
```

At the beginning of the script, you'll need to set the correct value for:

- `SCRIBUS_SRC_PATH`: to `"scribus-root-path"\scribus` (the path where you cloend the git/svn repo).
- `SCRIBUS_BUILD_PATH`:  "scribus-root-path\Scribus-builds"
- `SCRIBUS_INSTALL_PATH`: the path where we built Scribus in step 6.

Run the `install-scribus.bat` file. It is important that you do this before the next step.

### b. Install the Scribus common 3rd party libs:

- Open the folder `scribus-root-path\Scribus Libs\scribus-commmon-libs` created in step 3.
- Open the `copy-dlls-to-15x-build-dir.bat` file in a text editor. 
- Change the value of `SCRIBUS_BUILDS_DIR` to `"scribus-root-path\Scribus-builds`.
- Change the value of `SCRIBUS_LIB_TOOLSET` to `V140`
- Verify that all other details are correct.
- Run "copy-dlls-to-15x-build-dir.bat".

### c. Installing the Scribus 1.5.x specific 3rd party libs:

- Open the folder "scribus-root-path\Scribus Libs\scribus-1.5.x-libs-msvc2015\copy-platform-dlls-to-build-dir.bat" created in step 3.
- Open the "copy-platform-dlls-to-build-dir.bat" in a text editor. 
- Change the value of "SCRIBUS_BUILDS_DIR" to "scribus-root-path\Scribus-builds".
- Change the value of SCRIBUS_LIB_PLATFORM from "Unknown" to "x64" for 64 bit or "Win32" for 32 bit.
- Verify that all the details are correct.
- Run "copy-platform-dlls-to-build-dir.bat"

### d. Install the QT plugins and QT DLLs used by Scribus.

In the "scribus-root-path", create the script `install-qt-stuff.bat` script with the content:

```bat
@echo off

set SCRIBUS_BUILDS_DIR=.\Scribus-builds
set SCRIBUS_BUILD_MODE=Release
set SCRIBUS_BUILD_PLATFORM=x64
set SCRIBUS_LIB_TOOLSET=v140
set QT_DIR=C:\Qt\5.9.7\msvc2015_64

rem /.../Scribus-Release-x64-v140
set SCRIBUS_BUILD_PATH=%SCRIBUS_BUILDS_DIR%\Scribus-%SCRIBUS_BUILD_MODE%-%SCRIBUS_BUILD_PLATFORM%-%SCRIBUS_LIB_TOOLSET%

if not exist %SCRIBUS_BUILD_PATH% (
    echo Incorrect Scribus build directory:
    echo %SCRIBUS_BUILD_PATH%
    exit /b 1
)

if not exist %QT_DIR% (
    echo Incorrect Qt directory:
    echo %QT_DIR%
    exit /b 1
)

set EXT_DEBUG=
if "%SCRIBUS_BUILD_MODE%"=="Debug" (
    set EXT_DEBUG=d
)

if not exist %SCRIBUS_BUILD_PATH%\qtplugins       mkdir %SCRIBUS_BUILD_PATH%\qtplugins

xcopy %QT_DIR%\plugins\bearer       %SCRIBUS_BUILD_PATH%\qtplugins /s /y /i /D
xcopy %QT_DIR%\plugins\iconengines  %SCRIBUS_BUILD_PATH%\qtplugins /s /y /i /D
xcopy %QT_DIR%\plugins\imageformats %SCRIBUS_BUILD_PATH%\qtplugins /s /y /i /D
xcopy %QT_DIR%\plugins\platforms    %SCRIBUS_BUILD_PATH%\qtplugins /s /y /i /D
xcopy %QT_DIR%\plugins\printsupport %SCRIBUS_BUILD_PATH%\qtplugins /s /y /i /D

copy %QT_DIR%\bin\Qt5Core%EXT_DEBUG%.dll         %SCRIBUS_BUILD_PATH%\ /y
copy %QT_DIR%\bin\Qt5Gui%EXT_DEBUG%.dll          %SCRIBUS_BUILD_PATH%\ /y
copy %QT_DIR%\bin\Qt5Network%EXT_DEBUG%.dll      %SCRIBUS_BUILD_PATH%\ /y
copy %QT_DIR%\bin\Qt5PrintSupport%EXT_DEBUG%.dll %SCRIBUS_BUILD_PATH%\ /y
copy %QT_DIR%\bin\Qt5Widgets%EXT_DEBUG%.dll      %SCRIBUS_BUILD_PATH%\ /y
copy %QT_DIR%\bin\Qt5Xml%EXT_DEBUG%.dll          %SCRIBUS_BUILD_PATH%\ /y
copy %QT_DIR%\bin\Qt5Svg%EXT_DEBUG%.dll          %SCRIBUS_BUILD_PATH%\ /y
```

At the beginning of the script, you'll need to set the correct value for:

- `SCRIBUS_BUILDS_DIR`: Relative path to the Scribus build dir (step 6).
- `SCRIBUS_BUILDS_MODE`: "Release" or "Debug".
- `SCRIBUS_BUILD_PLATFORM`: "x64" or "win32".
- `SCRIBUS_LIB_TOOLSET`: currently, only "v140" is supported.
- `QT_DIR`: the full path for the Qt files matching the current platform (if you have both "x86" and "win32", it must match `SCRIBUS_LIB_PLATFORM`!).

Run the `install-scribus.bat` file. It is important that you do this before the next step.

AUTHOR NOTE: This last step is not omptimized, yet. It copies some extra qt libs and plugins which are never used by Scribus.
We should also differentiate between release and debug builds.  (I still can't make out if Scribus.exe links against the
debug DLLs if you build it for debug vs release. Qt debug DLLs have a small "d" at the end. E.g. "Qt5Cored.dll" vs "Qt5Core.dll").

Congratulations your done. You can finally run `Scribus.exe`.

## Further informations
 
### Getting MSVC

You will need to create a free Microsoft account to download as well as keep the software active.

You can choose to install only the c++ components if you wish and make the install lighter. On Visual studio 2017 in the installer under the "Workloads" tab if you choose "Desktop development with C++" it should be more than enough as it installs the 2017 and 2015 msvc toolchain.

### Getting Qt

- You can use bot the offline or online installer.
- You can install both 32 and 64 bits components if you intend to build both.

### Getting the dependency packages

The scribus development team provides two package with all the 3rd party dependencies needed to build scribus.

- `scribus-commmon-libs-YYYYMMDD.7z`: common libraries for 14x and trunk, no compilation is required here
- `scribus-15x-libs-msvcXXXX-YYYYMMDD.7z`: Scribus 15x specific libraries used for current Scribus 1.5.x releases

For building 15x dependencies, archives for Visual Studio 2013 and Visual Studio 2015 are provided. These archives allows to 
build libraries  for 32bit and 64bit platforms using the different available toolsets, including the Windows XP compatible ones. 
The default configuration allows to build binaries compatible with Windows Vista and up. Windows XP is end of life therefore 
we will mostly only need the scribus-15x-libs-msvc2015-YYYYMMDD.7z file.

These archives can be obtained from the below URL:

- scribus-commmon-libs-YYYYMMDD.7z from:  
  https://sourceforge.net/projects/scribus/files/scribus-libs/
- scribus-15x-libs-msvcXXXX-YYYYMMDD.7z from:  
  https://sourceforge.net/projects/scribus/files/scribus-libs/scribus-1.5.x/

### Compiling for different toolset

If you want to build using a different toolset, you can use msbuild through the command line. To do so you can use the provided 
build-all-platform-libs.bat script. For example :

- to build with Visual Studio 2015 default toolset for x64 platform: build-all-platform-libs.bat x64 v140
- to build with Visual Studio 2015 Windows XP toolset for Win32 platform: build-all-platform-libs.bat Win32 v140_xp

### Compiling Scribus

- If you're using the msvc2013 toolset you will to edit the `Win32\msvc2013\Scribus-build-props.props` file, instead of the one in the `msvc2015` directory.


### Installing Scribus

c. Installing the Scribus 1.5.x specific 3rd party libs:
  - If you're building for Windows XP, set the value of "SCRIBUS_LIB_TOOLSET" as `v140_xp`.
