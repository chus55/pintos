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
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/bounded_buffer -a bounded_buffer -- -q
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/consumer -a consumer -- -q
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/producer -a producer -- -q
pintos --qemu --disk=build/buildDisk.dsk -- run bounded_buffer