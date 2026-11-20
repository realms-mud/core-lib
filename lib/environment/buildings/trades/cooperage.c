//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cooperage");
    setFloorPlanType("trade");

    addAdjectives(({ "timber", "low", "weathered", "busy", "well-used" }));
    addDescriptionTemplate(
        "a ##Adjective## cooperage with tall double doors and open shutters");
    addNearDarkDescriptionTemplate(
        "a low timber cooperage with shadowed double doors");
    addLowLightDescriptionTemplate(
        "a weathered cooperage with open shutters");
    addDimLightDescriptionTemplate(
        "a timber cooperage with hoops stacked beside its doors");
    addSomeLightDescriptionTemplate(
        "a busy cooperage with tall doors and a workbench visible within");
    addItemTemplate(
        "The low building is made for shaping staves and binding casks. "
        "Its tall doors leave room for a barrel on a hand-cart, while "
        "the open shutters carry the sound of mallets into the lane.");
}
