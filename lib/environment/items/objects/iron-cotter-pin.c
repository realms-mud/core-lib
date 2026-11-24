//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("iron cotter pin");
    addAlias("cotter pin");
    addAlias("retaining pin");
    addAlias("pin");

    addAdjectives(({ "iron", "heavy", "greasy", "bent" }));

    addDescriptionTemplate("an ##Adjective## cotter pin through the gear");
    addItemTemplate(
        "The thick pin passes through the drive gear's retaining collar. "
        "Its bent end is accessible from behind the assembly, where a "
        "short pull would let the counterweight settle out of alignment."
    );

    addSomeLightDescriptionTemplate(
        "a bent iron pin securing the drive gear");
    addDimLightDescriptionTemplate(
        "a retaining pin through the rear gear");
    addLowLightDescriptionTemplate(
        "a short metal pin at the back of the machine");
    addNearDarkDescriptionTemplate(
        "a small iron shape behind the gears");
}
