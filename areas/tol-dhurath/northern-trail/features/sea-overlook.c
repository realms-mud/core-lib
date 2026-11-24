//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sea overlook");
    addAlias("overlook");
    addAlias("lookout");
    addDescriptionTemplate("a rocky overlook above the northern woods");
    addNearDarkDescriptionTemplate("a sheer edge beyond the trees");
    addLowLightDescriptionTemplate(
        "a rocky ledge overlooking the dark woodland");
    addDimLightDescriptionTemplate(
        "a break in the trees with a distant view toward the sea");
    addSomeLightDescriptionTemplate(
        "a high rocky ledge with a view toward the northern sea");
    addItemTemplate("The trees thin at the edge of a rocky shelf. On a "
        "clear day, the sea is visible beyond the northern ridges.");
}
