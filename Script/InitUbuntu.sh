# update and upgrade
sudo apt-get update
sudo apt-get upgrade
# remove useless software
sudo apt-get remove libreoffice-common unity-webapps-common thunderbird totem rhythmbox simple-scan gnome-mahjongg aisleriot gnome-mines cheese transmission-common gnome-orca webbrowser-app deja-dup
sudo apt-get autoremove
# install pip
sudo apt-get install python-pip
# install vim
sudo apt-get install vim
# install ipython
sudo apt-get install ipython
# install gef
sudo wget -O ~/.gdbinit-gef.py -q https://github.com/hugsy/gef/raw/master/gef.py
echo source ~/.gdbinit-gef.py >> ~/.gdbinit
# install pwntools
sudo apt-get install python2.7 python-pip python-dev git libssl-dev libffi-dev build-essential
sudo pip install --upgrade pwntools
# install angr
sudo apt-get install python-dev libffi-dev build-essential
sudo pip install angr
# install unity-tweak-tool & flatabulous theme
sudo apt-get install unity-tweak-tool
sudo add-apt-repository ppa:noobslab/themes
sudo apt-get update
sudo apt-get install flatabulous-theme
sudo add-apt-repository ppa:noobslab/icons
sudo apt-get update
sudo apt-get install ultra-flat-icons
# install zsh
sudo apt-get install zsh
sudo apt-get install git
sudo wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | sh
chsh -s /usr/bin/zsh
# install gcc multiple library
sudo apt-get install gcc-multilib
# install qemu
sudo apt-get install qemu
# install tmux
sudo apt-get install tmux
# install and run edb-debugger
sudo apt-get install cmake build-essential libboost-dev libqt5xmlpatterns5-dev qtbase5-dev qt5-default libqt5svg5-dev libgraphviz-dev libcapstone-dev pkg-config
git clone --recursive https://github.com/eteran/edb-debugger.git
cd edb-debugger
mkdir build
cd build
cmake ..
make
./edb
# install pwndbg
git clone https://github.com/pwndbg/pwndbg
cd pwndbg
./setup.sh
# install peda
git clone https://github.com/longld/peda.git ~/peda
echo "source ~/peda/peda.py" >> ~/.gdbinit