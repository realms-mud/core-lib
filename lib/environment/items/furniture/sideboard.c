//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sideboard");
    addAlias("buffet");
    addAlias("serving table");
    addAlias("wooden sideboard");

    addAdjectives(({ "long", "wooden", "carved", "broad", "sturdy", "old",
        "polished", "plain", "functional", "panelled" }));

    addDescriptionTemplate("a ##Adjective## sideboard with drawers and cabinets");

    addItemTemplate(
        "This sideboard is a long, low piece of furniture with drawers and "
        "cabinets beneath a broad serving surface. The wood is carved with "
        "simple designs, and the handles are made of iron."
    );

    addSomeLightDescriptionTemplate(
        "a wooden sideboard stands along the wall, its surface ready for serving"
    );
    addDimLightDescriptionTemplate(
        "a sideboard is visible in the gloom, its outline long and low"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a sideboard can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a sideboard is present, but details are lost in "
        "the darkness"
    );
}
