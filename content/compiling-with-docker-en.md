# Compiling Scribus with a Docker container

Goals:

- editing the source from outside of the container
- compiling Scribus inside the container or  "from outside" of the container
- run Scribus from inside the container or through an Appimage
- maybe trying witht https://code.visualstudio.com/docs/devcontainers/create-dev-container
- Maybe try a VOLUME directive in the dockerfile (See: https://docs.docker.com/reference/dockerfile/#volume)


- (install the `docker.io` package) (add yourself to the docker group; until you restart the X session, you need to activate the new group for each terminal: `newgrp docker`)
- list the installed images: `docker images`
- `docker pull registry.gitlab.com/scribus/scribus-ci-docker/main`
- `docker run -i -t registry.gitlab.com/scribus/scribus-ci-docker/main /bin/bash`

```sh
mkdir build
cd build
cmake -GNinja -DCMAKE_INSTALL_PREFIX:PATH=/home/ale/bin/scribus-gitlab -DWANT_DEBUG=1 -DWANT_GUI_LANG="en_GB;de;fr;it;en" ..
```


- `git clone --depth 1 https://gitlab.com/scribus/scribus.git`
- `cd scribus`

## Using a shared folder

```sh
cd ~/src
git clone --depth 1 https://gitlab.com/scribus/scribus.git scribus-docker
```

Adding to the dockerfile: https://docs.docker.com/reference/dockerfile/#volume
Adding at run time: https://docs.docker.com/engine/storage/bind-mounts/

```sh
docker run -i -t --mount type=bind,src=/home/$USER/src/scribus-docker/,dst=/mnt --user $(id -u):$(id -g) registry.gitlab.com/scribus/scribus-ci-docker/main /bin/bash
```

TODO:

- `--workdir="/mnt"`

Resources:

- use the local user:
  - https://stackoverflow.com/questions/45836272/running-as-a-host-user-within-a-docker-containerf
  - https://www.baeldung.com/ops/docker-set-user-container-host

with podman:

```sh
podman run -i -t --mount type=bind,src=/home/$USER/src/scribus-docker/,dst=/mnt --privileged --user $(id -u):$(id -g) registry.gitlab.com/scribus/scribus-ci-docker/main /bin/bash
```

```sh
cmake -DCMAKE_INSTALL_PREFIX:PATH=/mnt/scribus-docker/bin -DWANT_NOOSG=1 -DWANT_DEBUG=1 -DWANT_GUI_LANG="en_GB;de;fr;it;en" ..
make -j$(nproc)
```

You now cannot run the binary: the local system does not have the necessary shared library installed and docker has no acces to the local X11 server.

Two possible solution:

- let docker access the local X11
- create an Appimage that you can then run on the host system

#### Letting docker accessing X11

allow the group docker to access X11:

```
xhost +local:docker
```

Run docker with `-e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix`:

```sh
docker run -i -t \
    --mount type=bind,src=/home/$USER/src/scribus-docker/,dst=/mnt \
    --user $(id -u):$(id -g) \
    -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix \
    registry.gitlab.com/scribus/scribus-ci-docker/main /bin/bash
```


(for wayland: https://unix.stackexchange.com/questions/330366/how-can-i-run-a-graphical-application-in-a-container-under-wayland
```sh
docker run -e XDG_RUNTIME_DIR=/tmp \
           -e WAYLAND_DISPLAY=$WAYLAND_DISPLAY \
           -v $XDG_RUNTIME_DIR/$WAYLAND_DISPLAY:/tmp/$WAYLAND_DISPLAY  \
           --user=$(id -u):$(id -g) \
           imagename waylandapplication
```
)

## Using MS dev-containers (VS Code)

The devcontainer uses the same dockerfile as for the direct docker way. To use the devcontainer, a `.devcontainer/` directory is created.
This directory contains a `devcontainer.json` file which specifies which dockerfile to use for the devcontainer. VSCode needs the Devcontainer extention installed (
ms-vscode-remote.remote-containers).

NOTE: devcontainers in vscode automatically allow to use graphical apps, no need to passthrough an Display socket

`.devcontainer/devcontainer.json`

```json
{
  "name": "Scribus - CI docker",
  "build": {
    "dockerfile": "dockerfile"
  },
}
```
alternatively when you have prepared already image with correct dependencies (which for example is distributed on docker hub or GitLab)
`.devcontainer/devcontainer.json`
```json
{
  "name": "My Dev Container",
  "image": "registry.gitlab.com/scribus/scribus-ci-docker/main"
}
```

- run from inside `vs code` with command `Dev Container: Reopen in Container`

- add in dockerfile install script for `ninja-build` 
```
apt-get install ninja-build
```
- run inside `vs code` 
```sh
cmake -GNinja -DCMAKE_INSTALL_PREFIX:PATH=/home/ale/bin/scribus-gitlab -DWANT_DEBUG=1 -DWANT_GUI_LANG="en_GB;de;fr;it;en" ..
ninja
ninja install
./home/ale/bin/scribus-gitlab/bin/scribus
```
