//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hummock");
    addAdjectives(({ "mossy", "irregular", "lumpy", "damp", "low", "tussocky", "raised", "earthy" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where early mist clings to its irregular surface, droplets of dew hanging heavily from every stem",
        " where the first light reveals the intricate textures of moss and grass forming its small rise"
        }));
    addTimeOfDayDescription("morning", ({
        " where the morning sun begins to dry the dew-drenched vegetation covering its uneven surface",
        " where small insects stir to life across its miniature ecosystem as warmth returns"
        }));
    addTimeOfDayDescription("noon", ({
        " where sunlight penetrates the dense vegetation, warming the damp earth beneath its tangled growth",
        " where shadows are minimal, revealing every bump and depression across its lumpy profile"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the low mound absorbs the day's accumulated warmth, creating its own microclimate",
        " where small creatures find shelter among its twisted roots and dense vegetation"
        }));
    addTimeOfDayDescription("evening", ({
        " where cooling air causes moisture to condense once more across its moss-covered surface",
        " where the hummock's shadow stretches disproportionately long compared to its modest height"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the failing light blends its irregular outline into the gathering darkness",
        " where night-active insects begin to emerge from the protection of its dense growth"
        }));
    addTimeOfDayDescription("night", ({
        " where the small rise remains as a barely perceptible mound in the darkness",
        " where dew forms heavily on its surface, preparing to make it glisten at dawn"
        }));
    addTimeOfDayDescription("late night", ({
        " where the hummock becomes nearly invisible, betrayed only by the different texture underfoot",
        " where the dense vegetation holds warmth longer than the surrounding ground in the cool night"
        }));
    addTimeOfDayDescription("midnight", ({
        " where nocturnal life moves secretly through its protective cover, unseen in the darkness",
        " where the raised earth stands as a subtle guardian of moisture and life in the midnight hours"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where frost forms intricate patterns across its mossy surface, or snow caps its irregular top",
        " where the hummock provides rare shelter when other vegetation has died back for the season"
        }));

    addSeasonDescription("spring", ({
        " where new growth erupts with particular vigor, fed by the nutrients and moisture it has preserved",
        " where tiny flowers appear amid the moss and grass, transforming the small rise with color"
        }));

    addSeasonDescription("summer", ({
        " where the dense vegetation becomes a haven for countless tiny creatures escaping the summer heat",
        " where the contrast deepens between its perpetual dampness and the drier surrounding land"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves collect against its sides, beginning their transformation into future soil",
        " where fungi often appear, their caps and stems rising from its nutrient-rich earth"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## hummock, a small raised mound of earth and vegetation, often damper than surrounding terrain and covered in dense growth of moss, grass, and small plants forming a miniature ecosystem");
}
