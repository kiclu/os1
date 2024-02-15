DIR_INC 	= include
DIR_SRC 	= src
DIR_BUILD 	= build

KERNEL_IMG = kernel
KERNEL_ASM = kernel.asm

CPU_CORE_COUNT = 4

TOOLPREFIX	= riscv64-unknown-elf-

AS 		= ${TOOLPREFIX}as
CC 		= ${TOOLPREFIX}gcc
LD 		= ${TOOLPREFIX}ld
OBJCOPY	= ${TOOLPREFIX}objcopy
OBJDUMP	= ${TOOLPREFIX}objdump

QEMU 	= qemu-system-riscv64

ASFLAGS = -march=rv64g -mabi=lp64

CFLAGS  = -Wall -Werror
CFLAGS += -I${DIR_INC}
CFLAGS += -O3
CFLAGS += -nostdlib
CFLAGS += -march=rv64g -mabi=lp64 -mcmodel=medany -mno-relax
CFLAGS += -DNHART=${CPU_CORE_COUNT}
CFLAGS += -fno-omit-frame-pointer -ffreestanding -fno-common

LDSCRIPT = kernel.ld
LDFLAGS  = -z max-page-size=4096 --script ${LDSCRIPT}

SOURCES_ASM = $(shell find ${DIR_SRC} -name "*.S" -printf "%P ")
OBJECTS += $(addprefix ${DIR_BUILD}/,${SOURCES_ASM:.S=.o})

SOURCES_C = $(shell find ${DIR_SRC} -name "*.c" -printf "%P ")
OBJECTS += $(addprefix ${DIR_BUILD}/,${SOURCES_C:.c=.o})

all: ${KERNEL_IMG}

${KERNEL_IMG}: ${OBJECTS} ${LDSCRIPT} | ${DIR_BUILD}
	${LD} ${LDFLAGS} -o ${@} ${OBJECTS}
	${OBJDUMP} --source ${KERNEL_IMG} > ${KERNEL_ASM}

${DIR_BUILD}/%.o: ${DIR_SRC}/%.S Makefile | ${DIR_BUILD}
	@mkdir -p $(dir ${@})
	${AS} -c ${ASFLAGS} -o ${@} ${<}

${DIR_BUILD}/%.o: ${DIR_SRC}/%.c Makefile | ${DIR_BUILD}
	@mkdir -p $(dir ${@})
	${CC} -c ${CFLAGS} -o ${@} ${<}

${DIR_BUILD}:
	mkdir ${@}

clean:
	rm -rf ${DIR_BUILD}
	rm -f ${KERNEL_IMG}
	rm -f ${KERNEL_ASM}

QEMUOPTS = -machine virt -bios none -kernel ${KERNEL_IMG} -m 128M -smp ${CPU_CORE_COUNT} -nographic

qemu: ${KERNEL_IMG}
	@${QEMU} ${QEMUOPTS}
