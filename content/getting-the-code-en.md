# Getting the code

## SVN and Git

You can get the code from the Scribus own Subversion repository

```bash
svn co svn://scribus.net/trunk/Scribus scribus
```

or from one of the community maintained mirrors:

- From the Github mirror:  
  `git clone git@github.com:scribusproject/scribus.git` or  
  `git clone https://github.com/scribusproject/scribus.git`
- From the Gitlab mirror:   
  `git clone git@gitlab.com:scribus/scribus.git` or  
  `git clone https://gitlab.com/scribus/scribus.git`

The Scribus Team, also provides packages with the Source code for each release, but they are of little interest, except if you are packaging Scribus.

Provided Git or Svn are installed, You can type in the terminal the `git` or `svn` command above and get the code or you can use one of the many GUI tools for managing Git and Snv repositories.

In the furter instructions, we will assume that you have your source code in `~/src/` (where `~/` is your home). You will have to adapt the instructions if your paths are different.

If you're using Qt Creator the chapter dedicated to its usage will explain how to get the code and create a new project in one go.

It will take quite a while to download the whole source code.

## Forking the code for development

If you plan to work on the Scribus code and are using Git, you should create and clone your own fork of the [scribus repository](https://github.com/scribusproject/scribus):

- Most likely, you will need to setup your system and your Github account to use ssh keys: <https://help.github.com/articles/connecting-to-github-with-ssh/>
- Use the "Fork" button at the top of the [scribus repository](https://github.com/scribusproject/scribus) to create your own fork.
- Clone your own copy of Scribus: `git clone https://github.com/your-username/scribus.git`

For more details please read [Github's forking manual](https://help.github.com/articles/fork-a-repo/).
