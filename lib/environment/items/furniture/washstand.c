//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("washstand");
    addAlias("stand");
    addAlias("basin stand");
    addAlias("wooden washstand");

    addAdjectives(({ "wooden", "simple", "carved", "old", "worn", "small",
        "functional", "plain", "polished", "upright" }));

    addDescriptionTemplate("a ##Adjective## washstand with a ceramic basin");

    addItemTemplate(
        "This washstand is a small wooden table with a round ceramic basin set "
        "into the top. A shelf below holds a pitcher for water, and the wood "
        "is worn smooth by years of use."
    );

    addSomeLightDescriptionTemplate(
        "a wooden washstand stands near the wall, its basin clean and empty"
    );
    addDimLightDescriptionTemplate(
        "a washstand is visible in the gloom, its outline upright and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a washstand can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a washstand is present, but details are lost "
        "in the darkness"
    );
}
