//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crucible");
    addAlias("melting pot");
    addAlias("smelting crucible");

    addAdjectives(({ "clay", "heat-cracked", "blackened", "thick-walled",
        "small", "sturdy", "scorched", "ceramic", "stained", "heavy" }));

    addDescriptionTemplate("a ##Adjective## crucible for melting metal");

    addItemTemplate(
        "The crucible is a thick-walled clay vessel shaped to withstand "
        "extreme heat, its exterior blackened and cracked from repeated "
        "firings. The interior is glazed with a thin coat of slag and "
        "solidified metal drips. It sits in an iron ring cradle that "
        "allows it to be tilted for pouring."
    );

    addSomeLightDescriptionTemplate(
        "a blackened clay crucible sits in its iron cradle near the forge"
    );
    addDimLightDescriptionTemplate(
        "a dark clay vessel sits in an iron ring by the fire"
    );
    addLowLightDescriptionTemplate(
        "a dark rounded shape sits in a metal frame"
    );
    addNearDarkDescriptionTemplate(
        "a heavy shape in a metal frame is barely visible"
    );
}
