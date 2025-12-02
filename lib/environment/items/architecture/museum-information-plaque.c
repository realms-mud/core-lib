//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("informational plaque");
    addAlias("plaque");
    addAlias("sign");
    addAlias("description");
    addAlias("label");

    addAdjectives(({ "engraved", "detailed", "explanatory", "instructive",
        "historical" }));

    addDescriptionTemplate("##Adjective## plaque providing context for the "
        "nearby exhibit");

    addItemTemplate("The carefully crafted plaque offers details about the "
        "origin, significance, and history of the artifacts on display");

    addSomeLightDescriptionTemplate("an engraved plaque with text describing "
        "the historical context of the exhibit");

    addDimLightDescriptionTemplate("what appears to be an informational sign "
        "with text too dim to read clearly");

    addLowLightDescriptionTemplate("a small rectangular shape that might "
        "contain writing");

    addNearDarkDescriptionTemplate("a barely visible shape attached to the "
        "wall or display");
}
