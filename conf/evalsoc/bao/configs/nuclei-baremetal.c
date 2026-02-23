/**
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) Bao Project and Contributors. All rights reserved.
 */

#include <config.h>

VM_IMAGE(baremetal_image, "../work/evalsoc/baremetal/baremetal.bin")

struct config config = {

    .vmlist_size = 1,

    .vmlist = (struct vm_config[]){
        {
            .image = VM_IMAGE_BUILTIN(baremetal_image, 0x80200000),

            .entry = 0x80200000,

            .platform = {
                .cpu_num = 1,
                
                .region_num = 1,
                .regions =  (struct vm_mem_region[]) {
                    {
                        .base = 0x80200000,
                        .size = 0x4000000
                    }
                },

                .dev_num = 1,
                .devs =  (struct vm_dev_region[]) {
                    {
                        // UART0
                        .pa = 0x10013000,   
                        .va = 0x10013000,  
                        .size = 0x00001000,
                        .interrupt_num = 1,
                        .interrupts = (irqid_t[]) {33},
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