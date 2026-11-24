//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("old gallows");
    addAlias("gallows");
    addAlias("gallows frame");
    addDescriptionTemplate("an empty gallows frame on a low hill");
    addNearDarkDescriptionTemplate("a dark wooden frame above the path");
    addLowLightDescriptionTemplate("an old gallows with no rope");
    addDimLightDescriptionTemplate("an empty timber frame on the hill");
    addSomeLightDescriptionTemplate("the weathered frame of old gallows");
    addItemTemplate("The frame has been left to weather, its beam "
        "cracked and its ladder removed. No rope hangs from it. A flat "
        "stone at the foot bears the names of two watchmen and a date; "
        "the inscription calls this a warning, not a place of justice.");
}
