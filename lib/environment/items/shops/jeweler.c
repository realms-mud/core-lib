//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("jeweler interior");

    addItemTemplate(
        "The jeweler's shop is small but exquisite. Glass-topped display cases "
        "line the walls, each holding rings, brooches, and pendants set with "
        "polished stones that catch the light. A workbench at the rear is "
        "fitted with a magnifying lens on an articulated arm, surrounded by "
        "tiny hammers, fine pliers, and trays of uncut gems. Velvet-lined "
        "drawers hold chains of silver and gold. The walls are paneled in "
        "dark wood, and a heavy iron strongbox sits bolted to the floor "
        "beneath the counter."
    );

    addNearDarkDescriptionTemplate(
        "the jeweler's shop is swallowed by darkness, with only the barest "
        "twinkle from a gemstone catching some unseen light"
    );
    addLowLightDescriptionTemplate(
        "the display cases are dim shapes in the gloom, an occasional glint "
        "of metal or stone the only hint of their contents"
    );
    addDimLightDescriptionTemplate(
        "soft light plays across the glass-topped cases, revealing the "
        "outlines of rings and pendants within"
    );
    addSomeLightDescriptionTemplate(
        "the jeweler's shop is bright enough to admire the polished stones "
        "and the fine metalwork on display"
    );
    addDescriptionTemplate(
        "light fills the jeweler's shop, setting the gems ablaze with color "
        "and making the gold and silver chains gleam warmly"
    );
}
