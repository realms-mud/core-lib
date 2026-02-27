//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("washtub");
    addAlias("wash tub");
    addAlias("laundry tub");
    addAlias("scrubbing tub");

    addAdjectives(({ "wooden", "large", "soapy", "steaming", "battered",
        "iron-banded", "well-used", "water-filled", "sturdy", "old" }));

    addDescriptionTemplate("a ##Adjective## washtub filled with soapy water");

    addItemTemplate(
        "The washtub is a broad, shallow wooden tub banded with iron, "
        "filled with water gone grey and soapy from washing. A scrub "
        "board leans against the inside, and a cake of lye soap sits on "
        "the rim. The wood is swollen and waterlogged from constant use, "
        "and the ground around it is perpetually damp."
    );

    addSomeLightDescriptionTemplate(
        "a washtub sits steaming, its soapy water grey and well-used"
    );
    addDimLightDescriptionTemplate(
        "a broad tub of water is visible, a scrub board leaning inside"
    );
    addLowLightDescriptionTemplate(
        "a broad shallow container of water sits on the ground"
    );
    addNearDarkDescriptionTemplate(
        "the sharp smell of lye soap and damp cloth fills the air"
    );
}
