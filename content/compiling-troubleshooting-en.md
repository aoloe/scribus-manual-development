# Compiling: Troubleshooting

## Errors after a code update

Of course, it could be that some developer has pushed changes that break. That happens from time to time.

Before asking on the mailing list, irc or filling a ticket please do a clean build. If you have followed our instructions and are compiling in a separate `build` directory, just remove it, create a new `build` directory and run again `cmake` with all the options you need.

## Where is Scribus crashing?

If you have built Scribus with the debug symbols (using `-DCMAKE_BUILD_TYPE=Debug` in the `cmake` command), you can use `gdb` to find out the line in the code where the crash happens. Simply run

```
gdb /path/to/scribus/scribus
```


`gdb` might take a while to load everything ("Reading symbols from scribus...."). When you get a `(gdb) ` prompt, start
scribus by typing the "run" command.


If it still doesn't show anything useful, you can try running Scribus under valgrind:

```
valgrind -v --tool=memcheck /path/to/scribus/executable
```
