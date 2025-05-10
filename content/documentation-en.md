# Writing the documentation

Currently Scribus has:

- A very outdated built-in documentation that try to covers way more than the usage of the software itself.
- A wiki with lot of unmaintained nd outdated information.
- Several few older books and online tutorials.
- Several Youtube channels, some of rather good quality but still teaching a few _bad habits_.

## Proposal for a new documentation

The goal is to create:

- A free documentation.
- That is easy to keep up to date.
- That is managed by long term maintainers but also allows one shot contributions.
- Can be translated in multiple languages.

### Technical choices

- Use markdown (with styles).
- Use a text editor (or an IDE like vS Code)
- Use Git for collaboration.
- Use mkdocs to produce HTML output.
- Use mkdocs to produce Epub output.
- Provide a WYSIWYG temporary solution for contributors that are not comfortable with Git and Markdown and want to work on specific parts of the documentation.

### Content

- Instead of creating one big documentation, create multiple simpler and focused documentation..
- Translate and update "Initiation à Scribus" by Cédric Gémy (GPL):
  - About 100 A5 pages.
  - Covers most Scribus basics.
- Create a "first steps" document.
- A document for people evaluating Scribus (_marketing_...)
- Create task oriented documents:
  - For details, the can point to other documentation
  - Possible tasks:
    - Typesetting a novel
    - Writing technical documentation
    - Publishing a newspaper
    - Publishing a magazine
    - Publishing comics
    - Creating a flyer / leaflet
    - Creating a scientific poster
    - Creating a photobook
    - Writing scripts
    - Collaborating on documents
    - Workflows (content translations, proofreading, getting content from contributors)
- Document specific topics:
  - PDF and printing
  - Colors
  - Fonts
  - Languages and translations
  - Text formatting
  - Tables
  - Images
- Special documents:
  - Scribus development (this document)
  - Troubleshooting / FAQ
  - Glossary (explain DTP and Scribus specific terms)
  - List of tutorials

### Notes on the official Scribus documentation

The official Scribus documentation:

- Is published under a license that is not free (please don't use its content for creating free documentation)


### Notes on the Scribus Wiki

The Scribus Wiki has been used in the past to document Scribus.

This somehow worked at a time when Scribus had a bigger team and a big stable community.

But:

- It's hard to integrate new contributors.
- It's not easy to track the outdated content.
- Does not work for enthusiastic one shot contributions.

### Notes

- https://deborahwrites.com/blog/docs-like-code-basic-intro/
- https://docascod.github.io/howto/#/?id=main
- https://docsascode.org/
- https://www.writethedocs.org/guide/
- https://www.synesthesia.co.uk/tag/docsascode/
- https://cryptpad.org/

