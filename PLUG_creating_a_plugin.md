- create a new directory in the plugins/ directory with the name of the plugin (or in one of its subdirectories if the new plugin is part of a type). In this examples we will use the name "sample"... to create the sample plugin.
  - the boilerplate for loading and defining your code as a plugin, will go the file "sampleplugin.cpp"
  - the main code of your plugin will go to "sample.cpp"
  - if you are creating a dialog it will be called "sampledialog.ui" and it will be included through the files "sampledialog.cpp" and "sampledialog.h"
- create the main plugin class, named with the name of the plugin and the word "plugin".
  sampleplugin.cpp
  <pre>
  </pre>
  sampleplugin.h
  <pre>
  </pre>
  
  in the parameters for ::run(): what is QString target?

- add the directory to the plugins/CMakeLists.txt file as:
    ADD_SUBDIRECTORY(pluginname)
- add a CMakeLists.txt file in the plugin directory
