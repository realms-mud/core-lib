//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sinkhole");
    addAdjectives(({ "ominous", "unexpected", "yawning", "circular", "sudden",
        "mysterious", "deep", "collapsed", "treacherous", "dark" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where early light barely penetrates the depths, revealing only the upper "
        "portion while the bottom remains shrouded in profound shadow",
        " where mist often rises from the depression, creating an eerie atmosphere "
        "as first light catches the vapor without illuminating its source"
        }));
    addTimeOfDayDescription("morning", ({
        " where the sun gradually illuminates one side of the circular depression "
        "while the other remains in shadow, emphasizing its unsettling depth",
        " where birds circle above the opening, their calls echoing strangely "
        "from the stone walls of this unexpected interruption in the landscape"
        }));
    addTimeOfDayDescription("noon", ({
        " where even direct overhead sunlight fails to fully illuminate the deepest "
        "recesses, creating an impression of unknowable depth",
        " where the temperature drops noticeably at the edge, cool air rising "
        "from the shadowed interior even on the warmest days"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the angle of light creates dramatic shadows within the depression, "
        "revealing textures and features invisible at other times",
        " where the sinkhole's presence becomes a stark reminder of the hidden "
        "hollow spaces beneath the apparently solid ground"
        }));
    addTimeOfDayDescription("evening", ({
        " where fading light retreats up the walls of the depression, leaving "
        "the interior in darkness long before sunset claims the surrounding land",
        " where the temperature differential becomes most pronounced, cool air "
        "flowing outward from the darkened void like a silent waterfall"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the circular opening becomes a pool of absolute darkness, its "
        "edges still faintly visible while its depth is lost to night",
        " where the transition between day and night seems accelerated within "
        "the depression, darkness rising from below like a tide"
        }));
    addTimeOfDayDescription("night", ({
        " where the sinkhole becomes a void darker than the night sky, stars "
        "reflected in no pool at its base, light simply swallowed",
        " where the opening seems most ominous, a perfect circle of deeper "
        "blackness that suggests connection to places without light"
        }));
    addTimeOfDayDescription("late night", ({
        " where the difference between the night sky above and the absolute darkness "
        "of the depression creates a disorienting sense of infinite depth",
        " where strange echoes sometimes emerge from the depths, distorted sounds "
        "that might be water, wind, or something moving in darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the deepest night cannot compete with the more profound darkness "
        "of the sinkhole, a void that seems to draw in light and sound",
        " where standing at the edge creates a primal sense of boundary between "
        "known world and subterranean mystery at its most potent"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow creates a deceptive rim around the opening, sometimes bridging "
        "small sections with dangerous cornices that conceal the edge",
        " where ice forms fantastic structures around seeps and drips within the "
        "walls, creating a frozen wonderland rarely seen by living eyes"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt and rain increase any water flow within the depression, "
        "sometimes creating audible streams or falls deeper within",
        " where hardy plants cling to the upper edges and rare species adapted to "
        "low light may flower unseen on ledges within the sheltered interior"
        }));

    addSeasonDescription("summer", ({
        " where the cool air emanating from the depression provides natural "
        "relief from summer heat, though few dare venture too near the edge",
        " where the temperature differential between surface and depths is most "
        "pronounced, sometimes creating visible condensation or mist"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect around the rim and occasionally spiral down "
        "into the darkness, never making an audible sound of landing",
        " where early morning often finds the opening filled with mist that spills "
        "over the edges, marking the sinkhole's presence from a distance"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## sinkhole where the ground has collapsed to reveal a roughly circular opening of uncertain depth, its walls showing layers of earth and stone where the surface has given way to some hidden cavity below");
}
