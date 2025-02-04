# Icons

## Creating icons for 1.7+

- The icons are svg files.
- Put your icons in `resources/iconsets/1_7_0/16`
- Link them in `resources/iconsets/1_7_0/1_7_0.xml`


Question: why `22/`

Toolbutton with a different icon when checked:

```
QIcon icoPrint;
icoPrint.addPixmap(im.loadPixmap("NoPrint.png"), QIcon::Normal, QIcon::On);
icoPrint.addPixmap(im.loadPixmap("16/document-print.png"), QIcon::Normal, QIcon::Off);
noPrint->setIcon(icoPrint);
```

## Using Inkscape

- Create a new file
- In document setup,
  - pick the size "other > icon > 16"
  - set the unit and view item to px
  - 1:1
- With "grid creator" create guides in 16 colums and rows.
- Snap to guides.
- Save as "Optimized SVG"
- For half movements, it's best to edit the node definition in the "Object properties" panel

Issues:

- no way to 
- hard to attach a class
  - <https://wiki.inkscape.org/wiki/index.php/Style_Editor#.27class.27_selectors>
  - <https://wiki.inkscape.org/wiki/Release_notes/1.0.1#Selectors_and_CSS_dialog_unhidden>
