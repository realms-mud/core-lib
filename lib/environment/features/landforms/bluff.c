//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bluff");
    addAdjectives(({ "steep", "rocky", "rugged", "wind-swept" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({ " bathed in the soft glow of the rising sun, casting long shadows across the rugged face of the bluff" }));
    addTimeOfDayDescription("morning", ({ " where the sun rises higher, illuminating the craggy edges and revealing the vast expanse beyond" }));
    addTimeOfDayDescription("noon", ({ " where the sun beats down fiercely, highlighting the harsh, rugged contours of the bluff's rocky surface" }));
    addTimeOfDayDescription("afternoon", ({ " where the fading light of the afternoon softens the sharp edges of the bluff, casting a golden hue" }));
    addTimeOfDayDescription("evening", ({ " where the setting sun paints the bluff in warm tones of orange and red, the long shadows stretching across the land" }));
    addTimeOfDayDescription("dusk", ({ " where the last rays of light flicker and fade, leaving the bluff silhouetted against the dimming sky" }));
    addTimeOfDayDescription("night", ({ " where the bluff is shrouded in the cold, eerie light of the moon, casting long shadows across the valley below" }));
    addTimeOfDayDescription("late night", ({ " where the bluff stands silent and dark under a blanket of stars, the air cool and still" }));
    addTimeOfDayDescription("midnight", ({ " where the moonlight glints off the rough, weathered rocks of the bluff, and a ghostly stillness hangs in the air" }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where the winds howl and the bluff is covered in a dusting of snow, the rocks slick and treacherous",
        " where the cold air bites, and the bluff's jagged edges are lined with frost"
        }));

    addSeasonDescription("spring", ({
        " where small wildflowers bloom at the base of the bluff, and the air is fresh with new growth",
        " where the cliffs are speckled with patches of green moss, and the land begins to thaw and breathe again"
        }));

    addSeasonDescription("summer", ({
        " where the heat of the day radiates off the rocky surface, the air shimmering with heat waves",
        " where the cliffside is dry and sun-baked, the rocks slick with sweat from the heat"
        }));

    addSeasonDescription("autumn", ({
        " where leaves from the trees far below drift in the wind, landing in small piles at the foot of the bluff",
        " where the air turns crisp and the landscape is ablaze with the reds, oranges, and yellows of fall"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## bluff with a sharp drop and a sweeping view of the land below");
}
