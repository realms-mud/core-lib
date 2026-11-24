//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Abandoned Scions Hall");
    InteriorType("stone temple and meditation halls");
    setFloorPlanType("guild");

    addDescriptionTemplate("a shuttered stone hall with weathered tower "
        "sigils and dust gathered around its sealed entrance");
    addNearDarkDescriptionTemplate("a dark, neglected stone hall");
    addLowLightDescriptionTemplate("an abandoned stone hall with faded "
        "sigils and no light within");
    addDimLightDescriptionTemplate("a deserted guild hall whose doors "
        "have long been closed");
    addSomeLightDescriptionTemplate("an empty stone hall, silent behind "
        "its closed doors");
}
