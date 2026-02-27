//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mash tun");
    addAlias("tun");
    addAlias("mashing vessel");

    addAdjectives(({ "large", "copper-bottomed", "wooden", "steaming",
        "aromatic", "well-used", "heavy", "sturdy", "insulated", "warm" }));

    addDescriptionTemplate("a ##Adjective## mash tun for steeping grain");

    addItemTemplate(
        "The mash tun is a large insulated vessel where crushed grain "
        "steeps in hot water to extract its sugars. A false bottom of "
        "woven straw filters the liquid, and a spigot near the base allows "
        "the sweet wort to be drawn off. The air around it is thick with "
        "the warm, bready aroma of steeping grain."
    );

    addSomeLightDescriptionTemplate(
        "a mash tun steams gently, the warm smell of steeped grain heavy "
        "in the air"
    );
    addDimLightDescriptionTemplate(
        "a large vessel steams faintly, its spigot visible near the base"
    );
    addLowLightDescriptionTemplate(
        "a large steaming vessel sits in the work area"
    );
    addNearDarkDescriptionTemplate(
        "the warm, bready smell of steeping grain fills the air"
    );
}
