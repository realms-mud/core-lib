//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruined relay tower");
    addAlias("tower");
    addAlias("ruins");
    addDescriptionTemplate("the low remains of an old coastal relay tower");
    addItemTemplate("Broken walls enclose the old watch platform. "
        "A cleared cellar approach lies below, while the unsafe "
        "upper stair remains blocked. Simple masonry and worn "
        "repair marks show a working relay, not a royal residence.");
    addNearDarkDescriptionTemplate("a broken silhouette");
    addLowLightDescriptionTemplate("low ruined walls");
    addDimLightDescriptionTemplate("the remains of a small watchtower");
    addSomeLightDescriptionTemplate("a ruined relay tower with a cleared cellar");
    addTimeOfDayDescription("dawn", ({ " outlined against the pale sky" }));
    addTimeOfDayDescription("morning", ({ " revealing weathered repair seams" }));
    addTimeOfDayDescription("noon", ({ " casting short shadows inside its walls" }));
    addTimeOfDayDescription("afternoon", ({ " shaded beneath the broken stair" }));
    addTimeOfDayDescription("evening", ({ " darkening above the old road" }));
    addTimeOfDayDescription("dusk", ({ " a ragged shape against the sky" }));
    addTimeOfDayDescription("night", ({ " quiet above the path" }));
    addTimeOfDayDescription("midnight", ({ " silent beneath the night sky" }));
    addSeasonDescription("spring", ({ " with grass growing between its stones" }));
    addSeasonDescription("summer", ({ " warm on its exposed masonry" }));
    addSeasonDescription("autumn", ({ " catching leaves in its courtyard" }));
    addSeasonDescription("winter", ({ " dusted with snow along its broken walls" }));
}
