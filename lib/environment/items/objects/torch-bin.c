//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("torch bin");
    addAlias("bin of torches");
    addAlias("torch cache");
    addAdjectives(({ "dry", "wooden", "iron-bound", "covered", "old" }));

    addDescriptionTemplate("a ##Adjective## bin of spare torches");
    addItemTemplate(
        "The covered bin keeps spare torches and kindling above the damp "
        "floor. A few bundles of dry tinder are wrapped in waxed cloth."
    );

    addSomeLightDescriptionTemplate(
        "a covered bin stocked with spare torches and tinder");
    addDimLightDescriptionTemplate(
        "a covered torch bin set above the damp floor");
    addLowLightDescriptionTemplate(
        "a low wooden bin against the wall");
    addNearDarkDescriptionTemplate(
        "a squat shape at the edge of the passage");
}
