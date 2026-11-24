//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cistern hand pump");
    addAlias("hand pump");
    addAlias("pump");
    addAdjectives(({ "iron", "worn", "rusted", "well-kept", "old" }));

    addDescriptionTemplate(
        "an ##Adjective## hand pump fixed above a stone cistern");
    addItemTemplate(
        "The iron pump is bolted into a stone cistern head. Its handle "
        "moves with a heavy, familiar stroke, drawing water from a pipe "
        "that disappears into the city foundations."
    );

    addSomeLightDescriptionTemplate(
        "an iron hand pump fixed above a stone cistern");
    addDimLightDescriptionTemplate(
        "a hand pump mounted on a stone cistern");
    addLowLightDescriptionTemplate(
        "a squat pump above a cistern");
    addNearDarkDescriptionTemplate(
        "a low shape above the floor");
}
