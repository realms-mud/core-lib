//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("window seat");
    addAlias("seat");
    addAlias("window bench");
    addAlias("alcove seat");

    addAdjectives(({ "broad", "cushioned", "carved", "old", "wooden", "deep",
        "comfortable", "upholstered", "sunlit", "inviting" }));

    addDescriptionTemplate("a ##Adjective## window seat built into the alcove");

    addItemTemplate(
        "This window seat is a broad bench built into a window alcove. The "
        "surface is cushioned and the wood is carved with simple designs, "
        "offering a comfortable place to sit and look outside."
    );

    addSomeLightDescriptionTemplate(
        "a window seat is built into the alcove, its cushion sunlit and inviting"
    );
    addDimLightDescriptionTemplate(
        "a window seat is visible in the gloom, its outline broad and low"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a window seat can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a window seat is present, but details are lost "
        "in the darkness"
    );

    useExteriorLighting();
}
