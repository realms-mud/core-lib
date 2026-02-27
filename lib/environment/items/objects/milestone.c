//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("milestone");
    addAlias("road marker");
    addAlias("mile marker");
    addAlias("waystone");

    addAdjectives(({ "carved", "weathered", "ancient", "mossy", "leaning",
        "lichen-covered", "worn", "chipped", "granite", "old" }));

    addDescriptionTemplate("a ##Adjective## milestone beside the road");

    addItemTemplate(
        "The milestone is a rough pillar of granite set into the roadside, "
        "its face carved with distances to nearby settlements. The letters "
        "are worn shallow by wind and rain, and lichen fills the grooves. "
        "It leans slightly, the earth beneath it having shifted over the years."
    );

    addSomeLightDescriptionTemplate(
        "a carved milestone stands by the road, its distances just legible"
    );
    addDimLightDescriptionTemplate(
        "a stone pillar by the road appears to be a milestone"
    );
    addLowLightDescriptionTemplate(
        "a short stone pillar stands beside the road"
    );
    addNearDarkDescriptionTemplate(
        "a squat stone shape is barely visible by the road"
    );
}
