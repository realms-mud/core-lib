//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ore merchant interior");

    addItemTemplate(
        "The ore merchant's shop is a heavy, earth-toned space built to bear "
        "considerable weight. Stout wooden bins line the walls, each holding "
        "a different raw ore - ruddy iron, greenish copper, dark lead, and "
        "glittering chunks of silver-bearing galena. Samples of rarer finds "
        "sit in a locked glass case on the counter: nuggets of gold, rough "
        "mithril ore with its distinctive blue-silver sheen, and a chunk of "
        "obsidian. A heavy beam scale stands beside the case for weighing "
        "purchases, and a slate board lists prices per stone weight. The air "
        "is dry and carries a faint mineral tang."
    );

    addNearDarkDescriptionTemplate(
        "the ore merchant's shop is lost in darkness, the bins of ore "
        "indistinguishable from the heavy shadows around them"
    );
    addLowLightDescriptionTemplate(
        "the ore bins are dim, heavy shapes along the walls, with only "
        "the faintest glitter from a metallic vein catching the light"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the bins of sorted ore and the locked display "
        "case on the counter, a faint gleam from the rarer samples within"
    );
    addSomeLightDescriptionTemplate(
        "the ore merchant's shop is bright enough to distinguish the "
        "different ores by color and see the prices chalked on the slate"
    );
    addDescriptionTemplate(
        "light fills the ore merchant's shop, making the copper ore gleam "
        "green, the galena sparkle, and the mithril sample shine with an "
        "almost otherworldly luster"
    );
}
