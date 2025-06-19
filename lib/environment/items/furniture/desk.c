//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("desk");
    addAlias("writing desk");
    addAlias("wooden desk");
    addAlias("table");

    addAdjectives(({ "wooden", "broad", "carved", "plain", "old", "sturdy",
        "polished", "functional", "rectangular", "worn" }));

    addDescriptionTemplate("a ##Adjective## desk with a flat writing surface");

    addItemTemplate(
        "This desk is made from solid wood, with a broad, flat surface for "
        "writing or reading. The legs are sturdy, and the wood is polished "
        "smooth by years of use. A small drawer is set beneath the top."
    );

    addSomeLightDescriptionTemplate(
        "a wooden desk stands near the window, its surface clear and inviting"
    );
    addDimLightDescriptionTemplate(
        "a desk is visible in the gloom, its outline broad and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a desk can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a desk is present, but details are lost in the "
        "darkness"
    );
}
