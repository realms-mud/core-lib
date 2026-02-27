//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("armorer interior");

    addItemTemplate(
        "The armorer's shop is a broad, well-organized space dominated by "
        "rows of standing armor forms. Chain hauberks, breastplates of "
        "hammered steel, and suits of riveted scale hang from iron mannequins "
        "like a silent regiment. A workbench along one wall holds riveting "
        "tools, metal snips, and coils of wire for mending mail. Helmets of "
        "various designs - open-faced sallets, great helms, and padded "
        "arming caps - line a high shelf. Sheets of raw steel lean against "
        "the far wall, and the sharp tang of metal polish pervades the air."
    );

    addNearDarkDescriptionTemplate(
        "the armorer's shop is draped in shadow, the standing armor forms "
        "looming like motionless sentinels in the dark"
    );
    addLowLightDescriptionTemplate(
        "the armor forms are ghostly figures in the gloom, their metal "
        "surfaces catching only the faintest traces of light"
    );
    addDimLightDescriptionTemplate(
        "soft light outlines the rows of armor forms and the helmets on "
        "the high shelf, lending the shop a quiet, martial air"
    );
    addSomeLightDescriptionTemplate(
        "the armorer's shop is bright enough to see the individual rings of "
        "the chain mail and the dents hammered smooth on breastplates"
    );
    addDescriptionTemplate(
        "light fills the armorer's shop, making the polished steel gleam "
        "and every rivet and link of mail stand out in sharp detail"
    );
}
