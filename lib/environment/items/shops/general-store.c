//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("general store interior");

    addItemTemplate(
        "The general store is a sprawling, comfortable space packed to the "
        "rafters with goods of every description. Barrels of nails, coils of "
        "rope, and stacks of tin pots crowd the floor. Shelves hold lanterns, "
        "flint and steel kits, blankets, waterskins, and bundles of tallow "
        "candles. A glass-fronted case on the counter displays pocket knives, "
        "sewing needles, and small brass compasses. Sacks of salt and sugar "
        "lean against one wall beside crates of dried provisions. The shop "
        "has the pleasant, dusty smell of a place where everything useful can "
        "be found if one looks long enough."
    );

    addNearDarkDescriptionTemplate(
        "the general store is a maze of dark shapes, barrels and crates "
        "forming uncertain obstacles in every direction"
    );
    addLowLightDescriptionTemplate(
        "the cluttered shelves of the general store are dim outlines, "
        "the goods on them indistinguishable in the poor light"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the crowded shelves and the barrels on the "
        "floor, though reading labels remains a challenge"
    );
    addSomeLightDescriptionTemplate(
        "the general store is bright enough to browse the packed shelves "
        "and sort through the varied goods on display"
    );
    addDescriptionTemplate(
        "light fills the general store, showing the cheerful clutter of "
        "supplies and the glass-fronted display case on the counter"
    );
}
