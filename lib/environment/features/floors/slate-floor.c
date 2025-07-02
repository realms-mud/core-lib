//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("slate floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("slate");

    addAdjectives(({ "of dark gray slabs with natural cleavage lines",
        "that gleams with a subtle metallic sheen",
        "with blue-black stones fitted in irregular patterns",
        "showing the natural layered structure of the stone",
        "that feels smooth and cool beneath your feet",
        "with some slabs cracked along their natural grain",
        "that reflects light from its polished surface",
        "displaying subtle color variations from deep gray to black" }));

    addDescriptionTemplate("the floor is laid with slate "
        "##Adjective##. The dark stone creates an elegant "
        "and sophisticated surface");
    addSomeLightDescriptionTemplate("the floor is laid with slate "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor appears to be made of smooth, "
        "dark stone. It feels cool and slick underfoot");
    addLowLightDescriptionTemplate("the floor consists of dark stone slabs. "
        "The smooth surface has a subtle reflective quality");
    addDimLightDescriptionTemplate("the floor is paved with dark slate. "
        "The stone has a natural elegance despite its simplicity");

    addItemTemplate("The floor is constructed of slate slabs, each piece "
        "split along the stone's natural cleavage lines to create smooth, "
        "flat surfaces. The dark gray to black stones fit together with "
        "minimal gaps, their natural layered structure visible in the edges "
        "while the polished faces reflect light with understated elegance.");
}
