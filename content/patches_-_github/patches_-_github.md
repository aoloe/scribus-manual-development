# Github: forking, branching and the pull request

This chapter has been inspired by https://github.com/Kunena/Kunena-Forum/wiki/Create-a-new-branch-with-git-and-manage-branches

I should integrate some things <from http://forum.freecadweb.org/viewtopic.php?f=17&t=3781> (using mantis instead of the forum?)

> TODO: add a short version of this document? (tldr.md)

## Github

- If you don't have an account on Github, create one

## Forking the Scribus repository

- Go to https://github.com/scribusproject/scribus
- Click on the button in the top right corner that says "Fork"  
  ![Fork Scribus on Github](images/github_-_fork.png)  
  ![Fork Scribus on Github](images/github_-_forking.gif)
- You now have your own repository called Scribus (https://github.com/yourname/scribus, where yourname is the name you have chosen for Github)

> TODO: add origin
> - syncing from upstream: https://help.github.com/articles/syncing-a-fork

## Branching

In your github fork, you need to keep your master branch clean, by clean I mean without any changes, like that you can create at any time a branch from your master. Each time, that you want to commit a bug or a feature, you need to create a branch for it, which will be a copy of your master branch.

The easy way is to create a new branch on GitHub by typing the new name in the "Branches" selector.

> TODO: screenshot

It's a good idea to name the branch after the task you plan to achieve.

Now, you need to get the new branch on your local machine.

On the command line

    $ git checkout -b <name_of_your_new_branch> origin/<name_of_your_new_branch>

This will also automatically switch to the new branch.

Now you can start working on the your task!


You can see all branches created by using

    $ git branch 
    Which will show :

    * approval_messages
      master
      master_clean

## Comitting your changes

Don't forget to commit you're code from time to time.

You're also welcome to push your changes to your GitHub repository. If you have questions about your work, this is the best way to show the issues to the other contributors.

## Preparing the pull request

When you're done with you're task, it's time for a pull request.

First, you'll have to make sure that you have committed all your work and, then make sure that you're code base is up to date with the Scribus' master.

Replace the following commands by the ones in the link below:

    $ git fetch <name_of_your_remote>
    Then you need to apply to merge changes, if your branch is derivated from develop you need to do :

    $ git merge <name_of_your_remote>/develop
    Delete a branch on your local filesystem :

- see https://help.github.com/articles/syncing-a-fork

## Doing the pull request

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






## Using GitHub to browse the Scribus code

It's create a new branch of your repository, with a name that matches your change.
- In Scribus find a string that refers to what you want to change and that is somehow not too common.
- On Github, search for that string in the repository by using the "Search" field in the top part of the page.
- Click on the file that matches your result (you might have to click on a few files before finding the right one; if you get too many results, try to use another search criterium and put quotes around sentences)
- Click on the edit icon make the change and commit it.
- If you want to test the change, clone the repository on your computer (or pull the new version if you already have it locally), switch to the new branch and compile as usual.
Once you're comfortable with this way of doing, you should try to do patches on the source code that you have pulled on your computer.

