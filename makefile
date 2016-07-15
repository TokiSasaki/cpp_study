#####	include file of makefile
#####	definition of the common part, etc.
#include ./inc.mak

#PREFIX = /usr/local
#BINDIR	= $(PREFIX)/bin

###########	gcc, binutils prefix
ARCH	= x86_64-w64-mingw32
ADDNAME	= $(ARCH)-

#HEADPATH = $(shell cygpath -m $(realpath ..))

###########	definition of the using tools
AR		= $(ADDNAME)ar
AS		= $(ADDNAME)as
CC		= $(ADDNAME)g++
LD		= $(ADDNAME)ld
NM		= $(ADDNAME)nm
OBJCOPY	= $(ADDNAME)objcopy
OBJDUMP	= $(ADDNAME)objdump
RANLIB	= $(ADDNAME)ranlib
STRIP	= $(ADDNAME)strip

##########	compile option(Flags)
CFLAGS	= -Wall#			display all warnings
#CFLAGS	+= -mh#				output for the H8/300 (binary)code
#CFLAGS	+= -nostdinc#		not include system header(such as stdio.h?)
#CFLAGS	+= -nostdlib#		not use system library(such as stdlib.h?)
#CFLAGS	+= -fno-builtin#	not use the builtin function of compiler
CFLAGS	+= -I.#				specify the search destination of the header files
CFLAGS	+= -I./Algorythm#	
#CFLAGS	+= -I$(HEADPATH)/include
#CFLAGS	+= -I$(HEADPATH)/daemon
#CFLAGS	+= -Os#				optimize to minimize size of the execution file
#CFLAGS	+= -D_H8_3069F_ARCH_
#CFLAGS += -g#				use debagger
#CFLAGS += -mint32#			can't multiplication and division if you specify this(32bit)
CFLAGS	+= -std=c++11#		to use the random fuction of the c++ library

# be able to write following, but can't write the line comment
# CFLAGS	= -Wall \
# 	-mh \
# 	-nostdinc \
# 	-nostdlib \
# 	-fno-builtin \
# 	-I. \
# 	-Os \
## 	-g \
## 	-mint32 \
## 	-DKOZOS

##########	Link Flags
LFLAGS	= -static#			link all code with the static link
#LFLAGS	+= -T linker.ld#	specify the linker script
#LFLAGS	+= -L.#				specify the search destination of the header files
#LFLAGS	+= -L../common


##### 以下の様な方法でコンパイルするファイルを指定することも出来る
#ヘッダファイルは、例えばLinuxのシステムのヘッダファイル等と名前が
#かぶる場合に、下記のヘッダファイル指定を行い、ファイル名解決をする。
#HDRS = initProc.h \
#       ../inc/rabbit.h \
#       ../inc/shmem.h \
#       ../inc/msgFunc.h \
#       ../inc/devFunc.h
#
#SRCS = initProc.c \
#       ../common/shmem.c \
#       ../common/msgFunc.c \
#       ../common/devFunc.c
#
#OBJS = $(addsuffix .o,$(basename $(SRCS)))

##########	生成する実行形式のファイル名
TARGET	= alg.exe

##########	コンパイルするソースコード郡
SRCS	= main.cpp
SRCS	+= ./Algorythm/Algorythm.cpp
SRCS	+= ./Algorythm/Sort.cpp
SRCS	+= ./Algorythm/Search.cpp

#OBJS = $(addsuffix .o, $(basename $(shell cygpath -m $(realpath $(SRCS)))))
OBJS = $(addsuffix .o, $(basename $(shell cygpath -m $(realpath $(SRCS)))))

########## ターゲット部
# makeコマンドでターゲットを指定しなかった場合
# 一番上に記述されているターゲットが実行される
# ":"のあとには、ターゲットを指定するが、ターゲットには
# タスクターゲットとファイルターゲットがある
# all:は、タスクターゲットを指定している。
# $(TARGET)はファイルターゲットを指定している。
# ファイルターゲットを指定した場合、ファイルのタイムスタンプを
# 確認してから実行する。
# よって、ファイルに変更がなかった場合、そのターゲットは実行しない。
.PHONY:	all
all				: $(TARGET)

# 実行形式ファイルの生成ルール
.PHONY:	$(TARGET)
$(TARGET)		: $(OBJS)
	$(CC) $(LDFLAGS) $(notdir $(OBJS)) -o $(TARGET) $(CFLAGS) $(LFLAGS)

# *.cファイルのコンパイルルール
.c.o			: $<
	$(CC) -c $(CFLAGS) $<
# *.cppファイルのコンパイルルール
.cpp.o			: $<
	$(CC) -c $(CFLAGS) $<

# *.s(アセンブラファイル)のアセンブルルール
.s.o			: $<
	$(CC) -c $(CFLAGS) $<
	
# *.S(アセンブラファイル:大文字の.S)のアセンブルルール
.S.o			: $<
	$(CC) -c $(CFLAGS) $<

# フォルダの掃除
.PHONY:	clean
clean			:
	rm -f $(OBJS) $(TARGET) $(TARGET).elf *.o *.elf *.exe


