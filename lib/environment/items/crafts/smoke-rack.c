//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("smoke rack");
    addAlias("smoking rack");
    addAlias("curing rack");

    addAdjectives(({ "wooden", "soot-blackened", "laden", "fragrant",
        "well-used", "dark", "sturdy", "simple", "old", "greasy" }));

    addDescriptionTemplate("a ##Adjective## smoke rack hung with meats and fish");

    addItemTemplate(
        "The smoke rack is a wooden frame set above a smoldering fire pit, "
        "its crossbars hung with strips of meat and fish being slowly cured "
        "in fragrant smoke. The wood is black with soot and grease, and the "
        "air is thick with the rich, savory smell of smoking meat. Hickory "
        "and applewood chips smolder in the pit below."
    );

    addSomeLightDescriptionTemplate(
        "a smoke rack hangs over smoldering coals, laden with curing meats"
    );
    addDimLightDescriptionTemplate(
        "a rack of hanging meats is visible above a smoky fire pit"
    );
    addLowLightDescriptionTemplate(
        "dark shapes hang above a faintly glowing pit"
    );
    addNearDarkDescriptionTemplate(
        "the rich smell of smoking meat fills the air"
    );
}
