//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("beaver dam");
    addAlias("dam");
    addDescriptionTemplate("a low beaver dam across a side channel");
    addNearDarkDescriptionTemplate("a dark tangle at the water's edge");
    addLowLightDescriptionTemplate("a low ridge of branches across the water");
    addDimLightDescriptionTemplate(
        "a beaver dam holding back a quiet pool beside the main channel");
    addSomeLightDescriptionTemplate(
        "a fresh beaver dam diverting a narrow side stream into a pool");
    addItemTemplate("Fresh willow branches are packed with mud along the "
        "shallow channel. The main trail stays dry, while a narrow runnel "
        "below the dam carries clear water toward the lake.");
}
