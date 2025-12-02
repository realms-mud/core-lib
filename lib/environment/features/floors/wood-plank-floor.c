//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wood plank floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("wood");
    addAlias("wooden");
    addAlias("plank");
    addAlias("planks");

    addAdjectives(({ "of wide, thick planks laid in parallel rows",
        "with visible nail heads securing each board",
        "that creaks and groans with every step",
        "showing deep scratches and wear patterns",
        "with gaps between planks wide enough to catch debris",
        "that has warped and twisted with age and moisture",
        "stained dark with years of use and spilled liquids",
        "with some planks noticeably higher than others" }));

    addDescriptionTemplate("the floor is constructed of wood planks "
        "##Adjective##. The heavy timbers create a sturdy if somewhat "
        "uneven surface");
    addSomeLightDescriptionTemplate("the floor is constructed of wood planks "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor consists of wooden planks. "
        "They creak ominously in the darkness underfoot");
    addLowLightDescriptionTemplate("the floor is made of wide wooden planks. "
        "Dark lines mark the gaps between the heavy timbers");
    addDimLightDescriptionTemplate("the floor is planked with heavy timber. "
        "The wood shows considerable wear and weathering");

    addItemTemplate("The floor consists of thick wooden planks laid side "
        "by side and secured with iron nails. The heavy timbers have aged "
        "and weathered, creating an uneven surface with gaps between boards "
        "and the occasional loose plank that shifts underfoot. Deep scratches "
        "and stains tell of years of hard use.");
}
