//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mirror");
    addAlias("looking glass");
    addAlias("polished mirror");
    addAlias("glass mirror");

    addAdjectives(({ "polished", "small", "oval", "framed", "metal", "glass",
        "upright", "carved", "old", "plain" }));

    addDescriptionTemplate("a ##Adjective## mirror set in a wooden frame");

    addItemTemplate(
        "This mirror is made from polished metal or glass, set in a carved "
        "wooden frame. The surface is bright and reflective, though slightly "
        "worn with age."
    );

    addSomeLightDescriptionTemplate(
        "a mirror hangs on the wall, its surface gleaming in the light"
    );
    addDimLightDescriptionTemplate(
        "a mirror is visible in the gloom, its outline upright and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a mirror can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a mirror is present, but details are lost in "
        "the darkness"
    );
}
