//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruined waystation");
    addAlias("waystation");
    addAlias("roadwarden shelter");
    addDescriptionTemplate("the broken stone remains of a road waystation");
    addNearDarkDescriptionTemplate("a low, broken stone structure");
    addLowLightDescriptionTemplate("the outline of a ruined roadside shelter");
    addDimLightDescriptionTemplate(
        "a roofless stone waystation beside the old road");
    addSomeLightDescriptionTemplate(
        "a roofless waystation with a surviving eastern wall");
    addItemTemplate("The old shelter stands just off the trail. Its roof "
        "has fallen in, but a weathered board remains under the eastern "
        "wall, protected from the worst of the rain.");
}
