# User interface and user experience

See:

- https://wiki.scribus.net/canvas/IndigoUI_Style_Guide

## The basic concepts

The UI spacing grid follows a rule of 4, 8, 16, 24, 32 etc.

As an example, button group spacing is 4, widget margin is 8, icon size is 16. 

## Qt Designer

- Creating a buddy for a QLabel (the accelerator on the label triggers -- as an example -- a combobox):  
  <https://doc.qt.io/qt-6/designer-buddy-mode.html>
- Promeote a Qt widget to a Scribus widget (as an example a `QDoubleSpinBox` to `ScrSpinBox`)
  - Open another .ui file that already contains the Scribus widget.
  - Insert the Qt widget the Scribus Widget is extending.
  - In the context menu choose _Promote to >_ and pick the Scribus widget.
  - <https://doc.qt.io/qt-6/designer-using-custom-widgets.html>

## UI Spacing

### Dialogs

- QDialog, QGroupBox shall have margins of 8.

### Palettes

Palettes are

- `QWidget`s,
- each section being a `SectionContainer`,
- The horizontal groups with a label below being a `FormWidget`.

### Horizontal layouts

- `layoutSpacing: 4` if the items belong together
- `layoutSpacing: 16` if the items are sections (`FormWidgets`, ...)

## Tips and tricks

### ScrSpinBox

- `ScrSpinBox`es extend `QDoubleSpinBox` and not `QSpinBox` (but you can set the number of decimals to zero).
- By default, Scribus uses "px" as the default suffix for `ScrSpinBox`es. If you want to keep the value without any unit, you need to uncheck _translatable_ for the field.

