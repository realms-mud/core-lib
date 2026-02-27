//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cobbler interior");

    addItemTemplate(
        "The cobbler's shop is a compact, tidy space that smells of leather "
        "and boot polish. A low workbench dominates the room, covered with "
        "lasts of various sizes, hammers, curved knives, and rolls of thick "
        "thread. Pairs of finished boots and shoes line a shelf along the "
        "wall - sturdy riding boots, simple clogs, and a pair of fine "
        "slippers with embroidered uppers. Scraps of leather and off-cuts "
        "fill a basket beneath the bench, and a pegboard holds an assortment "
        "of buckles, eyelets, and sole plates."
    );

    addNearDarkDescriptionTemplate(
        "the cobbler's shop is nearly invisible in the dark, the smell of "
        "leather and polish the only clue to its nature"
    );
    addLowLightDescriptionTemplate(
        "the cobbler's shop is shrouded in shadow, the workbench and rows "
        "of shoes reduced to indistinct shapes"
    );
    addDimLightDescriptionTemplate(
        "enough light enters the cobbler's shop to reveal the workbench "
        "and the neat rows of boots and shoes on the shelf"
    );
    addSomeLightDescriptionTemplate(
        "the cobbler's shop is well-lit enough to see the fine stitching "
        "on the finished boots and the tools arrayed on the bench"
    );
    addDescriptionTemplate(
        "light fills the cobbler's shop, showing the polished leather of "
        "the finished footwear and the orderly workbench"
    );
}
