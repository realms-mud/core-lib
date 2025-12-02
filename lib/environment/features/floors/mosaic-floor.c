//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mosaic floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("mosaic");
    addAlias("tiles");

    addAdjectives(({ "depicting intricate geometric patterns in colored stone",
        "with tiny tiles arranged in elaborate designs",
        "showing faded images of mythical creatures",
        "featuring borders of intertwining vines and flowers",
        "with missing tiles creating gaps in the pattern",
        "displaying masterful craftsmanship in miniature stonework",
        "that shows scenes of ancient battles and victories",
        "with gold and silver tesserae catching the light" }));

    addDescriptionTemplate("the floor is a mosaic "
        "##Adjective##. Thousands of tiny stone pieces create "
        "artwork beneath your feet");
    addSomeLightDescriptionTemplate("the floor is a mosaic "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor appears to be made of many "
        "small pieces. Smooth stones create patterns underfoot");
    addLowLightDescriptionTemplate("the floor consists of fitted stone "
        "pieces. Faint patterns are visible in the limited light");
    addDimLightDescriptionTemplate("the floor is a mosaic of small tiles. "
        "Elaborate patterns can be dimly perceived");

    addItemTemplate("The floor is an elaborate mosaic composed of thousands "
        "of tiny stone tiles called tesserae, each carefully cut and placed "
        "to create intricate patterns and images. The artistry represents "
        "countless hours of skilled labor, with colored stones, glass, and "
        "sometimes precious metals combining to form designs of remarkable "
        "beauty and complexity.");
}
