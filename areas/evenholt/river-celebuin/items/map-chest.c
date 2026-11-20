//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("map chest");
    addAlias("chest");
    addAlias("map cache");
    addAdjectives(({ "medium", "wooden", "brush-hidden", "plain" }));
    addDescriptionTemplate("a ##Adjective## chest at the base of the rock");
    addItemTemplate("A medium chest rests beneath the stone ledge. "
        "The lid is closed; a small hole in its front and a fine seam "
        "around the catch betray a concealed dart mechanism. Maps are "
        "packed inside beneath an oilcloth.");
    addSomeLightDescriptionTemplate(
        "a medium chest rests beneath the stone ledge");
    addDimLightDescriptionTemplate(
        "a low chest is tucked under the rock ledge");
}

/////////////////////////////////////////////////////////////////////////////
public int canGet(object target)
{
    return 0;
}
