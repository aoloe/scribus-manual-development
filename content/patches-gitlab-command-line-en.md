# Gitlab: forking, branching and the pull request from the command line

## Login to Gitlab

If you don't have an account on Gitlab, create one.

## Forking the Scribus repository

- Go to <https://gitlab.com/scribus/scribus>
- Click on the button in the top right corner that says "Fork"  
- You now have your own repository called Scribus (https://gitlab.com/yourname/scribus, where yourname is the name you have chosen for Gitlab)

## Getting the code on your computer

This tutorial will assume that you're using from the command line.

If you don't have yet a place on your computer where you put the source code, you can create a `code` directory in your `Documents`.

`cd` to the `code` directory and clone your fork of Scribus:

```
git clone https://gitlab.com/<your-username>/scribus.git
```

or

```
git clone git@gitlab.com:<your-username>/scribus.git`
```

This will take some time.

As soon as the command is finished, you should have a `scribus` directory in the `code` directory.

You should also add the upstream Scribus directory as a remote. In the `scribus` directory and run the following command:

```
git remote add upstream https://gitlab.com/scribus/scribus.git
```

This will add an `upstream` remote on top of the `origin` one, that references your own fork of Scribus.

You can check the list of your remotes with:

```
git remote -V
```


## Branching

In your Gitlab fork, you need to keep your master branch clean, by clean I mean without any changes. This way, at any time you can create a new branch from your master.

Each time, that you want to fix a bug or a implement a feature, you need to create a new branch for it, which initially will be a copy of your master branch.

Those are often called _feature branches_, because the branch is specific to a feature.

You can create a new branch with:

```
git checkout -b your-new-feature
```


This will also automatically switch to the new branch.

It's a good idea to name the branch after the task you plan to achieve  (replace `your-new-feature` with a short description of your new feature).

Now you can start working on the your task!

You can see all branches created by using

```
$ git branch 
```

If you're working on `your-new-feature` and, in the past, have been working on `your-old-feature`, the command above will show :

```
  master
* your-new-feature
  your-old-feature
```

### Keeping up with the changes in Scribus

From time to time you'll need to pull the changes that have happened in the Scribus code. You can do so by fetching the `upstream` code (if you have added the upstream Scribus to the remotes as explained above) and applying your changes to your `origin/master`:

```
git fetch upstream
git checkout master
git merge upstream/master
```

Since you're not supposed to work on your master, this should work without generating any conflicts.

If you have long living branches or branches that are affected by the work other people are doing in Scribus, you should also apply the changes to the branches you're working on:

```
git checkout my-new-task
git merge master
```

This time, it is possible that merge conflicts happens: you will need to resolve, as git will tell you.

## Comitting your changes

Don't forget to commit you're code from time to time. Always make sure that you're working on your feature branch.

```
git commit . -m "a good commit message"
```

## Sending your changes: Merge requests and patch files

Scribus does not accept yet pull requests. But you you're still welcome to create a merge request:

- You can ask other developers to review your code by providing the link to your Merge / Pull request in the irc channel, the bug tracker, the forums, the mailing list, ...
- It will make it easy to create a patch file that you can upload in the Scribus bug tracker.

### Preparing the merge request: pushing to Gitlab

The merge request will be triggered from the Github webpage, so you need to make sure that all your changes are on Gitlab.

First, you'll need to make sure that you have committed all your work.

On the command line you can do:

```
git status
```

and check if there is anything that still needs to be committed.

Then – if took some time to create the patch – you should update your local code with the current state of the upstream repository (and eventually resolve the conflicts; see the chapter above about [Keeping up with the changes in Scribus](#) ).

Finally you can push your branch to Gitlab.


```
git push
```

For each branch, the first time you do a push you will be asked to create a _connection_ between the local branch and a new remote _origin_ branch. The error message will tell you how to use `git push -u` to get the branch on Github.


### Submitting the patch

Once the code is fine, you're ready for submitting your patch to the [official bug tracker](https://bugs.scribus.net).

You can again use your Merge Request to create the patch by using the download function on Gitlab, or create the patch on your own computer and upload it.


> TODO: Login per ssh
