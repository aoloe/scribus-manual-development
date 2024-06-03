# Github: forking, branching and the pull request with the Desktop app

This chapter has been inspired by https://github.com/Kunena/Kunena-Forum/wiki/Create-a-new-branch-with-git-and-manage-branches

> TODO: integrate some things from <http://forum.freecadweb.org/viewtopic.php?f=17&t=3781> (using mantis instead of the forum?)

> TODO: add a short version of this document? (tldr.md)

> TODO: make separate tutorials for the Github desktop app and one for the command line

## Login to Github

If you don't have an account on Github, create one.

## Forking the Scribus repository

- Go to <https://github.com/scribusproject/scribus>
- Click on the button in the top right corner that says "Fork"  
- You now have your own repository called Scribus (https://github.com/yourname/scribus, where yourname is the name you have chosen for Github)

## Getting the code on your computer

You can get the code from your own Scribus fork by using the [Github Desktop App](https://desktop.github.com/), any of the GUI clients or with the command line Git tool.

This tutorial will assume that you're using the Github own [Desktop app](https://desktop.github.com/).

If you prefer to use Git from the command line you can [continue with this chapter](patches-github-command-line.md)

> TODO: describe how to get the code with the Github Desktop app

## Branching

In your github fork, you need to keep your master branch clean, by clean I mean without any changes. This way, at any time you can create a new branch from your master.

Each time, that you want to fix a bug or a implement a feature, you need to create a new branch for it, which initially will be a copy of your master branch.

Those are often called _feature branches_, because the branch is specific to a feature.
Create a new branch by clicking on the "Create branch" button:

![Create branch](patches-github/branch-button.png)


It's a good idea to name the branch after the task you plan to achieve.

This will also automatically switch to the new branch.

Now you can start working on the your task!

## Comitting your changes

Don't forget to commit you're code from time to time. Always make sure that you're working on your feature branch.

Simply click on the "Commit" button at the button of the window.

## Sending your changes: Pull requests and patch files

Scribus does not accept yet pull requests. But you you're still welcome to create a pull request:

- you might get useful feebdack,
- it will make it easier to create a patch file that you can upload in the Scribus bug tracker.

### Preparing the pull request

The pull request will be triggered from the Github webpage, so you need to make sure that all your changes are on Github.

First, you'll need to make sure that you have committed all your work.

On the command line you will do:

```
git status
```

Then you'll need to push your branch to Github.

## Doing the pull request

In 
- the pull request is being done on the GitHub website
- If you're happy with your change, make a pull request by going to the main page of your repository and clicking on the green button left of the branch name, in the header of the page.
- don't change your branch after you have done the pull request: your changes will also change the pull request!
- Don't use the same branch for other changes, since those will be added to the pull request you already sent.

When you do a pull request on a branch, you can continue to work on another branch and make another pull request on this other branch.

## Cleaning up

Once your pull request has been accepted, you can delete your branch.

It's simpler to delete the branch on GitHub:

- The ticket attached to your pull request, will ask you if you want to remove the branch: just do it
- The alternative, being 

$ git branch -d <name_of_your_new_branch>
To force the deletion of local branch on your filesystem :

## Keeping the code in sync

 sure that you're code base is up to date with the Scribus' master.

Replace the following commands by the ones in the link below:

    $ git fetch <name_of_your_remote>
    Then you need to apply to merge changes, if your branch is derivated from develop you need to do :

    $ git merge <name_of_your_remote>/develop
    Delete a branch on your local filesystem :

- see https://help.github.com/articles/syncing-a-fork


> TODO: add origin
> - syncing from upstream: https://help.github.com/articles/syncing-a-fork


## Troubleshooting

### I forgot to create a feature branch

If you have already edited the code but did not create a branch, don't worry. As long as you have not commited your changes, you're still in time for creating a local branch and commit your changes in there.

You will be then able to push the local branch to Github.


## Using GitHub to browse the Scribus code

It's create a new branch of your repository, with a name that matches your change.
- In Scribus find a string that refers to what you want to change and that is somehow not too common.
- On Github, search for that string in the repository by using the "Search" field in the top part of the page.
- Click on the file that matches your result (you might have to click on a few files before finding the right one; if you get too many results, try to use another search criterium and put quotes around sentences)
- Click on the edit icon make the change and commit it.
- If you want to test the change, clone the repository on your computer (or pull the new version if you already have it locally), switch to the new branch and compile as usual.
Once you're comfortable with this way of doing, you should try to do patches on the source code that you have pulled on your computer.

