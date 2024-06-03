# Adding commands to the scripter

The scripter is programmed as a plugin that resides in `scribus/plugins/scriptplugin/`.

## Adding a command to an existing module

Most of the time, the new command is added to an existing module.

The modules are files names with the `cmd` prefix that contain, for each command:

- the function declaration,
- the implementation, and
- the docstring.

Some of the commands are in object oriented module (the filename starts with `obj`.

### The modules

Currently there are 19 modules and three objects:

- `cmdannotations`: PDF links, scripts and annotations.
- `cmdcell`: Manipulate table cells.
- `cmdcolor`: Manage the documents colors.
- `cmddialog`: Show dialogs to the user.
- `cmddoc`: Open, list and save documents; manage the document settings and other document level elements (load styles, master pages).
- `cmdgetprop`: Get frame level properties.
- `cmdgetsetprop`: Low level _direct_ access to the item's properties.
- `cmdmani`: Manipulate items and selections.
- `cmdmisc`: Those commands that could not find a better home...
- `cmdobj`: Create and check items; some frame properties; get and set the text styles.
- `cmdpage`: Manage pages and set their properties.
- `cmdsetprop`: Set frame level properties.
- `cmdstyle`: List and create different types of styles.
- `cmdtable`: Manipulate tables (but not the cells).
- `cmdtext`: Manipulate text frames.
- `cmdutil`: Internal commands
- `cmdvar:`:  Defines some global variables and exceptions.
- `guiapp`: Set parts of the Scribus user interface (cursor, status bar, document view).
- `svgimport`: Importing vector files.
- `objimageexport`: Export the document as an image
- `objpdffile`: Export the document as pdf
- `objprinter`: Printing

The descriptions above, can help you finding out which is the right module.  
If you're still unsure on where to put your commands, you can search (grep) for a similar command and find out in which file it's defined:

- first search for the command in `scriptplugin.cpp`,
- then search for the file that contains the function that implements it (it normally starts with `scribus_`).

### Adding the command

Once you have found the relevant `cmd` file, you're ready to implement the new command.

For this example we are adding two commands: `embedImage` and `extractImage`.

We will first add them to the point where the command is exectuted, the arguments are parsed and checked. In a further step we will then add the real functionality.

All commands relating to the image frames are in `cmdmani`.

At the end of `cmdmani.h` we add the declaration for `embedImage`, which accepts the optional argument `name` (the item name: if it's not defined, the current item will be used).

```cpp
PyDoc_STRVAR(scribus_embedimage__doc__,
QT_TR_NOOP("embedImage(name:str = None )\n\
\n\
Embed the linked image for the image frame \"name\".\n\
If \"name\" is not given the currently selected item is used.\n\
"));
/*! embed the linked image in the frame */
PyObject *scribus_embedimage(PyObject * /*self*/, PyObject* args);
```

The `PyDoc_STRVAR` macro fills the `scribus_embedimage__doc__` variable with the docstring that will be attached to the Python command (and that will be used to generate the Scripter API documentation).  
The first line of the docstring contains the signature of the command, the other lines its description.

After the documentation comment for Doxygen, we have the declaration of the function:

- the return object is a `PyObject` (which in our case will always be null)


All Python functions need to return a PyObject

- `Py_RETURN_NONE` returns None
- `return nullptr` will trigger an unspecified exception.

### Silencing the compiler

In the `cmd*.cpp` you should add the two docstrings variables to the `cmdmanidocwarnings()` function (the function name and the comment say it all: it's just about avoiding the compiler complaining about the string not being used).

### Making the command available

- In `scriptplugin.cpp`, add the command to the list of the commands `scribus_methods`.  
  The three arguments are:

  - the name of the command as C string (`char *`);
  - a reference to the function that implements the command;
  - one of `METH_VARARGS` (normal arguments) , `METH_VARARGS|METH_KEYWORDS` (arguments and keyword arguments), or `METH_NOARGS` (no arguments);  
    For more details on the arguments, see [the Python C-api documentation](https://docs.python.org/3/c-api/structures.html#c.PyMethodDef);
  - the docstring as a C string (`char *`).

For functions with no arguments, it is necessary to to cast the function to `PyCFunction`:

```cpp
{const_cast<char*>("setNormalMode"), (PyCFunction)scribus_setnormalmode, METH_NOARGS, tr(scribus_setnormalmode__doc__)},
```

### Getting the command to work

- Do as little work as possible in the command itself.
- Make sure that the code in the Scribus files you're calling, do correctly implement the undo steps.

TODO: Adding a new class and adding a function to a class



### The command's arguments

#### none

#### positional arguments

#### named arguments

### Rerturn types

#### Lists

first initialize to the right size, then insert

```cpp
    auto compare = [page, layerId, itemType](const auto i)
    {
        return i->OwnPage == page &&
            i->m_layerID == layerId &&
            (itemType == -1 || i->itemType() == itemType);
    };

    int n = std::count_if(currentDoc->DocItems.begin(), currentDoc->DocItems.end(), compare);

    auto itemsList = PyList_New(n);
    int i = 0;
    for (const auto& pageItem: currentDoc->DocItems)
    {
        if (compare(pageItem))
        {
            PyList_SetItem(itemsList, i, PyUnicode_FromString(pageItem->itemName().toUtf8()));
            i++;
        }
    }

    return itemsList;
```

initialize to zero and append

```cpp
    auto itemsList = PyList_New(0);
    for (const auto& pageItem: currentDoc->DocItems)
    {
        if (pageItem->m_layerID == layerId && pageItem->OwnPage == pageNr)
        {
            auto pyName = PyUnicode_FromString(pageItem->itemName().toUtf8());
            PyList_Append(itemsList, pyName);
            Py_DECREF(pyName);
        }
    }

    return itemsList;
```

yes, you need to deference the item after adding it to the list.





- you will have to work in scribus/plugins/scriptplugin/
- find the right `cmd*` file to add the new function
- in `cmd*.h`  add the doc string for the new function
  - explain what the content means
  - follow the examples, for now
- in `cmd*.cpp`
  - add the main function
    - add the doc string to cmdtextdocwarnings() at the end of the file
- add the function in scriptplugin.cpp (after the preeding one in the `cmd*.cpp`)

### Troubleshooting

#### There is a problem loading `libscriptplugin.so`

If you have a typo in the function name – in `scriptplugin.cpp` or in the `cmd*.h|cpp` – Scribus might might compile but at boot time it will not be able to load the scripter plugin. Often you won't even get a warning.

In such a case, check again that the name of the functions do match!

#### `PyArg_ParseTuple` blah blah blah

If at runtime you get an error on the line with `PyArg_ParseTuple`, it's very likely that arguments definition in the string does not match the list of arguments in. It's very likely that you have an `es` (encoded string) without the matching "utf-8"...
