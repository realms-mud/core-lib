//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("town");

    addAdjectives(({
        "bustling town with timbered houses and cobbled streets",
        "town where smoke rises from stone chimneys",
        "town square surrounded by shops and homes",
        "busy town with merchants hawking wares",
        "quiet town where children play in the lanes",
        "town where the scent of bread and woodsmoke fills the air",
        "cluster of homes and workshops with gardens and livestock",
        "town where townsfolk gather at the well",
        "peaceful town nestled among rolling hills",
        "town where the church bell marks the hours"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the golden light of sunrise",
        " where townsfolk begin their daily chores",
        " as the town slowly comes to life"
        }));

    addTimeOfDayDescription("morning", ({
        " alive with the bustle of market and townsfolk",
        " as the sun rises over the rooftops",
        " where the air is filled with the sounds of animals and people"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where townsfolk gather in the shade to rest",
        " as the market is at its busiest"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the town square",
        " with long shadows stretching over the cobbles",
        " where the air is filled with laughter and conversation"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as townsfolk return home for supper",
        " where the scent of cooking drifts through the air"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the glow of hearth fires",
        " where the town is quiet and peaceful",
        " as lanterns flicker in the windows"
        }));

    addSeasonDescription("winter", ({
        " with snow blanketing the rooftops and smoke curling from chimneys",
        " where townsfolk huddle indoors against the cold"
        }));

    addSeasonDescription("spring", ({
        " with gardens bursting into bloom",
        " as lambs and calves are born in the fields"
        }));

    addSeasonDescription("summer", ({
        " at its busiest, with fields green and full of life",
        " where the days are long and the air is warm"
        }));

    addSeasonDescription("autumn", ({
        " golden with ripening grain and falling leaves",
        " as townsfolk prepare for the coming winter"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy town where only the glow of windows reveals its presence");
    addLowLightDescriptionTemplate("a barely-lit town where buildings are little more than shapes in the gloom");
    addDimLightDescriptionTemplate("a dimly-lit town where the lanes are painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit town where every house and street is clear");
}
