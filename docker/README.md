
---
# Building and sharing the image

* `build.sh` : apply the Dokerfile recipe, building a local image whose name is taken from `name.txt`.
* `push.sh` : push the image `name.txt` to the registry, which requires access rights to this registry.


---
# Starting a container

* `run.sh` : start a container from the image `name.txt`, and run the command given as arguments (default is `bash`). The current directory is mounted as `/work`, and this is where the command is executed.
* `run_x11_macos.sh` : same as `run.sh`, plus X11 forwarding, in macOS flavor. It requires some prerequisites: see next section.
* `run_x11_linux.sh` : same as `run.sh`, plus X11 forwarding, in linux flavor.
* `run_x11_win.sh` : same as `run.sh`, plus X11 forwarding, in windows flavor. It requires some prerequisites: see next section.
* `versions.sh` : type `./run.sh ./versions.sh` within the `docker` directory, and you should check the version of the installed tools in the image.


---
# X11 applications

For the use of applications with X11 graphics, especially `kcachegrind`, one must setup the forwarding of X11 commands from the container to the host machine, which may be turn complex, depending on your system. We provide a set of scripts `run_x11_<os_flavor>.sh`. Except for linux, it requires to start an X11 server emulator, and define some environment variable `MYIP`, which should contain the IP number associated your host and X11 session. We give below some tricks for each system.  Once you think it should work, try the script `xeyes_<os_flavor>.sh`.

## macOS

1. Install and start XQuartz. 
1. Search for your IP number, using terminal command `ifconfig` and searching for `inet` lines.
1. Define `export MYIP=<your_ip_number>`.
1. Check with `xeyes_macos.sh`.
1. Run `run_x11_macos.sh`.

## Linux

1. Check with `xeyes_linux.sh`.
1. Run `run_x11_linux.sh`.

## Windows

1. Install and start Xming or Exceed. For Xming, we recommend those options: `Xming :0 -multiwindow -clipboard -ac`.
1. The applications above should enable you to get some IP number, typically `10.0.75.1` for Exceed.
1. Define `export MYIP=<your_ip_number>`.
1. Check with `xeyes_win.sh`.
1. Run `run_x11_win.sh`.

