//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("seed bin");
    addAlias("seed box");
    addAlias("planting bin");

    addAdjectives(({ "wooden", "partitioned", "labeled", "dusty",
        "full", "old", "well-organized", "sturdy", "lidded", "dry" }));

    addDescriptionTemplate("a ##Adjective## seed bin with labeled compartments");

    addItemTemplate(
        "The seed bin is a broad wooden box divided into compartments, "
        "each holding a different variety of seed. Small wooden labels "
        "are tacked to each divider — wheat, barley, turnip, carrot, "
        "and others. The seeds are dry and carefully stored, protected "
        "from moisture and vermin by tight-fitting lids."
    );

    addSomeLightDescriptionTemplate(
        "a seed bin sits open, its compartments filled with sorted seeds"
    );
    addDimLightDescriptionTemplate(
        "a partitioned wooden box is visible, small labels on each section"
    );
    addLowLightDescriptionTemplate(
        "a broad wooden box with dividers sits on a shelf"
    );
    addNearDarkDescriptionTemplate(
        "the dry, earthy smell of stored seeds comes from nearby"
    );
}
