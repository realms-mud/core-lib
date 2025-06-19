//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("display cabinet");
    addAlias("cabinet");
    addAlias("glass cabinet");
    addAlias("wooden display cabinet");

    addAdjectives(({ "ornate", "wooden", "glass-fronted", "tall",
        "carved", "polished", "sturdy", "old", "decorative" }));

    addDescriptionTemplate("a ##Adjective## display cabinet with glass panels");

    addItemTemplate(
        "This display cabinet is crafted from polished wood, its "
        "front set with glass panels to show off valuable items. The frame is "
        "carved with decorative motifs, and the shelves inside are lined with "
        "velvet."
    );

    addSomeLightDescriptionTemplate(
        "a glass-fronted display cabinet stands against the wall, its shelves "
        "showing off various treasures"
    );
    addDimLightDescriptionTemplate(
        "a display cabinet is visible in the gloom, its glass reflecting faint "
        "light"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a display cabinet can be made out, little more than "
        "a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a display cabinet is present, but details are "
        "lost in the darkness"
    );
}
