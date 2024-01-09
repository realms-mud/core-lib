//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruined marble floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("marble");
    addAlias("marble floor");

    addAdjectives(({ "with blue-gray swirls",
        "that has been cracked and weathered with age", 
        "with fine golden threads coursing through it", 
        "that has blue-black tendrils winding through a field of ivory white",
        "with a large divot torn out of it",
        "with rose colored blotches melded on a background of white",
        "that has been neglected by long years without maintenance",
        "that has been shattered into several large chunks" }));

    addDescriptionTemplate("the floor is fashioned out of marble "
        "##Adjective##. There are many crystals within the rock, all "
        "reflecting glimmering light from their surfaces");
    addSomeLightDescriptionTemplate("the floor is fashioned out of marble "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor is fashioned out of an unknown "
        "material. Thin etchings along its edge give off a faint light");
    addLowLightDescriptionTemplate("the floor is fashioned out of stone. "
        "Thin etchings along its edge give off a faint light");
    addDimLightDescriptionTemplate("the floor is fashioned out of marble. "
        "It looks quite old and has been neglected. Thin etchings along its edge give off a faint light");
    addSourceOfLight(3);

    addItemTemplate("The floor appears to be fashioned out of large "
        "tiles. All along the edge of each piece, it has been scored with intricate etchings, each "
        "giving off a very faint glow");
}
