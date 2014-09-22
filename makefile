default:
	mkdir -p build
	sudo apt-get install fcitx-libs-qt
	sudo apt-get install fcitx-libs-qt5
	sudo apt-get install qt5-qmake
	sudo apt-get install qtbase5-dev
	sudo apt-get install libqt5x11extras5-dev
	cd build/ && /usr/lib/x86_64-linux-gnu/qt5/bin/qmake ../Mutate/Mutate.pro
	echo -e "run configure Ok!"
	cd build/ && make

install: ./build/mutate
	cd ./build && sudo make install
	mkdir -p ${HOME}/.config/Mutate
	cp -r ./config/* ${HOME}/.config/Mutate
	cat ./config/config.ini | sed "s#{home}#`echo ${HOME}`#g" > ${HOME}/.config/Mutate/config.ini
	sudo cp ./info/Mutate.desktop /usr/share/applications/Mutate.desktop
	sudo cp ./info/mutate.png /usr/share/icons/mutate.png

	
.PHONY:clean, uninstall

clean:
	cd ./build && sudo make clean

uninstall: 
	sudo rm -rf /usr/local/bin/mutate
	sudo rm /usr/share/icons/mutate.png
	sudo rm /usr/share/applications/Mutate.desktop
	sudo rm -rf ${HOME}/.config/Mutate
