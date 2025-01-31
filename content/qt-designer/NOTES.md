# Using Qt Designer

For panels that use the advanced docking system and the section, you need to add a Qt Plugin that has been created for Scribus.

The plugin contains the SectionContainer (for the expandable sections) Widget and FormWidget (for the fields with informational labels).

- In the Scribus main source directory there is a `ScribusDesignerPlugins.pro` file.
- Create the directory `build-qt-plugin` and cd into it.
- `qmake6 ..`
- `make`
- copy the library `libScribusDesignerPlugins.so` that has been generated to the Qt 6 directory for the designer plugins.
  - On Linux it can be `/usr/lib/x86_64-linux-gnu/qt6/plugins/designer`
  - On Mac it is something similar to `Qt/Tools/QtCreator/lib/Qt/plugins/designer`
  -
