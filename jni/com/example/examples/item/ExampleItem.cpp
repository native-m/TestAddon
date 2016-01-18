#include "ExampleItem.h"

ExampleItem::ExampleItem(const std::string& name, short itemId) : Item(name, itemId - 0x100) //not really sure why we have to include '- 0x100'
{
    Item::mItems[itemId] = this; //could do another way but this is the best way
    creativeCategory = 1; //adds our item into the bottom creative inv
    setIcon("apple", 0); //sets an apple as our icon

    /*
    You can get the Item's texture names and data
    from http://zhuoweizhang.net/mcpetexturenames/
    */
}
