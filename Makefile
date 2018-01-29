include 00_devenv/setenv_nxtosek.mak

# ディレクトリ構成の設定
USER_SRC_PATH      = src
USER_INC_PATH      = src/robocontrol
USER_INC_PATH     += src/courseprogram
USER_INC_PATH     += src/common
USER_INC_PATH     += $(NXT_OSEK_ROOT)/ecrobot/nxtway_gs_balancer
USER_INC_PATH     += $(NXT_OSEK_ROOT)/c++/boost
USER_INC_PATH     += $(NXT_OSEK_ROOT)/c++/util
USER_LIB           = nxtway_gs_balancer

TARGET_SOURCES     = $(shell find $(USER_SRC_PATH) -name "*.c")
TARGET_CPP_SOURCES = $(shell find $(USER_SRC_PATH) -name "*.cpp")


# コンパイルオプション
#CFLAGS             = -Wall
#CPPFLAGS           = -Wall


TOPPERS_OSEK_OIL_SOURCE = ./resource.oil

# Don't modify below part
O_PATH ?= build


# validator
ifeq ($(origin NXT_OSEK_ROOT), undefined)
$(error NXT_OSEK_ROOT undefined!)
endif


# BSS領域がオーバーフローする問題を解決するためにROM_ONLYとする
BUILD_MODE = ROM_ONLY

# makefile for C++(.cpp) build
include $(NXT_OSEK_ROOT)/ecrobot/ecrobot++.mak

