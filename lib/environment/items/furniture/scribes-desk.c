//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("scribe's desk");
    addAlias("writing desk");
    addAlias("wooden scribe's desk");
    addAlias("desk");

    addAdjectives(({ "wooden", "small", "carved", "plain", "old", "sturdy",
        "polished", "functional", "rectangular", "worn" }));

    addDescriptionTemplate("a ##Adjective## scribe's desk with slots for scrolls");

    addItemTemplate(
        "This scribe's desk is crafted from wood, with a sloped surface for "
        "writing and several slots for storing scrolls and writing implements. "
        "A small drawer is built into the side."
    );

    addSomeLightDescriptionTemplate(
        "a wooden scribe's desk stands near the wall, its surface sloped and clear"
    );
    addDimLightDescriptionTemplate(
        "a scribe's desk is visible in the gloom, its outline small and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a scribe's desk can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a scribe's desk is present, but details are lost "
        "in the darkness"
    );
}
