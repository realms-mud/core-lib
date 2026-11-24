//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone drainage channel");
    addAlias("drainage channel");
    addAlias("gutter");
    addAlias("runoff channel");

    addDescriptionTemplate("a narrow stone drainage channel");
    addItemTemplate(
        "The channel is cut into the fitted floor blocks to carry seepage "
        "and runoff toward the cisterns. Its edges are smooth from years "
        "of water and maintenance."
    );

    addNearDarkDescriptionTemplate(
        "a shallow groove cut along the floor");
    addLowLightDescriptionTemplate(
        "a narrow channel in the stone floor");
    addDimLightDescriptionTemplate(
        "a fitted drainage channel running beside the passage");
    addSomeLightDescriptionTemplate(
        "a narrow stone channel directing water through the tunnel");
}
