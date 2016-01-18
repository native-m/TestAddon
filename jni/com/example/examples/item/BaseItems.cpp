#include "BaseItems.h"
#include "ExampleItem.h"

Item* BaseItems::example;

void BaseItems::initItems()
{
    example = new ExampleItem("examplename", 511);
    /*
    The first parameter sets the item name as
    item.The Name.name, this is because mojang
    made the default name thingy as item."custom name".name.
    The second parameter sets the item id as 511.
    */
}
