# Data Structures

This is my DStruc repo.

All of the Assignments are under the Sorting folder

## Bugs Galore

One interesting bug I found (or rather, created):

While attempting to push my files to git then github, I found that it was not working. 

It was saying that I did not have access to the repo.

Originally thought that my method of commiting to git was the issue, so looked to multiple ways to commit, thinking that I was just doing incorrectly. Essentially just stopped github for a while. 

Found that the error was caused by previously commiting to git through different folders, then adding all these folders into one, and
committing it again.
Essentially, I had multiple folders that were already uploaded to github, but after hearing that we were supposed to only have one repo, I changed it to have only one. The other repo is still up, however.

From this, I:
- removed empty folders
- removed the .git and .vscode files from every folder
- removed any repeats

It still was not pushing to git, so I decided to force push the files to github using -f 
- This is why the message for many commits it "Commit Trial"

After this, all of my folders & files were updated to git, other than the Nodes file
- On github, it was shown as a folder with an arrow on it
- This folder was also not opening

I found that I had accidently created a submodule in git.

Currently working to fix this bug, but a work in progress.

UPDATE: I am ignoring the bug for now, but I am putting the files for LinkedLists under sorting, so the dates are messed up a bit. I am not sure if the correct dates will ever pop up.

UPDATE: ran the 
git rm -r --cached . 
command to update my .gitignore file.
Somehow, the submodule was removed, and it is working again.