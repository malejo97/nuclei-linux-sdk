# Shifted to fit freeloader + OpenSBI + Bao + Linux at beggining of DDR
DDR_BASE ?= 0x82000000
# Loading everything to DRAM
FLASH_BASE ?= 0x80000000
FLASH_SIZE ?= 32M
CACHE_CTRL ?= 0x100C1
# prefetch control register settings
## spfl1dctrl1
SPFL1DCTRL1 ?= 0x1F
SPFL1DCTRL2 ?=
MERGL1DCTRL ?= 0x013503FF
ENABLE_SMP ?= 1
ENABLE_L2 ?= 1
AMPFW_START_OFFSET ?= 0x7E000000
AMPFW_SIZE ?= 0x400000
AMP_START_CORE ?= 8
