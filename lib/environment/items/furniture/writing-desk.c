//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("writing desk");
    addAlias("desk");
    addAlias("wooden writing desk");
    addAlias("writing table");

    addAdjectives(({ "wooden", "small", "carved", "plain", "old", "sturdy",
        "polished", "functional", "rectangular", "worn" }));

    addDescriptionTemplate("a ##Adjective## writing desk with a sloped surface");

    addItemTemplate(
        "This writing desk is crafted from wood, with a sloped surface for "
        "writing letters or keeping records. A small drawer or compartment is "
        "built into the side for storing ink and quills."
    );

    addSomeLightDescriptionTemplate(
        "a wooden writing desk stands near the wall, its surface sloped and clear"
    );
    addDimLightDescriptionTemplate(
        "a writing desk is visible in the gloom, its outline small and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a writing desk can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a writing desk is present, but details are lost "
        "in the darkness"
    );
}
