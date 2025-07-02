//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("path");
    addAdjectives(({ "narrow", "winding", "well-trodden", "dusty", "packed-earth",
        "meandering", "simple", "well-used", "irregular", "modest" }));

    // Time of Day Descriptions (terrain/weather agnostic)
    addTimeOfDayDescription("dawn", ({
        "faintly visible in the low light of dawn",
        "emerging from the dimness as day begins"
        }));
    addTimeOfDayDescription("morning", ({
        "easy to follow in the morning light",
        "outlined softly as the day brightens"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly defined in the full light of day",
        "warm and dry under the midday sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with shadows stretching across its length",
        "quiet as the day grows warm"
        }));
    addTimeOfDayDescription("evening", ({
        "bathed in golden light as the sun sets",
        "becoming less distinct as evening falls"
        }));
    addTimeOfDayDescription("dusk", ({
        "blending into the dimness at dusk",
        "barely discernible as daylight wanes"
        }));
    addTimeOfDayDescription("night", ({
        "dark and quiet in the night",
        "barely visible in the darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        "almost lost in the deep midnight shadows",
        "present only as a faint outline"
        }));

    // Season Descriptions (terrain/weather agnostic)
    addSeasonDescription("winter", ({
        "sometimes dusted with snow",
        "edges blurred by frost"
        }));
    addSeasonDescription("spring", ({
        "soft with recent rain",
        "firm as the season turns"
        }));
    addSeasonDescription("summer", ({
        "dry and firm underfoot",
        "well-defined in the summer light"
        }));
    addSeasonDescription("autumn", ({
        "edges softened by fallen leaves",
        "firm as the season cools"
        }));

    addAlias("trail");
    addAlias("track");

    addDescriptionTemplate("a ##Adjective## path winding through the area");

    addItemTemplate("The path forms a narrow corridor, its surface worn by many travelers. "
        "It winds through the landscape, following the path of least resistance. "
        "The ground is compacted and clear of obstacles, showing the marks of countless journeys.");
}
