//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("village");

    addAdjectives(({
        "village with thatched cottages and cobbled lanes",
        "small village where smoke rises from stone chimneys",
        "village green surrounded by timber-framed houses",
        "bustling village with a central well and market stalls",
        "quiet village where chickens peck in the dust",
        "village where children play and elders gossip",
        "cluster of homes with gardens and livestock",
        "village where the scent of baking bread fills the air",
        "peaceful village nestled among rolling hills",
        "village where the church bell marks the hours"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the golden light of sunrise",
        " where villagers begin their daily chores",
        " as the village slowly comes to life"
        }));

    addTimeOfDayDescription("morning", ({
        " alive with the bustle of market and farmhands",
        " as the sun rises over the rooftops",
        " where the air is filled with the sounds of animals and people"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where villagers gather in the shade to rest",
        " as the market is at its busiest"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the village green",
        " with long shadows stretching over the cottages",
        " where the air is filled with laughter and conversation"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as villagers return home for supper",
        " where the scent of cooking drifts through the air"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the glow of hearth fires",
        " where the village is quiet and peaceful",
        " as lanterns flicker in the windows"
        }));

    addSeasonDescription("winter", ({
        " with snow blanketing the rooftops and smoke curling from chimneys",
        " where villagers huddle indoors against the cold"
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
        " as villagers prepare for the coming winter"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy village where only the glow of windows reveals its presence");
    addLowLightDescriptionTemplate("a barely-lit village where cottages are little more than shapes in the gloom");
    addDimLightDescriptionTemplate("a dimly-lit village where the lanes are painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit village where every house and garden is clear");
}
