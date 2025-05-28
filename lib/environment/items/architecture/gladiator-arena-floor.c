//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("arena floor");
    addAlias("floor");
    addAlias("sand");
    addAlias("combat area");

    addAdjectives(({ "sandy", "blood-stained", "raked", "battle-worn",
        "circular" }));

    setDescriptionTemplate("##Adjective## sand-covered floor where gladiators "
        "fight and die");

    addItemTemplate("The sand is regularly raked between bouts, but dark "
        "stains of blood and other fluids remain visible throughout");

    addSomeLightDescriptionTemplate("a circular area of sand where combatants "
        "face each other for the entertainment of the crowd");

    addDimLightDescriptionTemplate("a sandy floor marked by footprints and "
        "darker patches");

    addLowLightDescriptionTemplate("what appears to be a sand-covered combat "
        "area");

    addNearDarkDescriptionTemplate("a slightly lighter patch suggesting the "
        "sandy floor of the arena");
}
