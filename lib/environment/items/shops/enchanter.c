//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("enchanter interior");

    addItemTemplate(
        "The enchanter's sanctum hums with a faint, almost subliminal energy "
        "that makes the skin prickle. The room is circular, its walls lined "
        "with shelves of crystal phials, bound grimoires, and jars of luminous "
        "reagents that cast shifting colors across the ceiling. An inscribed "
        "stone worktable occupies the center, its surface etched with arcane "
        "circles and inlaid with thin lines of silver. Rune-carved focusing "
        "rods, prisms of cut quartz, and fine copper wire fill a nearby rack. "
        "A faint ozone scent mingles with the earthy smell of dried spell "
        "components, and the candles on the walls burn without flickering."
    );

    addNearDarkDescriptionTemplate(
        "the enchanter's sanctum is dark, but a faint luminescence from the "
        "reagent jars bathes the shelves in ghostly blues and greens"
    );
    addLowLightDescriptionTemplate(
        "the glowing reagents on the shelves cast pale, shifting light across "
        "the enchanter's worktable and its inscribed circles"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the arcane circles on the worktable and the "
        "colorful array of phials and grimoires lining the walls"
    );
    addSomeLightDescriptionTemplate(
        "the enchanter's sanctum is bright enough to read the runes etched "
        "into the worktable and discern the labels on the reagent jars"
    );
    addDescriptionTemplate(
        "light fills the enchanter's sanctum, making the silver inlay gleam "
        "and the crystal phials sparkle with contained energy"
    );
}
