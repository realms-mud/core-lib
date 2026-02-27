//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bellows");
    addAlias("forge bellows");
    addAlias("great bellows");

    addAdjectives(({ "leather", "large", "creaking", "soot-blackened",
        "well-worn", "massive", "sturdy", "heavy", "old", "functional" }));

    addDescriptionTemplate("a ##Adjective## set of bellows beside the forge");

    addItemTemplate(
        "The bellows is a great contraption of leather, wood, and iron, "
        "designed to force air into the forge fire. The leather is "
        "darkened and cracked from years of heat, and the wooden handles "
        "are worn smooth. When worked, it produces a deep wheezing "
        "breath that brings the coals to white heat."
    );

    addSomeLightDescriptionTemplate(
        "a large set of forge bellows stands beside the fire, leather and "
        "iron"
    );
    addDimLightDescriptionTemplate(
        "a bulky shape beside the forge appears to be a set of bellows"
    );
    addLowLightDescriptionTemplate(
        "a large leather and wood contraption sits by the forge"
    );
    addNearDarkDescriptionTemplate(
        "the creak of leather suggests bellows nearby"
    );
}
