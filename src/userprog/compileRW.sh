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
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/reader_writer -a reader_writer -- -q
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/reader -a reader -- -q
pintos --qemu --disk=build/buildDisk.dsk -p ../examples/writer -a writer -- -q
pintos --qemu --disk=build/buildDisk.dsk -- run reader_writer