# TODO

- use the name "model" instead of action
- use the options to pass the values between the dialog and the model
- define a qDebug() for the options

## Adding an empty plugin

- If you're using Git, it's a good idea to create a new branch in your Scribus fork. Before starting with programming the plugin.
- Create a new directory in the plugins/ directory with the name of the plugin (or in one of its subdirectories if the new plugin is part of a type). In this examples we will use the name "sample"... to create the sample plugin.
  - the boilerplate for loading and defining your code as a plugin, will go the file "sampleplugin.cpp"
  - the main code of your plugin will go to "sample.cpp"
  - if you are creating a dialog it will be called "sampledialog.ui" and it will be included through the files "sampledialog.cpp" and "sampledialog.h"
- create the main plugin class, named with the name of the plugin and the word "plugin".
  <pre>
  sampleplugin.cpp
  sampleplugin.h
  </pre>
  The two files are in the download folder under sampleplugin\_base
  TODO: in the parameters for ::run(): what is QString target?
  TODO: describe briefly the content of the two files

- add the directory to the plugins/CMakeLists.txt file as:
    ADD_SUBDIRECTORY(pluginname)
- add a CMakeLists.txt file in the plugin directory
- you can now try to compile the plugin. at the end you should have an entry "Sample" in your "Extra" menu

## Plugins specificities

### Creating a plugin that reads text files

- Create the plugin in the `plugins/gettext/` directory
- Name the directory and the main plugin's file by the type of file you want your pluging to be able to read (`markdown/markdown.cpp`).
  - Each plugin defines three "free functions": 
    - `FileFormatName()`
    - `FileExtensions()`
    - `GetText()`, where you create and run a plugin importer object.
  - The class is mostly named by the type of the file followed by "GetText" (MarkdownGetText) and usually has three public functions:
    - The creator receives from the "loading" parameters (file name, ...) from the `GetText()` function.
    - `loadText()` loads the file content in an internal structure matching the format rules and the user's settings.
    - `write()` adds the content to the outpustream that has been passed to the plugin.

- put the plugin's implementation in a file with the `reader` ending (`markdown/markdownreader.cpp`).


### Creating a plugin that export the file content

## Showing a dialog when the plugin runs

- With Qt Designer create your dialog as a "Dialog with buttons" and save the .ui file in the plugin's directory as sample.ui. You should at least add a "Cancel" button which you will call "cancelButton"
  - rename the object name to the name of the class (SampleDialog; it's the name you will call as UI::SampleDialog in the dialog header)
  - set the correct window title
- Create a class that manages the communication among the plugin and the .ui file:
  - sampledialog.cpp
  - sampledialog.h
- in sampleplugin.cpp include sampledialog.h add the code displaying the dialog in the "run" method of "SamplePlugin" class
- Add the ui-related files to the plugin's CMakeLists.txt
  - add the .ui files to SCRIBUS\_SAMPLE\_PLUGIN\_UI\_SRC
  - add the sampledialog.h file to SCRIBUS\_SAMPLE\_PLUGIN\_MOC\_CLASSES
  - add the sampledialog.cpp file to SCRIBUS\_SAMPLE\_PLUGIN\_SOURCES
  - add the macro QT4\_WRAP\_UI(SCRIBUS\_SAMPLE\_PLUGIN\_UI\_SOURCES ${SCRIBUS\_SAMPLE\_PLUGIN\_UI\_SRC} )
  - ${SCRIBUS\_SAMPLE\_PLUGIN\_UI\_CPP} ${SCRIBUS\_SAMPLE\_PLUGIN\_UI\_SOURCES} to the ADD\_LIBRARY macro

## Adding your actions

The real code will be in the class named after the plugin name. In the SampleDialog class you will then connect the events from the dialog with the single actions.
If the plugin is not trivial you may want to split the logic in multiple classes, which you will load from your main plugin class (in our case the Sample class)

In the constructur, you will often want to pass the current document as a parameter.

- create the sample.h and sample.cpp file containent the headers and the code for the Sample class.
- add the two files to the CMakeLists.txt file:
  - sample.h to the SCRIBUS\_SCRIPTMANAGER\_PLUGIN\_MOC\_CLASSES constant
  - sample.cpp to the SCRIBUS\_SCRIPTMANAGER\_PLUGIN\_SOURCES constant
- TODO: what can be the sample action?
  - showing a message box? a bit stupid
  - ... putting a "sample" watermark on eacch page of the document... why not? One can set the text to be shown.
- add the widget (button, list, ...) with Qt Designer to the .ui file
- add the method doing the class into the Sample class

## Accessing the Scribus API

Scribus does not really have an API for plugins: You can access any functionality in Scribus from a plugin, but you have to take care that the code you're using is compiled before your own code.
"Notamment", if you want to use functionality defined in the Scribus class (defined in the scribuscore.h file) you will have to add the dependincy to the main executable file at the end of the plugins' CMakeLists file:
<pre>
ADD_DEPENDENCIES(${SCRIBUS_EXPORTEPUB_PLUGIN} ${EXE_NAME})
</pre>

## Using an "Options" structure to pass around the values from the dialog

## Adding a progress bar

## Debugging

If you can compile and install your plugin but on start Scribus says:

```
There is a problem loading 1 of 58 plug-ins.

- name of your plugin

This is probably caused by some kind of dependency issue or old plug-ins existing in your install directory. If you clean out your install directory and reinstall and this still occurs, please report it on bugs.scribus.net.
```

Then:
- check that the plugin `*_getPluginAPIVersion()`, `*_getPlugin()`,  and `*_freePlugin()` function names match the plugin library name.  
  eg. if plugin is named `myexportplugin` and the `*_getPluginAPIVersion()` is named `myplugin_getPluginAPIVersion()`, plugin will failed to load
- if plugin is not linked probably to its dependency it's another reason it may fail to load
