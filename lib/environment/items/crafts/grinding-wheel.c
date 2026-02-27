//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("grinding wheel");
    addAlias("grindstone");
    addAlias("whetstone wheel");
    addAlias("sharpening wheel");

    addAdjectives(({ "large", "spinning", "stone", "pedal-driven",
        "well-worn", "grooved", "gritty", "heavy", "functional", "old" }));

    addDescriptionTemplate("a ##Adjective## grinding wheel on an iron frame");

    addItemTemplate(
        "The grinding wheel is a thick disc of coarse sandstone mounted on "
        "an iron axle within a sturdy frame. A foot pedal drives the wheel "
        "through a simple crank mechanism, and a water trough beneath keeps "
        "the stone wet during sharpening. The stone is grooved and uneven "
        "from years of blades pressed against it."
    );

    addSomeLightDescriptionTemplate(
        "a grinding wheel sits on its frame, stone grooved from heavy use"
    );
    addDimLightDescriptionTemplate(
        "a round stone wheel mounted on a frame is visible"
    );
    addLowLightDescriptionTemplate(
        "a circular shape on a frame suggests a grinding wheel"
    );
    addNearDarkDescriptionTemplate(
        "a heavy stone shape on a frame is barely discernible"
    );
}
