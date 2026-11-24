//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("muddy hoofprints");
    addAlias("hoofprints");
    addAlias("cart tracks");
    addAdjectives(({ "deep", "fresh", "muddy", "overlapping" }));
    addDescriptionTemplate("##Adjective## hoofprints in the track");
    addNearDarkDescriptionTemplate("a churned patch of road mud");
    addLowLightDescriptionTemplate("deep prints beside the track");
    addDimLightDescriptionTemplate(
        "hoofprints pressed into the wet slope");
    addSomeLightDescriptionTemplate(
        "fresh hoofprints and a cart rut climbing toward the mill");
    addItemTemplate("The heavier set of prints belongs to a shod "
        "draft horse. A lighter set doubles back down the slope. "
        "The cart rut is narrow enough for a miller's handcart, "
        "not a merchant wagon.");
}
