//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("stone");

    addAdjectives(({ "with rough, uneven surfaces",
        "that has been worn smooth by countless footfalls",
        "with small cracks running through several blocks",
        "consisting of large granite blocks fit tightly together",
        "with dark water stains spread across it",
        "fashioned from gray weathered stone",
        "that has been chipped and cracked over the years",
        "with mortar crumbling between the stone blocks" }));

    addDescriptionTemplate("the floor is constructed of stone "
        "##Adjective##. The stones are cold and sturdy, a testament "
        "to the builders' craft");
    addSomeLightDescriptionTemplate("the floor is constructed of stone "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor is constructed of some hard "
        "material. Faint outlines of blocks can be discerned in the darkness");
    addLowLightDescriptionTemplate("the floor is made of fitted stone blocks. "
        "The joints between them appear as dark lines in the dim light");
    addDimLightDescriptionTemplate("the floor is made of stone blocks. "
        "It has endured through the years, though showing signs of wear");
    addSourceOfLight(1);

    addItemTemplate("The floor is composed of carefully cut stone "
        "blocks fitted together with precision. Despite its age, it remains "
        "solid underfoot, though some sections have begun to sink slightly");
}
