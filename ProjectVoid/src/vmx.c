#include "../include/vmx.h"

/**
 * vmx_enable_on_core - Belirli bir CPU çekirdeğinde VMX'i aktifleştirir.
 * @info: on_each_cpu tarafından gönderilen argüman (kullanılmıyor)
 * * Bu fonksiyon her işlemci çekirdeğinde ayrı ayrı çalışacaktır.
 */
void vmx_enable_on_core(void *info)
{
    int cpu_id = smp_processor_id();
    // Buraya ileride CR4 register ayarları ve VMXON komutu gelecek.
    // Şimdilik sadece log atıyoruz.
    printk(KERN_INFO "ProjectVoid: Core %d icin VMX hazirliklari basladi.\n", cpu_id);
}

/**
 * vmx_disable_on_core - VMX'i kapatır.
 */
void vmx_disable_on_core(void *info)
{
    int cpu_id = smp_processor_id();
    // VMXOFF komutu buraya gelecek.
    // printk(KERN_INFO "ProjectVoid: Core %d VMX kapatildi.\n", cpu_id);
}
