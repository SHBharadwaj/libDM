DM is a C++ library being developed for Data mining techniques.

Build instructions:

* git clone https://VenomCoder@bitbucket.org/VenomCoder/dm-a-data-mining-library.git
* mkdir DM-build
* mkdir DM-install
* cd DM-build/
* cmake -G "Ninja" -DCMAKE_INSTALL_PREFIX=/{Path to DM-install dir} /{Path to DM source dir}
* ninja install
* You can find 'dm' executable inside ../DM-install/bin/
