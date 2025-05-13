//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cliff");
    addAdjectives(({ "steep", "jagged", "towering", "breathtaking" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({ " bathed in the soft pink and orange hues of the rising sun, the cliffs casting long, dramatic shadows over the valley below" }));
    addTimeOfDayDescription("dusk", ({ " where the last fading light of the day clings to the jagged edges, casting long shadows over the steep drop" }));
    addTimeOfDayDescription("night", ({ " outlined in the cold silver light of the moon, casting a dark, looming presence against the starlit sky" }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where the cliffs are dusted with a light layer of snow, and the cold wind howls through the jagged rocks",
        " where the wind bites, and the cliffside is slick with ice, dangerous to approach"
        }));

    addSeasonDescription("spring", ({
        " where patches of green moss and small wildflowers begin to bloom along the base",
        " where the cliffs are speckled with new growth, vibrant greens contrasting against the rocky surface"
        }));

    addSeasonDescription("summer", ({
        " where the sun beats down on the rocky face, creating shimmering heat waves rising from the steep slope",
        " where the cliffs are dry and sun-baked, with only sparse vegetation clinging to the rock"
        }));

    addSeasonDescription("autumn", ({
        " where golden leaves flutter in the wind and fall over the edge, creating a blanket of colors on the ground below",
        " where the cliffs are framed by vibrant autumn leaves, the air crisp and cool as the season turns"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## cliff, rising steeply with jagged edges and a breathtaking view of the land below");
}
