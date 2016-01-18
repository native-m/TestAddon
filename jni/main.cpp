#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

/* MCPE Base Headers */
#include "com/mojang/minecraftpe/Item.h"
#include "com/mojang/minecraftpe/I18n.h"

/* My Example Headers */
#include "com/example/examples/item/ExampleItem.h"
#include "com/example/examples/item/BaseItems.h"

#define LOG_TAG "examples"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

/* Inits our item */

static void (*_Item$initItems)();

static void Item$initItems()
{
    _Item$initItems();

    BaseItems::initItems();
}

/* Inits our item to the creative inv */

static void (*_Item$initCreativeItems)();

static void Item$initCreativeItems()
{
    _Item$initCreativeItems();

    Item::addCreativeItem(511, 0);
}

/* Changes the name of our Items/Blocks */

static std::string (*_I18n$get)(std::string const&);

static std::string I18n$get(std::string const& key)
{
    if(key == "item.examplename.name") return "The Name";
    /* Basically sees if there is a name called item.examplename.name then returns the string The Name
       So it makes the name of the item The Name :P */

    return _I18n$get(key);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

    MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems); //hooking
    MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems); //more hooking
    MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get); //even MOAR hooking

	return JNI_VERSION_1_2;
}
