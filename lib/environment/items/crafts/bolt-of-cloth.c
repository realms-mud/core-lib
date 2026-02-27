//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bolt of cloth");
    addAlias("cloth");
    addAlias("fabric bolt");
    addAlias("fabric");

    addAdjectives(({ "rolled", "colorful", "fine", "rough-spun",
        "neatly-wound", "linen", "woolen", "dyed", "plain", "soft" }));

    addDescriptionTemplate("a ##Adjective## bolt of cloth on a shelf");

    addItemTemplate(
        "The bolt of cloth is tightly wound around a wooden dowel, its "
        "fabric neatly rolled and secured with a ribbon tie. The weave "
        "is even and the edges are straight, the mark of skilled work "
        "at the loom."
    );

    addSomeLightDescriptionTemplate(
        "a bolt of cloth sits on a shelf, its fabric neatly wound"
    );
    addDimLightDescriptionTemplate(
        "a rolled cylinder of fabric is visible on a shelf"
    );
    addLowLightDescriptionTemplate(
        "a cylindrical shape sits on a shelf"
    );
    addNearDarkDescriptionTemplate(
        "something soft and cylindrical rests on a shelf nearby"
    );
}
