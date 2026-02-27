//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mill gears");
    addAlias("gears");
    addAlias("wooden gears");
    addAlias("gear mechanism");

    addAdjectives(({ "massive", "wooden", "interlocking", "creaking",
        "greased", "turning", "ancient", "heavy", "oak", "complex" }));

    addDescriptionTemplate("##Adjective## mill gears meshing with slow precision");

    addItemTemplate(
        "The mill gears are a series of interlocking wooden cog wheels, "
        "their teeth carved from seasoned oak and greased with tallow. "
        "They transfer the turning force of the water wheel to the "
        "millstones above through a system of shafts and pinions. The "
        "mechanism groans and clicks rhythmically as the teeth engage "
        "and release."
    );

    addSomeLightDescriptionTemplate(
        "massive wooden gears mesh and turn, their teeth greased and "
        "clicking"
    );
    addDimLightDescriptionTemplate(
        "large wooden wheels turn and interlock, their motion relentless"
    );
    addLowLightDescriptionTemplate(
        "large shapes turn and mesh in the gloom, clicking rhythmically"
    );
    addNearDarkDescriptionTemplate(
        "the grinding click of wooden gears fills the darkness"
    );
}
