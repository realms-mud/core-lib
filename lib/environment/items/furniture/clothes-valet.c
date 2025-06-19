//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("clothes valet");
    addAlias("valet");
    addAlias("clothes stand");
    addAlias("wooden valet");

    addAdjectives(({ "wooden", "upright", "carved", "plain", "old", "sturdy",
        "functional", "tall", "well-made", "broad" }));

    addDescriptionTemplate("a ##Adjective## clothes valet for hanging garments");

    addItemTemplate(
        "This clothes valet is an upright wooden stand with arms and pegs for "
        "hanging garments. The base is broad for stability, and the wood is "
        "worn smooth by years of use."
    );

    addSomeLightDescriptionTemplate(
        "a wooden clothes valet stands near the bed, its arms empty"
    );
    addDimLightDescriptionTemplate(
        "a clothes valet is visible in the gloom, its outline upright and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a clothes valet can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a clothes valet is present, but details are lost "
        "in the darkness"
    );
}
