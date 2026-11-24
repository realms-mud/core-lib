//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("paired stone lions");
    addAlias("lion statues");
    addAlias("stone lions");

    addAdjectives(({ "weathered", "carved", "watchful", "pale" }));

    addDescriptionTemplate(
        "two ##Adjective## stone lions guard the entrance");
    addItemTemplate(
        "The matching lions crouch on low plinths, their forepaws resting "
        "on shields carved with Phaedra's device. Their worn faces look "
        "out across the approach to the headquarters."
    );

    addSomeLightDescriptionTemplate(
        "two carved stone lions on either side of the entrance");
    addDimLightDescriptionTemplate(
        "the paired silhouettes of stone lions");
    addLowLightDescriptionTemplate(
        "two broad shapes flanking the doorway");
    addNearDarkDescriptionTemplate(
        "the faint outline of paired stone figures");
}
