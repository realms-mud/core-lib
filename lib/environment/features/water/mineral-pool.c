//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mineral pool");
    addAlias("shallow pool");
    addAlias("pool");

    addDescriptionTemplate("a still pool edged with pale mineral scales");
    addItemTemplate(
        "Water gathers in a hollow beneath the shelf, clear at the center "
        "and cloudy where it touches the stone. Each drop from the roof "
        "sends a ring across the surface; the mineral rim records how "
        "high the pool rises after a heavy rain."
    );

    addNearDarkDescriptionTemplate(
        "a still patch of water beneath the rock shelf");
    addLowLightDescriptionTemplate(
        "a small pool with a pale rim");
    addDimLightDescriptionTemplate(
        "a clear pool edged in mineral deposits");
    addSomeLightDescriptionTemplate(
        "a shallow mineral pool reflecting the limestone roof");
}
