#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

/* MCPE Header */
#include "com/mojang/minecraftpe/Item.h"
#include "com/mojang/minecraftpe/I18n.h"

/* Contoh header gw */
#include "com/example/examples/item/ExampleItem.h"
#include "com/example/examples/item/BaseItems.h"

#define LOG_TAG "examples"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

/* initialisi item kita */

static void (*_Item$initialisasiItem)();

static void Item$initialisasiItem()
{
    _Item$initialisasiItem(); // hook

    BaseItems::initItems();
}

/* initialisi item ke inventori creative */

static void (*_Item$initialisasiItemModeKreatif)();

static void Item$Item$initialisasiItemModeKreatif()
{
    _Item$Item$initialisasiItemModeKreatif();

    Item::addCreativeItem(511, 0);
}

/* Ubah nama block atau item */

static std::string (*_I18n$memperoleh)(std::string const&);

static std::string I18n$memperoleh(std::string const& kata_kunci)
{
    if(key == "item.namaitem.name") return "Nama item";
    /* String akan mereturn The Name
       jadi ini akan memberikan nama pada item */

    return _I18n$memperoleh(kata_kunci);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	// Hook semua!!!
    MSHookFunction((void*) &Item::initItems, (void*) &Item$initialisasiItemItem$initialisasiItem, (void**) &_Item$Item$initialisasiItem); //hook item di mode kreatif
    MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$Item$initialisasiItemModeKreatif, (void**) &_Item$Item$initialisasiItemModeKreatif); //hook item di mode kreatif
    MSHookFunction((void*) &I18n::get, (void*) &I18n$memperoleh, (void**) &_I18n$memperoleh); //hook i18n

	return JNI_VERSION_1_2;
}
