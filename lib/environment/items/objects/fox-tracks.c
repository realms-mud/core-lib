//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fox tracks");
    addAlias("paw prints");
    addDescriptionTemplate("a line of fox tracks in the damp earth");
    addItemTemplate(
        "The prints lead from the brook's edge to a split in the roots. "
        "Smaller tracks follow the same route, and the mud is fresh enough "
        "to show that the den is still used.");
    addNearDarkDescriptionTemplate("small impressions in the earth");
    addLowLightDescriptionTemplate("paw prints in damp soil");
    addDimLightDescriptionTemplate("a fresh trail of fox prints");
    addSomeLightDescriptionTemplate(
        "a fox's tracks leading toward a narrow root-bound opening");
}
