//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("privy");
    addAlias("outhouse");
    addAlias("latrine");
    addAlias("toilet");

    addAdjectives(({ "wooden", "simple", "enclosed", "old", "worn", "small",
        "functional", "drafty", "plain", "weathered" }));

    addDescriptionTemplate("a ##Adjective## privy with a wooden seat");

    addItemTemplate(
        "This privy is a small, enclosed structure with a wooden seat set "
        "over a pit. The boards are weathered and the door creaks on its "
        "hinges. A small vent near the roof lets in a bit of light and air."
    );

    addSomeLightDescriptionTemplate(
        "a wooden privy stands in the corner, its door slightly ajar"
    );
    addDimLightDescriptionTemplate(
        "a small privy is visible in the gloom, its outline plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a privy can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a privy is present, but details are lost in "
        "the darkness"
    );
}
