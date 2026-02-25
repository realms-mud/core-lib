//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tailor interior");

    addItemTemplate(
        "The tailor's shop is a bright, orderly space filled with bolts of "
        "fabric in every color - rich velvets, sturdy linens, and fine silks "
        "arranged on wooden racks. A large cutting table dominates the center "
        "of the room, its surface scattered with patterns, shears, and coils "
        "of thread. Dress forms stand along one wall, draped in half-finished "
        "garments. Spools of ribbon and lace hang from a pegboard, and a "
        "full-length mirror in a carved frame leans near the fitting area. "
        "The faint scent of lavender sachets drifts from the fabric stores."
    );

    addNearDarkDescriptionTemplate(
        "the tailor's shop is nearly invisible in the darkness, with only "
        "the vague outlines of dress forms standing like silent figures"
    );
    addLowLightDescriptionTemplate(
        "the tailor's shop is shrouded in gloom, bolts of fabric reduced "
        "to dark shapes on their racks"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the cutting table and the silhouettes of dress "
        "forms draped in half-finished garments"
    );
    addSomeLightDescriptionTemplate(
        "the tailor's shop is bright enough to distinguish the colors of "
        "the fabrics and the details of the garments in progress"
    );
    addDescriptionTemplate(
        "light streams into the tailor's shop, making the silks and velvets "
        "shimmer and the threads on the cutting table gleam"
    );
}
