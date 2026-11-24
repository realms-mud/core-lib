//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("roadside shrine");
    addAlias("wayfarer's shrine");
    addAlias("slate shrine");
    addDescriptionTemplate("a low roadside shrine set beneath an oak");
    addNearDarkDescriptionTemplate("a low stone niche at the path's edge");
    addLowLightDescriptionTemplate("a small shrine with a hooded lantern");
    addDimLightDescriptionTemplate("a slate niche with offerings");
    addSomeLightDescriptionTemplate("a cared-for shrine beside the road");
    addItemTemplate("The slate niche holds a few small offerings: a "
        "carved wooden horse, a twist of barley, and a smooth blue stone. "
        "Someone has swept the path and replaced the lantern's wick. A "
        "weathered board asks travelers to leave the offerings where "
        "others can see them.");
}
