# Working with git

## Pulling in changes from the master

most branches are short living and it's not really a problem... but sometimes we really have to update them... and it can be a pain.

cezary says:
"git diff --stat origin/master" show you different files, if some of them differ because of changes in the master you do "git checkout origin/master -- path\_to\_file"... next step being a normall "git diff trunk svn" and carefully looks for places changed by other other people's commits, not from your branch.
