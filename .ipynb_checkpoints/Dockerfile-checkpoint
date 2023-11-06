# Download base image
# You can use Ubuntu instead if you wish
# FROM ubuntu:latest
FROM debian:stable

# LABEL about the custom image
LABEL Name=champsim_ramulator Version=1.0.0
LABEL description="This is a image for the xxx"

# Install your favorite packages
# -qq: No output except for errors
RUN apt-get update 
RUN apt-get --yes -qq install \
  build-essential \
  sudo \
  gdb \
  libssl-dev
# wget 
RUN rm -rf /var/lib/apt/lists/*
RUN apt clean

# User/group names/ids which will be overwritten: https://stackoverflow.com/a/44683248
ARG UNAME
ARG GNAME
ARG UID
ARG GID
RUN groupadd -g $GID -o $GNAME
# Add a user with empty password in sudo: https://unix.stackexchange.com/a/472968
RUN useradd -m -u $UID -g $GID -o -s /bin/bash $UNAME && echo "$UNAME:U6aMy0wojraho" | chpasswd -e && usermod -aG sudo $UNAME

# Set the user (for subsequent commands)
USER $UNAME

# Set the working directory (for subsequent commands)
WORKDIR /home/$UNAME

# These commands copy your files into the specified directory in the image
# COPY . ./ChampSim_Ramulator

# Define the ENV variable
# ENV workspaceFolder ./Codes

# Run when the container launches
CMD /bin/bash

# Build your docker image using the following command.
# docker build --build-arg UNAME=$(id -un) --build-arg GNAME=$(id -gn) --build-arg UID=$(id -u) --build-arg GID=$(id -g) -t yousei:Champsim_Ramulator -f Dockerfile .

# You can run your container using the following command.
# docker run -it --rm YOUR_USERNAME:TAG
# docker run -it --rm -v $(pwd):/home/$(id -un) yousei:Champsim_Ramulator
# docker run -it --restart always -v $(pwd):/home/$(id -un) yousei:Champsim_Ramulator
