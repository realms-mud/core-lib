//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("armor stand");
    addAlias("stand");
    addAlias("armor rack");

    addItemTemplate(
        "The armor stand is a sturdy wooden frame, shaped to hold a full suit "
        "of armor. Polished breastplates, helmets, and gauntlets are arranged "
        "neatly, ready for inspection or use. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of an armor stand is barely visible, with only the "
        "faintest glint from metal"
    );
    addLowLightDescriptionTemplate(
        "an armor stand stands in the gloom, its armor little more than "
        "shadows"
    );
    addDimLightDescriptionTemplate(
        "the armor stand is faintly illuminated, the shapes of breastplates "
        "and helmets just visible"
    );
    addSomeLightDescriptionTemplate(
        "the armor stand is clearly visible, with polished armor arranged "
        "neatly"
    );
    addAdjectives(({ "wooden", "upright", "empty", "military", "display" }));
    addDescriptionTemplate("a ##Adjective## armor stand for displaying suits of armor");
}
