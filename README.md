#Data Structures

This is my DStruc repo

##Bugs Galore

One interesting bug I found (or rather, created):

While attempting to push my files to git then github, I found that it was not working. 

It was saying that I did not have access to the repo.

Found that the error was caused by previously commiting to git through different folders, then adding all these folders into one, and
committing it again.
Essentially, I had multiple folders that were already uploaded to github, but after hearing that we were supposed to 

From this, I:
- removed empty folders
- removed the .git and .vscode files from every folder
- removed any repeats

It still was not pushing to git, so I decided to force push the files to github using -f 

After this, all of my folders & files were updated to git, other than the Nodes file
- On github, it was shown as a folder with an arrow on it
- This folder was also not opening

I found that I had accidently created a submodule in git.

Currently working to fix this bug, but a work in progress.
