//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ore pile");
    addAlias("raw ore");
    addAlias("ore heap");
    addAlias("mine tailings");

    addAdjectives(({ "rough", "dark", "glittering", "heavy", "unsorted",
        "dusty", "heaped", "raw", "crushed", "metallic" }));

    addDescriptionTemplate("a ##Adjective## pile of raw ore awaiting processing");

    addItemTemplate(
        "The ore pile is a rough heap of rock freshly hauled from the mine, "
        "dark stone shot through with veins of metal that glint when the "
        "light catches them. Dust and grit cover everything nearby, and "
        "the pile shifts and settles with occasional small rockslides. "
        "Chunks range from fist-sized to boulders."
    );

    addSomeLightDescriptionTemplate(
        "a pile of raw ore glints with metallic veins in the light"
    );
    addDimLightDescriptionTemplate(
        "a heap of dark rock is piled nearby, faint glints of metal visible"
    );
    addLowLightDescriptionTemplate(
        "a dark heap of rock or ore is piled on the ground"
    );
    addNearDarkDescriptionTemplate(
        "the gritty crunch of loose rock underfoot suggests ore nearby"
    );
}
