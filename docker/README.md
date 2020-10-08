
---
# Building and sharing the image

* `build.sh` : apply the Dokerfile recipe, building a local image whose name is taken from `name.txt`.
* `push.sh` : push the image `name.txt` to the registry, which requires access rights to this registry.


---
# Starting a container

* `run.sh` : start a container from the image `name.txt`, and run the command given as arguments (default is `bash`). The current directory is mounted as `/work`, and this is where the command is executed.
* `versions.sh` : type `./run.sh ./versions.sh` within the `docker` directory, and you should check the version of the installed tools in the image.


---
# X11 applications

For the use of applications with X11 graphics, especially `kcachegrind`, one must setup the forwarding of X11 commands from the container to the host machine, which may be turn complex, depending on your system.

As a general mechanism, we provide a script `run.sh` which requires you to define a, environment variable `MYIP`, which should contain the IP number associated your host and X11 session. We give below some tricks for each system.  Once you think it should work, try the script `xeyes.sh`.

## MacOSX

1. Install and start XQuartz. 
1. Search for your IP number on MacOS, using command `ifconfig` and searching for `inet` lines.
1. Define `export MYIP=<your_ip_number>`.

## Linux

1. Search for your IP number on MacOS.
1. Define `export MYIP=<your_ip_number>`.

## Windows

1. Install and start Xming or Exceed. For Xming, we recommand those options: `Xming :0 -multiwindow -clipboard -ac`.
1. The applications above should enable you to get some IP number, typically `10.0.75.1` for Exceed.
1. Define `export MYIP=<your_ip_number>`.

