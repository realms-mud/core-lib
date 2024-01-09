//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fake forest");

    addAdjectives(({ "deciduous" }));

    addDescriptionTemplate("a ##Adjective## forest");
    addNearDarkDescriptionTemplate("a very dark forest");
    addLowLightDescriptionTemplate("a barely-lit forest");
    addDimLightDescriptionTemplate("a dimly-lit forest");
    addSomeLightDescriptionTemplate("a forest with a little light");
}
