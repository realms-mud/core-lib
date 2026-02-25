//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("grocery interior");

    addItemTemplate(
        "The grocery shop is lined with sturdy wooden shelves, each crowded "
        "with an assortment of goods. Baskets of fresh produce - apples, onions, "
        "and root vegetables - sit near the entrance. Sacks of grain and flour "
        "are stacked neatly along one wall, while jars of preserves, dried "
        "herbs, and wheels of cheese fill the air with a mingled aroma. "
        "A counter at the back displays loaves of bread and a small set of "
        "scales for weighing purchases. The floor is swept clean, and the "
        "shop is lit by sunlight streaming through the front window."
    );

    addNearDarkDescriptionTemplate(
        "the outlines of shelves and baskets are barely visible in the gloom, "
        "with only the faintest glimmer of light reflecting off glass jars"
    );
    addLowLightDescriptionTemplate(
        "the grocery shelves are dimly lit, their contents little more than "
        "shapes and shadows"
    );
    addDimLightDescriptionTemplate(
        "the grocery is softly illuminated, revealing baskets of produce and "
        "rows of jars along the shelves"
    );
    addSomeLightDescriptionTemplate(
        "the grocery is bright enough to make out the colors of apples, "
        "onions, and loaves of bread on the counter"
    );
    addDescriptionTemplate(
        "sunlight fills the grocery, making the produce and goods on the "
        "shelves appear fresh and inviting"
    );
}
