//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("butcher block");
    addAlias("chopping block");
    addAlias("cutting block");

    addAdjectives(({ "heavy", "scarred", "blood-stained", "thick",
        "worn", "massive", "old", "oak", "well-used", "notched" }));

    addDescriptionTemplate("a ##Adjective## butcher block scored with cut marks");

    addItemTemplate(
        "The butcher block is a massive slab of end-grain oak, its "
        "surface deeply scored by years of cleaver strikes. Dark stains "
        "have seeped into the wood despite regular scrubbing, and the "
        "edges are rounded from constant use. It stands on four stout "
        "legs, solid as a boulder."
    );

    addSomeLightDescriptionTemplate(
        "a massive butcher block dominates the work area, its surface "
        "deeply scarred"
    );
    addDimLightDescriptionTemplate(
        "a heavy block of wood on thick legs is visible — a butcher block"
    );
    addLowLightDescriptionTemplate(
        "a massive low table of thick wood stands in the work area"
    );
    addNearDarkDescriptionTemplate(
        "a large, immovable surface dominates the work area"
    );
}
