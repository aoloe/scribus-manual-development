# Tranlating the Scribus UI

Scribus is localized in 62 lanaguages, but most of them are far from being fully translated, only a few being close to be complete. This means there's a lot of demand for translators!

You have three possible workflows for editing the translatable strings:

- You can join the localization team on Transifex, a very popular, easy to use (but proprietary) platform for localization.
- You can edit the localization files with a text editor.
- You can use Qt Linguist, 

That's it. There isn't that much to it aside from the initial setup. Now this should be a suitable setting for you to live-test your translations easily! I hope this little tutorial has been helpful!

For more information, please refer to the current scribus wiki or contact the devs over at #scribus on IRC, they're very friendly.

## Translating the `.ts` files

In this documentation we assume that you have the Scribus source code in `~/src/scribus`. You will have to adapt the instructions if your paths are different.

That and the folder ~/src/scribus/resources/translation should be the ones we'll use the most and the ones we will care about.

Note that the output mentions several localization files, the kind we will be using for translating, such as scribus.pt_BR.ts

Similarly, you can translate the files locally by simply editing the aforementioned localization files (the ones with .ts extension under scribus/resources/translations) on a text editor.

## Transifex

On Transifex, after changing any string, you should be able to go to your Dashboard, visit the section for your language pair and click on Resources. Download the file for use, rename it according to the scheme in ~/Scribus/resources/translation and replace it!

## Using Qt Linguist

You can also translate your loacal `.ts` files  Qt Linguist (which should be provided by the package `qt5tools`).

- document how to do the translation: <https://doc.qt.io/qt-5/linguist-translators.html>
- <https://doc.qt.io/archives/qt-4.8/linguist-manager.html>
- `lrelease scribus.pro` to produce the `.qm` files

## Testing the translations on your machine

There are two ways you can run Scribus with your up-to-date translations: by building the application itself or by changing the AppImage files.

Now, the localized files that were previously .ts now have a .qm extension and should be installed in ~/bin/scribus/resources/translations/. Sadly, we can't edit/translate these kinds of files.

## Workflow

I'd suggest checking how your translation looks in Scribus every 1000 or 2000 words. This way, you can always keep in mind more or less where each part you translated is and whether the language you used is consistent, while also not interrupting your workflow much. But it's just a suggestion!

This will change your current local Scribus to include the new translation. It should give you a better idea on whether your translation fits well with the interface or not, if it's consistent, if there were typos or mistakes regarding variables, or if the interface reads fluently like one would expect from a professional desktop publishing application.

Having changed the `.ts` for your language, `make install` the new code before you can test it.

## Using Gitlab's CI to produce your binaries for Linux

- Fork the Scribus repository.
- Setup the continous integration (CI) to create the the appimages.
- Use Gitlab's webeditor to edit or upload your translations.

## Using the appimage

