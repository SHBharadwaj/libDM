DM is a C++ library being developed for Data mining techniques.

Build instructions:

* clone or copy DM source 
* mkdir DM-build
* mkdir DM-install
* cd DM-build/
* cmake -G "Ninja" -DCMAKE_INSTALL_PREFIX=/{Path to DM-install dir} /{Path to DM source dir}
* ninja install
* You can find 'dm' executable inside ../DM-install/bin/
