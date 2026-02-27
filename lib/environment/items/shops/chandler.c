//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("chandler interior");

    addItemTemplate(
        "The chandler's shop is a narrow space suffused with the warm, waxy "
        "scent of tallow and beeswax. Rows of candles in every size hang "
        "from drying racks suspended from the ceiling - slender tapers, "
        "thick pillar candles, and rushlights bundled together with twine. "
        "Blocks of rendered tallow and rounds of beeswax are stacked on a "
        "side table, alongside molds and wicking spools. A few bars of lye "
        "soap and small pots of lamp oil sit on a shelf near the counter. "
        "The floor is slick in places where wax has dripped and hardened."
    );

    addNearDarkDescriptionTemplate(
        "the chandler's shop is almost completely dark, the waxy smell of "
        "tallow the strongest indication of what surrounds you"
    );
    addLowLightDescriptionTemplate(
        "the chandler's shop is dim, with the pale shapes of hanging candles "
        "just visible against the dark ceiling"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the rows of candles hanging from drying racks "
        "and the blocks of wax stacked on the side table"
    );
    addSomeLightDescriptionTemplate(
        "the chandler's shop is bright enough to see the different sizes "
        "and colors of the candles and the soap on the shelf"
    );
    addDescriptionTemplate(
        "light fills the chandler's shop, lending a warm glow to the rows "
        "of hanging candles and the smooth blocks of beeswax"
    );
}
