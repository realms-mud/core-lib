//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("monumental staircase");
    addAlias("staircase");
    addAlias("stairs");
    addAlias("steps");
    addAlias("entrance stairs");

    addAdjectives(({ "broad", "imposing", "grand", "marble", "sweeping" }));

    addDescriptionTemplate("##Adjective## staircase leading to the museum's "
        "impressive entrance");

    addItemTemplate("The wide marble steps ascend majestically to the columned "
        "portico, designed to elevate visitors both literally and spiritually "
        "as they approach the temple of culture");

    addSomeLightDescriptionTemplate("a grand set of marble stairs that rise "
        "impressively to the museum entrance flanked by columns");

    addDimLightDescriptionTemplate("a broad staircase that appears to lead up "
        "to the building's main entrance");

    addLowLightDescriptionTemplate("what seems to be a wide set of steps "
        "leading up to the building");

    addNearDarkDescriptionTemplate("a vague impression of rising steps leading "
        "toward the building's entrance");
}
