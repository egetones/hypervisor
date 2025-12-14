#ifndef VMX_H
#define VMX_H

#include "globals.h"

// VMXON işlemini her çekirdek için başlatır
void vmx_enable_on_core(void *info);

// VMXOFF işlemini her çekirdek için yapar
void vmx_disable_on_core(void *info);

#endif // VMX_H
