//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("clothier interior");

    addItemTemplate(
        "The clothier's shop is a refined space arranged for presentation. "
        "Ready-made garments hang from polished wooden rods - traveling "
        "cloaks in muted wool, linen tunics in natural and dyed shades, "
        "sturdy breeches, and fine cotton shirts with embroidered collars. "
        "A table near the entrance is piled with folded scarves, stockings, "
        "and broad-brimmed hats. Bolts of surplus fabric are stacked along "
        "the back wall for those who prefer to have something custom-made "
        "elsewhere. A tall mirror stands beside the counter, and the shop "
        "carries the clean, pleasant smell of freshly laundered cloth."
    );

    addNearDarkDescriptionTemplate(
        "the clothier's shop is dark, the hanging garments swaying faintly "
        "like formless shapes in the gloom"
    );
    addLowLightDescriptionTemplate(
        "the clothier's shop is dimly lit, the garments on their rods "
        "reduced to shadowy outlines of fabric"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the rows of hanging cloaks and tunics and the "
        "folded goods stacked on the entrance table"
    );
    addSomeLightDescriptionTemplate(
        "the clothier's shop is bright enough to distinguish the colors and "
        "weaves of the garments and the embroidery on the finer shirts"
    );
    addDescriptionTemplate(
        "light fills the clothier's shop, making the dyed fabrics vivid "
        "and the embroidered details crisp and inviting"
    );
}
