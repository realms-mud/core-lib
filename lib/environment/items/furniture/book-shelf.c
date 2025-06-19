//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("book shelf");
    addAlias("bookshelf");
    addAlias("wooden bookshelf");
    addAlias("shelf");

    addAdjectives(({ "wooden", "carved", "tall", "broad", "sturdy",
        "old", "ornate", "functional", "dusty" }));

    addDescriptionTemplate("a ##Adjective## book shelf filled with old tomes");

    addItemTemplate(
        "This bookshelf is crafted from dark wood, its shelves "
        "lined with old tomes and scrolls. The uprights are carved with "
        "simple patterns, and the wood is worn smooth by years of use."
    );

    addSomeLightDescriptionTemplate(
        "a wooden bookshelf stands against the wall, its shelves crowded with "
        "books"
    );
    addDimLightDescriptionTemplate(
        "a bookshelf is visible in the gloom, its outline filled with "
        "rectangular shapes"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a bookshelf can be made out, little more than a "
        "shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a bookshelf is present, but details are lost "
        "in the darkness"
    );
}
