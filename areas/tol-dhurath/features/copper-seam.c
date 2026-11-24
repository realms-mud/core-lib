//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("copper seam");
    addAlias("copper vein");
    addAdjectives(({ "narrow", "green-streaked", "discontinuous", "shallow" }));
    addDescriptionTemplate("a ##Adjective## copper seam exposed in the rock");
    addNearDarkDescriptionTemplate("a thin mineral line in the rock");
    addLowLightDescriptionTemplate("a narrow seam in the cave wall");
    addDimLightDescriptionTemplate(
        "a green-streaked seam of copper in the stone");
    addSomeLightDescriptionTemplate(
        "a discontinuous copper seam exposed in the cave wall");
    addItemTemplate("The exposed copper is thin and broken by barren rock. "
        "A pick can work loose a small quantity from the stable face, but "
        "the seam does not continue into the unsafe lower gallery.");

    harvestableResource("copper ore", 5,
        "/lib/instances/items/materials/metal-ores/copper.c",
        "the copper seam marked by fresh tool scars, with only a few "
        "pieces of loose ore remaining",
        ({ "copper", "ore", "copper vein" }));
    harvestRequiresTool("copper ore", ([ "blueprint": "pick axe" ]));
    harvestRequiresQuest("copper ore",
        "/areas/minlach/quests/safe-seam.c");
}
