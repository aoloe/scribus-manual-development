# Your first patch

## Using Github

If you're using Github, please first read the section dedicated to working with the Scribus Github repository.

## Creating a patch file

- when doing the diff, you have to be in the main scribus directory (the one below the "scribus/" directory that contains the whole code).
- use the version system to create the patch:
  - `svn diff scribus/the_file_you_have_modified > name_of_my_patch.diff`
  - `git diff scribus/the_file_you_have_modified > name_of_my_patch.diff`
  that way you don't have to keep a copy of the original file, but can "automatically" compare the file you modified with the version you got when you last updated the repository.

Of course, you don't have to use the command line tool, but you can use your svn or git client to create the patch.

## Uploading a patch to the bug tracker

Once you have crated an account for the bug tracker you can attach your patch to an existing ticket (or create first a new ticket for it, if none matching exists).

- upload each diff file individually: that way they can be viewed in mantis itself

# Working with Qt Creator

## Creating a patch

While the file is opened, go to `Tools > Subversion > Diff "filename.cpp"`

There is also an option to make a diff of the whole source

![Diff with Qt Creator](images/qtcreator_diff.png)

