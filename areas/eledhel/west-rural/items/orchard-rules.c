//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("orchard access board");
    addAlias("orchard rules");
    addAlias("access board");
    addDescriptionTemplate("a weather-darkened orchard access board");
    addItemTemplate(
        "The board marks the lane and creek as public. Fruit from the "
        "cultivated rows, stored hives, and cut wood belong to the "
        "households that tend them. Ask Meral before gathering anything; "
        "the marked baskets are for sale, not free picking.");
    addNearDarkDescriptionTemplate("a board beside the orchard lane");
    addLowLightDescriptionTemplate("a weather-darkened notice board");
    addDimLightDescriptionTemplate(
        "an access notice with several lines of careful writing");
    addSomeLightDescriptionTemplate(
        "an orchard notice setting out the household access rules");
}
