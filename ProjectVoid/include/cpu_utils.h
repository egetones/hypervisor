#ifndef CPU_UTILS_H
#define CPU_UTILS_H

#include "globals.h"

// Intel Manual Vol 3'e göre: CPUID EAX=1, ECX Bit 5 = VMX
#define CPUID_FEAT_ECX_VMX (1 << 5)

/**
 * native_cpuid - Saf Assembly ile CPUID çağırma
 * @eax: Yaprak numarası (Giriş), Sonuç (Çıkış)
 * @ebx: Sonuç (Çıkış)
 * @ecx: Sonuç (Çıkış)
 * @edx: Sonuç (Çıkış)
 */
static inline void native_cpuid(unsigned int *eax, unsigned int *ebx,
                                unsigned int *ecx, unsigned int *edx)
{
    asm volatile("cpuid"
                 : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
                 : "0" (*eax));
}

/**
 * check_vmx_support - İşlemcinin sanallaştırma desteğini kontrol eder
 * Return: Destekleniyorsa true, yoksa false
 */
static inline bool check_vmx_support(void)
{
    unsigned int eax = 1, ebx, ecx, edx;
    
    native_cpuid(&eax, &ebx, &ecx, &edx);
    
    if (!(ecx & CPUID_FEAT_ECX_VMX)) {
        return false;
    }
    return true;
}

#endif // CPU_UTILS_H
