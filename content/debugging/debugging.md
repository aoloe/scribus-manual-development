#Debugging

There are three main issues wich you will have to debug in your code:

- Syntax errors that block the compilation.
- Errors that make your code crash during the execution.
- Errors that makes your code misbehave without any error being issued.

##Debugging with Qt Creator

This is 

##Debugging with qDebug()

The <kbd>qDebug()</kbd> command 

If you're working in a terminal, just launch your development version of Scribus from it, and the <kbd>qDebug()</kbd> messages will be displayed in there.

##Extending qDebug()

In most cases, <kbd>qDebug()</kbd> will correctly display the value of your variables. Most of all it will will behave quite well with Qt's own data structures. But not much later after having defined your own  data structures you may be stuck when trying to display their content.

<kbd>qDebug</kbd>'s <kbd><<</kbd> operator can be can be overload to manage the most complex structures.

Let's suppose that you want display the the content of a variable of type <kbd>QList<ScPage*></kbd> (whih is a list of pointers to Scribus pages objects) as a list of the number of those pages:

    (1, 2, 3, 5)

Your first step is to define the signature of the new operator in the header file where you want to use it:

    QDebug operator<<(QDebug dbg, const QList<ScPage*> &pages);

You have to take care, that you have defined the overloaded operator before it's first use, otherwise <kbd>qDebug()</kbd> will use it's "default" operator and simply output the address of your object.
An alternative to adding the signature to the header file is to have a forward definition of the method at the beginning of your source file or to put its definition at the beginning of the file (but you will rather want to "hide" it at the end of the file: it's not that important).


Now, you're ready to define you're overloaded operator:

    QDebug operator<<(QDebug dbg, const QList<ScPage*> &pages)
    {
        QStringList output;
        for (int i = 0; i < pages.length(); i++) {
            output << QString::number(pages.at(i)->pageNr());
        }
        dbg.nospace() << "(" << output.join(", ") << ")";
        return dbg.space();
    }

The salient parts are:

- In order to better graps which are the "immutable" parts that are expected by QDebug "as is", here is a version of the signature with variables parts replaces by a bunnch of "x" and "y": <kbd>QDebug operator<<(QDebug dbg, const xxxxxxx &yyyyyyy)</kbd>. xxxxxx must correspond to the type of the structure you want to display and yyyyyy is the name of the variables inside of the <kbd><<</kbd> operator's definition.
- 

