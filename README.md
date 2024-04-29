### Requirements
	source ~/zephyrproject/zephyr/zephyr-env.sh
	source /home/adrain/devel/evb/milkv-duo/zephyrproject/.venv/bin/activate

### Steps

- Clone repo
   	```
   	git clone git@github.com:adrain-yu/exp-zephyr.git
   	```

- Build
	```
	mkdir build
	cd build
	cmake -GNinja -DBOARD=qemu_riscv64 ../
	ninjia 
	```
- Run
	```
	ninjia run
	```

- Clean
	```
	ninja clean 	#clean build files exclude config file
	ninja pristine  #clean all build files
	```
- Debug
	```
	one terminal:
		ninja debugserver
	another terminal:
		1. /opt/zephyr-sdk-0.16.3/riscv64-zephyr-elf/bin/riscv64-zephyr-elf-gdb ~/devel/sourcecode/exp-zephyr/build/zephyr/zephyr.elf
		2. target remote localhost:1234
			tui enable
			tui reg csr/all
			si or ni
	```
### Ref
	https://lgl88911.github.io/2018/03/24/Zephyr%E5%88%9B%E5%BB%BA%E5%BA%94%E7%94%A8-%E6%A8%A1%E6%8B%9F%E8%BF%90%E8%A1%8C/



