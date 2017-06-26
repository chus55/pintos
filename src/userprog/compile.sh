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
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/insult -a insult -- -q
pintos --qemu --disk=build/buildDisk.dsk -- run insult
