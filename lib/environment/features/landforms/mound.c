//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mound");
    addAdjectives(({ "distinctive", "artificial-looking", "symmetrical", "ancient", "mysterious", "weathered", "prominent", "earthen" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where early light emphasizes its artificial symmetry, casting long shadows that hint at its purpose",
        " where morning mist clings to its base while the top emerges clear and distinct"
        }));
    addTimeOfDayDescription("morning", ({
        " where sun climbing the eastern sky illuminates one side of the mound while leaving the other in shadow",
        " where dew quickly evaporates from its exposed surface, rising as light vapor in the morning light"
        }));
    addTimeOfDayDescription("noon", ({
        " where midday sun reveals the mound's full form, any patterns or constructions on its surface clearly visible",
        " where its shadow shrinks to a small pool at its base while the summit basks in full light"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the western face catches golden afternoon light while eastern shadows lengthen",
        " where birds of prey sometimes circle above, using thermal currents created by its sun-warmed mass"
        }));
    addTimeOfDayDescription("evening", ({
        " where sunset casts the mound in dramatic relief, accentuating its deliberate shape against the landscape",
        " where the last light creates long shadows that stretch from its base across the surrounding terrain"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the mound's silhouette stands stark against the fading light, an unmistakable presence",
        " where darkness claims it from the ground up, the summit last to surrender to the advancing night"
        }));
    addTimeOfDayDescription("night", ({
        " where moonlight transforms the mound into something otherworldly, its purpose seeming more mysterious",
        " where its dark mass interrupts the star-filled horizon, a sentinel from forgotten times"
        }));
    addTimeOfDayDescription("late night", ({
        " where the mound looms in darkness, somehow more imposing when details are obscured by night",
        " where its presence seems to intensify in the deep quiet, a connection to those who raised it long ago"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the mound stands silent under the stars, keeper of secrets accumulated over centuries",
        " where its form creates a distinct void in the star-field, a piece of earth reaching toward sky"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow smooths its contours without concealing its distinctive shape, emphasizing its permanence",
        " where frost or ice sometimes reveals hidden patterns in its construction not visible in other seasons"
        }));

    addSeasonDescription("spring", ({
        " where new growth clothes the ancient form in fresh green, often with wildflowers in abundance",
        " where birds may nest in its protective sides, adding their songs to its ancient presence"
        }));

    addSeasonDescription("summer", ({
        " where the grass-covered slopes appear most verdant, though patterns of growth often reveal underlying structures",
        " where the heat of day is absorbed by its mass, radiating back well into evening hours"
        }));

    addSeasonDescription("autumn", ({
        " where changing colors highlight its form against the autumnal landscape, a constant amid seasonal change",
        " where fallen leaves sometimes reveal depressions or features hidden by summer's growth"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## mound rising deliberately from the surrounding terrain, its shape suggesting human construction rather than natural formation, covered now in grass and small plants that do not conceal its distinctive profile");
}
