/**
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) Bao Project and Contributors. All rights reserved.
 */

#include <config.h>

VM_IMAGE(linux_image, "../work/evalsoc/lloader/linux-rv64-nuclei.bin")

struct config config = {

    .vmlist_size = 1,

    .vmlist = (struct vm_config[]){
        {
            .image = VM_IMAGE_BUILTIN(linux_image, 0x80200000),

            .entry = 0x80200000,

            .platform = {
                .cpu_num = 1,
                
                .region_num = 1,
                .regions =  (struct vm_mem_region[]) {
                    {
                        .base = 0x80200000,
                        .size = 0x20000000
                    }
                },

                .dev_num = 5,
                .devs =  (struct vm_dev_region[]) {
                    {
                        // UART0
                        .pa = 0x10013000,   
                        .va = 0x10013000,  
                        .size = 0x00001000,
                        .interrupt_num = 1,
                        .interrupts = (irqid_t[]) {33},
                        .id = 0
                    },
                    {
                        // UART1
                        .pa = 0x10023000,   
                        .va = 0x10023000,  
                        .size = 0x00001000,
                        .interrupt_num = 1,
                        .interrupts = (irqid_t[]) {34},
                        .id = 0
                    },
                    {
                        // SPI0
                        .pa = 0x10014000,   
                        .va = 0x10014000,  
                        .size = 0x00001000,
                        .interrupt_num = 1,
                        .interrupts = (irqid_t[]) {35},
                        .id = 0
                    },
                    {
                        // SPI2
                        .pa = 0x10034000,   
                        .va = 0x10034000,  
                        .size = 0x00001000,
                        .interrupt_num = 1,
                        .interrupts = (irqid_t[]) {37},
                        .id = 0
                    },
                    {
                        // XEC0
                        .pa = 0x10002000,   
                        .va = 0x10002000,  
                        .size = 0x00001000,
                        .interrupt_num = 1,
                        .interrupts = (irqid_t[]) {8},
                        .id = 0
                    }
                },

                .arch = {
                   .irqc.plic.base = 0x1c000000,
                },

                .remio_dev_num = 0,
                .remio_devs = NULL
            }
        }
    }
};