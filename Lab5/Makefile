obj-m += hello1.o
obj-m += hello2.o

ccflags-y += -I$(src)/inc

KDIR ?= $(HOME)/repos/linux-stable
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
