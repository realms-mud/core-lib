//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("anvil");
    addAlias("iron anvil");
    addAlias("smith's anvil");
    addAlias("blacksmith anvil");

    addAdjectives(({ "heavy", "iron", "scarred", "massive", "worn",
        "pitted", "dark", "solid", "ancient", "well-used" }));

    addDescriptionTemplate("a ##Adjective## anvil mounted on a thick oak stump");

    addItemTemplate(
        "The anvil is a massive block of iron, its face scarred and pitted "
        "from countless hammer blows. It sits firmly on a thick oak stump "
        "that has been sunk into the ground for stability. The horn curves "
        "upward at one end, and the hardy hole and pritchel hole are dark "
        "with soot and scale."
    );

    addSomeLightDescriptionTemplate(
        "a heavy iron anvil sits on its stump, its surface scarred by work"
    );
    addDimLightDescriptionTemplate(
        "a dark mass of iron sits on a wooden stump — an anvil"
    );
    addLowLightDescriptionTemplate(
        "a heavy dark shape on a broad stump suggests an anvil"
    );
    addNearDarkDescriptionTemplate(
        "a massive, immovable shape squats in the darkness"
    );
}
