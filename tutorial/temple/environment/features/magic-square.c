//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("magic square");
    suppressEntryMessage();

    addDescriptionTemplate("along the wall near the entry, many "
        "intricate runes have been carved. In the center of the "
        "room stands a table carved of onxy. On its surface sits a "
        "grid with several glowing runes.\n"
        "##call_other::key::/lib/tutorial/temple/objects/magic-square.c::displayMagicSquare::"
        "\nTo the right of the grid, there is another grid of slightly raised cubes of "
        "onyx that look like they can be pushed into its surface. ");
    addSourceOfLight(10);

    addAlias("grid");

    addItemTemplate("All of the pedestals appear to be of the same nature - "
        "about three feet tall, they appear to have been formed "
        "of the same amethyst from which the whole room was formed.");
}
