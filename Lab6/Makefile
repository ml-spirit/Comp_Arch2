
obj-m += hello.o

KDIR ?= $(HOME)/repos/linux-stable
PWD := $(shell pwd)

ccflags-y += -g

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
