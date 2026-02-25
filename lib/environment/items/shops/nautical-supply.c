//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("nautical supply interior");

    addItemTemplate(
        "The nautical supply shop is a salt-scented space crammed with "
        "everything a mariner could need. Coils of heavy hemp rope hang "
        "from ceiling hooks alongside blocks, pulleys, and lengths of chain. "
        "One wall holds navigation instruments - brass sextants, sand glasses, "
        "and a lodestone compass in a gimbaled box. Shelves are packed with "
        "caulking pitch, rolls of sailcloth, brass fittings, and jars of "
        "tallow for waterproofing. Nets, grappling hooks, and boarding pikes "
        "lean in a corner, and a ship's lantern with thick green glass hangs "
        "over the counter. The whole shop smells of tar, brine, and hemp."
    );

    addNearDarkDescriptionTemplate(
        "the nautical supply shop is dark and smells strongly of tar and "
        "salt, the coils of rope overhead invisible against the ceiling"
    );
    addLowLightDescriptionTemplate(
        "the hanging ropes and chains are dim shapes overhead, and the "
        "brass instruments on the wall catch only the faintest light"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the coils of rope, the navigation instruments, "
        "and the rolls of sailcloth stacked on the shelves"
    );
    addSomeLightDescriptionTemplate(
        "the nautical supply shop is bright enough to read the markings on "
        "the sextants and see the green glass of the ship's lantern"
    );
    addDescriptionTemplate(
        "light fills the nautical supply shop, making the brass instruments "
        "gleam and the coils of rope glow with a warm, golden hue"
    );
}
