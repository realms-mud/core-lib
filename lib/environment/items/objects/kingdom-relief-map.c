//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("kingdom relief map");
    addAlias("map of Eledhel");
    addAlias("citadel map");
    addAlias("war map");

    addAdjectives(({ "huge", "carved", "painted", "detailed" }));

    addDescriptionTemplate(
        "a ##Adjective## relief map of Eledhel and the surrounding lands");
    addItemTemplate(
        "The entire north wall is covered by a relief map of Eledhel and "
        "its neighbors. Named citadels are mounted on brass pivots; "
        "fine scratches circle their edges, and a shallow finger groove "
        "runs from one fortress to the next. The Eledhel marker is set "
        "slightly proud of the map."
    );

    addSomeLightDescriptionTemplate(
        "a great relief map with six citadels set on turning pivots");
    addDimLightDescriptionTemplate(
        "a painted map covering the north wall");
    addLowLightDescriptionTemplate(
        "a broad shape on the north wall, marked with metal points");
    addNearDarkDescriptionTemplate(
        "a faint outline across the north wall");
}
