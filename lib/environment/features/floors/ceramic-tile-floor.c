//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ceramic tile floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("tile");
    addAlias("tiles");
    addAlias("ceramic");

    addAdjectives(({ "of glazed tiles in brilliant blue and white",
        "with hand-painted designs on each square",
        "featuring geometric patterns in earth tones",
        "that gleams with a glossy, waterproof finish",
        "with some tiles cracked or chipped from use",
        "showing intricate floral motifs in faded colors",
        "that reflects light from its polished surface",
        "with grout lines creating a regular grid pattern" }));

    addDescriptionTemplate("the floor is laid with ceramic tiles "
        "##Adjective##. The fired clay creates a smooth "
        "and decorative surface");
    addSomeLightDescriptionTemplate("the floor is laid with ceramic tiles "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor appears to be tiled with "
        "smooth squares. The surface feels slick and cool");
    addLowLightDescriptionTemplate("the floor consists of fitted tiles. "
        "Faint lines mark the joints between squares");
    addDimLightDescriptionTemplate("the floor is tiled with ceramic squares. "
        "The glazed surface has a subtle reflective quality");

    addItemTemplate("The floor is laid with ceramic tiles, each square "
        "carefully crafted from fired clay and finished with a protective "
        "glaze. The tiles fit together with narrow grout lines, creating "
        "a smooth, waterproof surface that combines practical durability "
        "with decorative beauty in its colors and patterns.");
}
