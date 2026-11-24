//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Phaedra memorial statues");
    addAlias("statues of former commanders");
    addAlias("Phaedra statues");

    addAdjectives(({ "stone", "armored", "old", "weathered" }));

    addDescriptionTemplate(
        "a row of ##Adjective## statues of Phaedra commanders");
    addItemTemplate(
        "The figures commemorate former commanders of Phaedra. Each wears "
        "the service armor of a different generation, with names and "
        "campaign dates cut into the narrow plinths."
    );

    addSomeLightDescriptionTemplate(
        "a row of carved commanders in old Phaedra armor");
    addDimLightDescriptionTemplate(
        "a line of armored figures along the hall");
    addLowLightDescriptionTemplate(
        "the dark outlines of several statues");
    addNearDarkDescriptionTemplate(
        "the rigid silhouettes of figures against the wall");
}
