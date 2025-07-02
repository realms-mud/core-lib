//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("knoll");
    addAdjectives(({ "small", "rounded", "grassy", "gentle", "tree-crowned",
        "peaceful", "modest", "quiet", "pastoral", "secluded" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " peaceful in morning light",
        " gentle in dawn's glow",
        " rounded in early illumination",
        " grassy with morning dew",
        " small in modest beauty",
        " tree-crowned in dawn quiet",
        " quiet in morning stillness",
        " pastoral in dawn peace",
        " modest in gentle light",
        " secluded in morning calm"
        }));

    addTimeOfDayDescription("morning", ({
        " bright in morning sunshine",
        " gentle in warming light",
        " rounded in clear visibility",
        " grassy in morning freshness",
        " small in perfect proportion",
        " tree-crowned in morning glory",
        " quiet in morning peace",
        " pastoral in morning beauty",
        " modest in daylight charm",
        " secluded in morning tranquility"
        }));

    addTimeOfDayDescription("noon", ({
        " warm in midday sunshine",
        " gentle in bright light",
        " rounded in full visibility",
        " grassy in noon abundance",
        " small in perfect clarity",
        " tree-crowned in full glory",
        " quiet in midday stillness",
        " pastoral in noon beauty",
        " modest in bright charm",
        " secluded in midday peace"
        }));

    addTimeOfDayDescription("afternoon", ({
        " golden in afternoon light",
        " gentle in warm illumination",
        " rounded in textured light",
        " grassy in afternoon warmth",
        " small in perfect beauty",
        " tree-crowned in golden glory",
        " quiet in afternoon peace",
        " pastoral in golden hour",
        " modest in warm charm",
        " secluded in afternoon calm"
        }));

    addTimeOfDayDescription("evening", ({
        " beautiful in evening glow",
        " gentle in alpenglow",
        " rounded in soft light",
        " grassy in cooling air",
        " small in evening beauty",
        " tree-crowned in sunset glory",
        " quiet in evening peace",
        " pastoral in twilight beauty",
        " modest in evening charm",
        " secluded in evening calm"
        }));

    addTimeOfDayDescription("dusk", ({
        " peaceful in gathering twilight",
        " gentle in fading light",
        " rounded in soft outline",
        " grassy in evening shadow",
        " small in twilight beauty",
        " tree-crowned in dusk silhouette",
        " quiet in evening stillness",
        " pastoral in twilight peace",
        " modest in fading charm",
        " secluded in gathering gloom"
        }));

    addTimeOfDayDescription("night", ({
        " serene in moonlight",
        " gentle under stars",
        " rounded in lunar glow",
        " grassy in night dew",
        " small in night beauty",
        " tree-crowned in stellar glory",
        " quiet in night stillness",
        " pastoral in night peace",
        " modest in lunar charm",
        " secluded in night tranquility"
        }));

    addTimeOfDayDescription("late night", ({
        " peaceful in deep night",
        " gentle in night silence",
        " rounded in felt presence",
        " grassy in night moisture",
        " small in night serenity",
        " tree-crowned in night mystery",
        " quiet in deep stillness",
        " pastoral in night beauty",
        " modest in night charm",
        " secluded in deep tranquility"
        }));

    addTimeOfDayDescription("midnight", ({
        " serene under starfield",
        " gentle in cosmic peace",
        " rounded in stellar outline",
        " grassy in midnight dew",
        " small in cosmic beauty",
        " tree-crowned under cosmos",
        " quiet in absolute stillness",
        " pastoral in midnight peace",
        " modest in stellar charm",
        " secluded in cosmic tranquility"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " peaceful under snow",
        " gentle in winter beauty",
        " rounded in white outline",
        " grassy beneath snow cover",
        " small in winter charm",
        " tree-crowned in winter glory",
        " quiet in winter stillness",
        " pastoral in winter peace",
        " modest in winter beauty",
        " secluded in winter tranquility"
        }));

    addSeasonDescription("spring", ({
        " fresh with new growth",
        " gentle in spring awakening",
        " rounded in spring clarity",
        " grassy with spring green",
        " small in spring beauty",
        " tree-crowned in spring glory",
        " quiet in spring peace",
        " pastoral in spring renewal",
        " modest in spring charm",
        " secluded in spring tranquility"
        }));

    addSeasonDescription("summer", ({
        " lush in summer abundance",
        " gentle in summer warmth",
        " rounded in summer clarity",
        " grassy in full growth",
        " small in summer perfection",
        " tree-crowned in summer glory",
        " quiet in summer peace",
        " pastoral in summer beauty",
        " modest in summer charm",
        " secluded in summer tranquility"
        }));

    addSeasonDescription("autumn", ({
        " colorful in autumn beauty",
        " gentle in autumn peace",
        " rounded in autumn clarity",
        " grassy in seasonal change",
        " small in autumn perfection",
        " tree-crowned in autumn glory",
        " quiet in autumn stillness",
        " pastoral in autumn beauty",
        " modest in autumn charm",
        " secluded in autumn tranquility"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## knoll rising gently as a "
        "small rounded hill");

    addItemTemplate("The knoll forms a small, rounded elevation that rises "
        "modestly from the surrounding landscape. Its gentle slopes and "
        "manageable size create an inviting feature that often serves as "
        "a natural gathering place or viewpoint. Grasses typically cover "
        "its surface, while trees may crown its summit, providing shade "
        "and visual interest. The knoll's modest scale makes it accessible "
        "and non-threatening, often becoming a focal point for pastoral "
        "activities or simply a peaceful spot to rest and enjoy views of "
        "the surrounding countryside.");
}
