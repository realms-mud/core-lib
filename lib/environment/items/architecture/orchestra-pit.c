//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("orchestra pit");
    addAlias("pit");
    addAlias("musicians area");
    addAlias("mosaic floor");

    addAdjectives(({ "semicircular", "ancient", "paved", "stone" }));

    addDescriptionTemplate("##Adjective## area between the lowest tier of seating and the stage");
    addItemTemplate("The floor has a mosaic pattern of alternating light and dark stones, though many have been displaced over time");
    addItemTemplate("This area was once reserved for musicians and chorus performers essential to ancient theatrical productions");

    addSomeLightDescriptionTemplate("a semicircular area with a patterned stone floor");
    addDimLightDescriptionTemplate("a lower area between the stage and first row of seating");
    addLowLightDescriptionTemplate("what appears to be a sunken area before the stage");
    addNearDarkDescriptionTemplate("a darker section between the seating and stage area");
}
