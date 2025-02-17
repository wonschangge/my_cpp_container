CPP=clang
CPPFLAGS=-std=c11 -lpthread

# 定义要编译的源文件列表
SOURCES=$(wildcard *.c)

# 根据源文件列表生成目标文件列表
TARGETS=$(SOURCES:.c=)

all: $(TARGETS)

# 通用规则，将每个 .cpp 文件编译为对应的可执行文件
%: %.c
	$(CPP) $(CPPFLAGS) $< -o $@