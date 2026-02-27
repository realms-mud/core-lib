//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mortar and pestle");
    addAlias("mortar");
    addAlias("pestle");
    addAlias("grinding bowl");

    addAdjectives(({ "stone", "heavy", "well-worn", "marble", "stained",
        "smooth", "polished", "old", "sturdy", "dark" }));

    addDescriptionTemplate("a ##Adjective## mortar and pestle on the counter");

    addItemTemplate(
        "The mortar is a heavy stone bowl, its interior worn smooth and "
        "stained with the residue of a thousand ground ingredients — herb "
        "green, mineral grey, root brown. The pestle is a thick cylinder "
        "of the same stone, shaped to fit the hand and polished by use "
        "to a satin finish."
    );

    addSomeLightDescriptionTemplate(
        "a stone mortar and pestle sits on the counter, stained with use"
    );
    addDimLightDescriptionTemplate(
        "a stone bowl and grinding tool are visible on the counter"
    );
    addLowLightDescriptionTemplate(
        "a round stone shape sits on the counter"
    );
    addNearDarkDescriptionTemplate(
        "the pungent scent of ground herbs hangs in the air"
    );
}
