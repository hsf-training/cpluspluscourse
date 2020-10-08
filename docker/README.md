* build.sh : apply the Dokerfile recipe, building an image whose name is taken from `name.txt`.
* push.sh : push the image `name.txt` to the registry
* run.sh : start a container from the image `name.txt`, and run the command given as arguments. The current directory is mounted as `/work`, and this is where the command is executed.