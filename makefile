# makefileの共通定義をインクルード
include ./inc.mak

#CFLAGS	+= -DKOZOS#		条件コンパイルのデファインでしょう
#CFLAGS	+= -Wno-attributes
#CFLAGS	+= -D_20MHZ_CPU_#	H8/3069F LANボードで使用

##########	生成する実行形式のファイル名
TARGET	= alg.exe
#TARGET_PATH	= kozos

##########	他のディレクトリ
#KZ_OS_COMMON_DIR	= ../common
#KZ_OS_DAEMON_DIR	= ../daemon

##########	コンパイルするソースコード郡
SRCS	= main.cpp
SRCS	+= ./Sorter/Sorter.cpp

CFLAGS	+= -I./Sorter

#OBJS = $(addsuffix .o, $(basename $(shell cygpath -m $(realpath $(SRCS)))))
OBJS = $(addsuffix .o, $(basename $(shell cygpath -m $(realpath $(SRCS)))))

########## ターゲット部
# makeコマンドでターゲットを指定しなかった場合
# 一番上に記述されているターゲットが実行される
# ":"のあとには、ターゲットを指定するが、
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

# モトローラSレコード・フォーマットへの変換ルール
#.PHONY:	$(TARGET).mot
#$(TARGET).mot	: $(TARGET)
#	$(OBJCOPY) -O srec $(TARGET) $(TARGET)_tmp.mot
#	tr -s '\n' '\r' < $(TARGET)_tmp.mot > $(TARGET).mot

# イメージファイル作成ルール
#.PHONY:	image
#image			: $(TARGET).mot
#	cp $(TARGET).mot ../../bin

# フォルダの掃除
.PHONY:	clean
clean			:
	rm -f $(OBJS) $(TARGET) $(TARGET).elf *.o *.elf *.exe


