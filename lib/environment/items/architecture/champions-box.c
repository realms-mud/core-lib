//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("champion's box");
    addAlias("box");
    addAlias("viewing box");
    addAlias("special seating");

    addAdjectives(({ "elevated", "ornate", "prestigious", "canopied",
        "decorated" }));

    setDescriptionTemplate("##Adjective## viewing box elevated above the common "
        "stands for important officials and sponsors");

    addItemTemplate("The box is draped with colorful fabrics and features "
        "comfortable seating from which to enjoy the bloodsport below");

    addSomeLightDescriptionTemplate("a special elevated section with better "
        "seating and a canopy for shade, reserved for important spectators");

    addDimLightDescriptionTemplate("what appears to be a special viewing area "
        "rising above the regular stands");

    addLowLightDescriptionTemplate("a raised platform or box that seems more "
        "elaborately constructed than the surrounding seating");

    addNearDarkDescriptionTemplate("a vaguely elevated shape that might be "
        "special seating for important spectators");
}
