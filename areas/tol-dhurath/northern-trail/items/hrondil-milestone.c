//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("old road milestone");
    addAlias("milestone");
    addAlias("road marker");
    addAlias("waystone");
    addAdjectives(({ "weathered", "lichen-covered", "worn", "leaning" }));
    addDescriptionTemplate("a weathered milestone beside the trail");
    addItemTemplate("The worn carving names Hrondil to the west and "
        "Tol-Dhurath to the south. The letters have nearly vanished, but "
        "the old road distances can still be made out in clear light.");
    addSomeLightDescriptionTemplate(
        "a leaning stone marked for Hrondil and Tol-Dhurath");
    addDimLightDescriptionTemplate(
        "a lichen-covered milestone stands beside the trail");
    addLowLightDescriptionTemplate("a short stone marker beside the trail");
    addNearDarkDescriptionTemplate("a squat shape at the road's edge");
}
