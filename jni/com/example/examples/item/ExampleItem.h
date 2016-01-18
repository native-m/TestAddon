#pragma once
#include <string>

#include "../../../mojang/minecraftpe/Item.h"
/* If you're wondering the ../ basically means go back a directory
so I'm saying here to go back to examples then go to example then
go to com and then go to mojang and get the Item.h header */

class ExampleItem : public Item
{
public:

        ExampleItem(const std::string&, short); //our constructor for the item
};
