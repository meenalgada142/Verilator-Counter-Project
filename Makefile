# Verilator simulation Makefile for COUNTER_PROJECT

VERILATOR = verilator
TOP_MODULE = counter
CPP_FILE = sim/tb_counter.cpp

all:
	$(VERILATOR) -Wall --cc rtl/$(TOP_MODULE).sv \
		--exe $(CPP_FILE) --Mdir obj_dir --trace
	make -C obj_dir -f V$(TOP_MODULE).mk V$(TOP_MODULE)
	./obj_dir/V$(TOP_MODULE)

clean:
	rm -rf obj_dir dump.vcd

run: all
	gtkwave dump.vcd
