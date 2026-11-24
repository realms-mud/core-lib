//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("field stretcher");
    addAlias("stretcher");
    addAlias("bier");
    addAdjectives(({ "canvas", "folding", "field", "worn", "wooden" }));

    addDescriptionTemplate(
        "a ##Adjective## stretcher set against the cavern wall");
    addItemTemplate(
        "Two ash poles are joined by a broad canvas sling, stained by "
        "mud and old use. It can carry an injured traveler through the "
        "level passages, but is too wide for the steep climb ahead."
    );

    addSomeLightDescriptionTemplate(
        "a canvas field stretcher rests against the wall");
    addDimLightDescriptionTemplate(
        "a pair of poles joined by a dark canvas sling");
    addLowLightDescriptionTemplate(
        "a long, low shape rests beside the passage");
    addNearDarkDescriptionTemplate(
        "two parallel shapes lie against the cavern wall");
}
