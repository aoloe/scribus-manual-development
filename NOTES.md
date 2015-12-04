# Notes

- have a look at <http://www.kdab.com/kdab-products/gammaray/>, an introspection tool specific to Qt. it might be able to set break points at runtime.

## Ubuntu
To compile and run scribus without problem in Ubuntu 12.10 you may need to set the  paths to python libs or add them to cmake command line, otherwise python3 libs will be preferred over python2

`cmake ../Scribus -DWANT_SYSTEM_CAIRO=1 -DCMAKE_INSTALL_PREFIX=../Scribus-bin -DPYTHON_LIBRARY=/usr/lib/libpython2.7.so -DPYTHON_INCLUDE_DIR=/usr/include/python2.7`

## Writing good bug reports

- a good example of bug report: <http://bugs.scribus.net/view.php?id=13026>

## How to find out if a line has a bad behavior

> I'm trying to solve the following issue http://bugs.scribus.net/view.php?id=12245 ,
> and found this line in pageitem_group.cpp:193
>
>          p->scale(m_width / groupWidth, m_height / groupHeight);
>
> What's the purpose of scaling here?! and it's scaling by 1.

this question makes me wonder about the need of refactoring in scribus.

the suggestions by as. to simply remove the

https://github.com/scribusproject/scribus/blob/master/scribus/pageitem_group.cpp#L193

line looks like the right thing to do.

not because it's a wrong line, but because when i look at the DrawObj_Item() function, the only purpose -- implicitly  declared -- is the general task of drawing the group.  
without further notice in the code, i would expect that the method simply delegates the drawing to each element in the group.  
nothing less, nothing more.  
in this context, there should never be a function that modifies the scale of a variable which is not local to the function itself.  
not without an explanation on why the line is there.


now back to reality.  
the line 193 probably has a purpose.

let's find out what the purpose could be!

what as. could do is to do a blame on that line

~~~
$ git blame scribus/pageitem_group.cpp -L 190,195
33527943 (Franz Schmid  2014-01-27 19:44:13 +0000 190)  else
33527943 (Franz Schmid  2014-01-27 19:44:13 +0000 191)          p->beginLayer(1.0 - fillTransparency(), fillBlendmode());
69781711 (Jean Ghali    2012-02-10 22:20:30 +0000 192)  p->setMaskMode(0);
4aca2e1d (Craig Bradney 2013-01-15 22:03:04 +0000 193)  p->scale(m_width / groupWidth, m_height / groupHeight);
69781711 (Jean Ghali    2012-02-10 22:20:30 +0000 194)  for (int em = 0; em < groupItemList.count(); ++em)
69781711 (Jean Ghali    2012-02-10 22:20:30 +0000 195)  {
~~~

now we know that the line has been last changed by craig in 2013, after jean changed the surrounding lines one year early (and we see that franz has also added some more lines more recently before those lines.

let's have a look at the commit that introduced that line:

https://github.com/scribusproject/scribus/commit/4aca2e1d#diff-f5de24759cc7fd0558e9d8ab73448db4L190

that was only a general refactoring in pageitem. it does not help us finding out the reason for that line.

let's do a git log on that line!

~~~
$ git log -L 193,193:scribus/pageitem_group.cpp
commit 4aca2e1d32dcdcb3a417677b29bb13f534717ae3
Author: Craig Bradney <mrb@scribus.info>
Date:   Tue Jan 15 22:03:04 2013 +0000

    Rename PageItem's Width/Height, some more rearranging of pageitem.h

    git-svn-id: svn://scribus.net/trunk/Scribus@18095 11d20701-8431-0410-a711-e3c959e3b870

diff --git a/scribus/pageitem_group.cpp b/scribus/pageitem_group.cpp
--- a/scribus/pageitem_group.cpp
+++ b/scribus/pageitem_group.cpp
@@ -190,1 +190,1 @@
-       p->scale(Width / groupWidth, Height / groupHeight);
+       p->scale(m_width / groupWidth, m_height / groupHeight);

commit 697817116aa6a550bd648e49a24ec499184e5d67
Author: Jean Ghali <jghali@libertysurf.fr>
Date:   Fri Feb 10 22:20:30 2012 +0000

    some refactoring of graphics related function :
    - improve readability by removing some unnecessary indentation levels
    - split ScPainter::drawVPath() functions
    - remove unused fillPathText() and strokePathText() function from ScPainter

    git-svn-id: svn://scribus.net/trunk/Scribus@17288 11d20701-8431-0410-a711-e3c959e3b870

diff --git a/scribus/pageitem_group.cpp b/scribus/pageitem_group.cpp
--- a/scribus/pageitem_group.cpp
+++ b/scribus/pageitem_group.cpp
@@ -237,0 +190,1 @@
+       p->scale(Width / groupWidth, Height / groupHeight);
~~~

ok, the line has been inserted by jean in 2012 while refactoring... we have to have a look at his commit, then: no luck, either: the line is older:

    112 - p->scale(Width / pat.width, Height / pat.height);

now, if the original author of the line does not step in, you will have to go on with this speleological research until you have found out who has written that specific line and why!
i stop here, because it's not the main goal of this mail (and i'm no git expert), but i hope that the commands i've shown above can help you and the other guys to better work with such issues!






and i go back to the main topic: how the hell is somebody supposed to understand what that line is doing and how to change it, if in some cases it seems to do harm?

what i'd like to suggest you and the team:

    PageItem_Group::DrawObj_Item() does urgently need some refactoring!

to make the code more explicit, we don't want to comment each line to say what it is doing. we're not programming in assembler...

so, how can we then document what DrawObj_item() is doing?  
for sure by writing some doxygen doc for the method.  
but also by splitting the 90 lines long method in a few private function with telling names, names that automatically tell the reader what is going on.


so, my question to the team is: would be it be ok to ask as. to create a new private function with the code around

    p->scale(m_width / groupWidth, m_height / groupHeight);

so that it's clear what that line does?

in my eyes, in such a case, the programmer should not refactor the whole DrawObj_Item() function, just the lines that she fears are offending.  
the refactoring should be submitted as a separate patch.  
and only after having refactored the code (and in this way having shown that she understood what the specific line is doing) she should apply the change and submit a patch for it.

of course, the patch for refactoring the existing method, should be submitted even if the bug was not there :-)

and, of course, not every line should be in its own function! but in my experience 10 lines is somehow the ideal length or a function.


and my proposal to HOST:

- when you touch a function, always try to write a doxygen doc for it and make a patch with it (if the team agrees that there is a need for it, of course... and the comment should describe what the function does and not be obvious: no /** @return returns x */ ABC::getX() {return x;}, please :-)
- when you see a function that does multiple things that are not summarized in the function name, split the function in private function that are specific to the task (always if the team agrees)

if you don't know what refactoring or doxygen are, please first read the Wikipedia entries:

- https://en.wikipedia.org/wiki/Code_refactoring
- https://en.wikipedia.org/wiki/Doxygen

### Documenting the class members

    Double oldXpos; ///< Stores the old X-position for undo action. Is used to detect move actions.

that's an example of doxygen doc.


is not in my eyes a perfect doxygen comment:

    double oldXpos; ///< used for detecting move actions .

would probably have been better, since the name of the class member variables already says that it's an old x position... we should try to keep them as short as possible and only document what we could not write in the name itself.

## How to face new code

On December 3 2015, Jason says on the cmus list:

"I just wanted to add that my personal preference is to dive deep
into one aspect of the software instead of trying to get a broad
understanding first. Usually I want to track down a quirk or bug,
and see if I can change/improve it, but it works just as well if
I'm just curious about some detail.

Usually, as I try to figure out what's going on in that specific
part of the code, I end up learning a bit about the bigger picture
too, but I like the structure of trying to understand one part, and
how it feels like I understand something well much sooner, even if
it's just a small part."
=======
