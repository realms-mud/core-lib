//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("loom");
    addAlias("weaving loom");
    addAlias("floor loom");

    addAdjectives(({ "wooden", "large", "upright", "complex", "threaded",
        "well-used", "sturdy", "clacking", "old", "intricate" }));

    addDescriptionTemplate("a ##Adjective## loom strung with thread");

    addItemTemplate(
        "The loom is a large wooden frame strung with hundreds of threads "
        "in tight parallel rows. Heddles and treadles allow the weaver to "
        "separate the warp threads so the shuttle can pass through. A "
        "half-finished length of cloth hangs from the beam, its pattern "
        "slowly emerging row by row."
    );

    addSomeLightDescriptionTemplate(
        "a large loom dominates the space, its threads taut and a cloth "
        "half-woven"
    );
    addDimLightDescriptionTemplate(
        "a loom is visible, the faint gleam of its threads catching the light"
    );
    addLowLightDescriptionTemplate(
        "a large upright frame strung with something fine fills the space"
    );
    addNearDarkDescriptionTemplate(
        "a large wooden frame occupies much of the room"
    );
}
