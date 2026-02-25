//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("weaponsmith interior");

    addItemTemplate(
        "The weaponsmith's shop is a purposeful space where every surface "
        "speaks of martial craft. Display racks along the walls hold an "
        "impressive array of weapons - maces, spears, war hammers, and "
        "short swords - each polished and ready for sale. A heavy grinding "
        "wheel sits in one corner, its trough dark with water and metal "
        "filings. Behind the counter, a pegboard displays hilts, pommels, "
        "and crossguards in various stages of assembly. The back wall opens "
        "into a workshop where a small forge glows, and the mingled scent "
        "of oil, steel, and fresh leather wrappings fills the air."
    );

    addNearDarkDescriptionTemplate(
        "the weaponsmith's shop is cloaked in darkness, the faint glow from "
        "the back forge barely catching the edges of blades on the racks"
    );
    addLowLightDescriptionTemplate(
        "the weapons on display are dark silhouettes against the walls, "
        "the occasional glint of an edge the only hint of their nature"
    );
    addDimLightDescriptionTemplate(
        "dim light reveals the outlines of weapons on their racks and the "
        "grinding wheel in the corner, the forge glowing faintly beyond"
    );
    addSomeLightDescriptionTemplate(
        "the weaponsmith's shop is bright enough to appreciate the variety "
        "of arms on display and the craftsmanship of each piece"
    );
    addDescriptionTemplate(
        "light gleams along every blade and polished haft in the "
        "weaponsmith's shop, the steel practically singing with readiness"
    );
}
