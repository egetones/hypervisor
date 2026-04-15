#include "../include/globals.h"
#include "../include/cpu_utils.h"
#include "../include/vmx.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("User & Gemini");
MODULE_DESCRIPTION("Project Void: Level-2 Hypervisor Entry");
MODULE_VERSION("0.1");

static int __init void_init(void)
{
    printk(KERN_INFO "ProjectVoid: [INIT] Hypervisor yukleniyor...\n");

    // 1. Donanım Kontrolü
    if (!check_vmx_support()) {
        printk(KERN_ERR "ProjectVoid: [HATA] VMX destegi yok veya BIOS'tan kapali!\n");
        return -ENODEV;
    }
    
    printk(KERN_INFO "ProjectVoid: [OK] Donanim VMX destekliyor.\n");

    // 2. VMX'i tüm çekirdeklerde aktifleştirmeyi dene
    // on_each_cpu fonksiyonu, vmx_enable_on_core fonksiyonunu tüm çekirdeklerde çalıştırır.
    // Şimdilik güvenli olması için sadece log atıyoruz, VMXON komutunu bir sonraki fazda ekleyeceğiz.
    on_each_cpu(vmx_enable_on_core, NULL, 1);

    return 0;
}

static void __exit void_exit(void)
{
    // Modül kaldırılırken VMX'i kapat
    on_each_cpu(vmx_disable_on_core, NULL, 1);
    
    printk(KERN_INFO "ProjectVoid: [EXIT] Hypervisor bellekten silindi.\n");
}

module_init(void_init);
module_exit(void_exit);
