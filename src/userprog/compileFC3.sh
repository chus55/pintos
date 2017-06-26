make clean
make
cd ..
cd threads/
make clean
make
cd ..
cd examples/
make clean
make
cd ..
cd utils/
make clean
make
cd ..
cd userprog/
pintos-mkdisk build/buildDisk.dsk --filesys-size=10
pintos --qemu --disk=build/buildDisk.dsk -- -f -q
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/philo_can -a philo_can -- -q
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/philo -a philo -- -q
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/writer -a writer -- -q
pintos --qemu --disk=build/buildDisk.dsk -- run philo_can