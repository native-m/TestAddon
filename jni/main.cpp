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

static void (*_Item$initItems)();

static void Item$initItems()
{
    _Item$initItems(); // hook

    BaseItems::initItems();
}

/* initialisi item ke inventori creative */

static void (*_Item$initCreativeItems)();

static void Item$initCreativeItems()
{
    _Item$initCreativeItems();

    Item::addCreativeItem(511, 0);
}

/* Ubah nama block atau item */

static std::string (*_I18n$get)(std::string const&);

static std::string I18n$get(std::string const& key)
{
    if(key == "item.examplename.name") return "The Name";
    /* String akan mereturn The Name
       jadi ini akan memberikan nama pada item */

    return _I18n$get(key);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	// Hook theme all
    MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems); //hook
    MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems); //hook
    MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get); //hook i18n

	return JNI_VERSION_1_2;
}
