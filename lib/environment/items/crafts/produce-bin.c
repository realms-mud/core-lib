//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("produce bin");
    addAlias("vegetable bin");
    addAlias("produce crate");
    addAlias("market bin");

    addAdjectives(({ "wooden", "overflowing", "colorful", "slatted",
        "fresh", "well-stocked", "rustic", "open", "sturdy", "neat" }));

    addDescriptionTemplate("a ##Adjective## produce bin filled with fresh goods");

    addItemTemplate(
        "The produce bin is a shallow wooden crate with slatted sides for "
        "ventilation, heaped with fresh vegetables and fruits. Root "
        "vegetables still carry traces of garden soil, and the leafy "
        "greens are dewy with freshness. A careful hand has arranged "
        "the contents for display, with the finest specimens on top."
    );

    addSomeLightDescriptionTemplate(
        "a produce bin overflows with colorful fruits and vegetables"
    );
    addDimLightDescriptionTemplate(
        "a wooden bin holds assorted produce, its colors muted in the light"
    );
    addLowLightDescriptionTemplate(
        "a shallow bin holds something fresh and organic"
    );
    addNearDarkDescriptionTemplate(
        "the earthy smell of fresh produce comes from nearby"
    );
}
