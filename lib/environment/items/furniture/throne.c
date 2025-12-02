//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("throne");
    addAlias("chair");
    addAlias("seat");
    addAlias("royal seat");

    addAdjectives(({ "imposing", "stone", "ornate", "ancient", "grand",
        "weathered", "carved", "massive" }));

    addDescriptionTemplate("a ##Adjective## throne positioned at the head of the "
        "great hall, a symbol of former authority");

    addItemTemplate("Carved from a single block of granite, the throne features "
        "armrests ending in worn lion heads and a high, decorated back. "
        "The heraldic designs that once adorned this royal seat have been "
        "worn by time but remain faintly visible.");

    addSomeLightDescriptionTemplate("a large stone chair at the north end of "
        "the hall, clearly the seat of power for the castle's former rulers");

    addDimLightDescriptionTemplate("an impressive chair or throne at the head "
        "of the hall, its carved details catching what little light there is");

    addLowLightDescriptionTemplate("a large, ornate seat barely visible at the "
        "far end of the hall");

    addNearDarkDescriptionTemplate("a looming shadow at the head of the hall "
        "that suggests an elevated seat or throne");
}
