//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("exterior steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("exterior");
    addAlias("outside");

    addAdjectives(({ "weathered by rain and wind",
        "carved into the natural slope of the hill",
        "with edges softened by years of erosion",
        "that follow the building's outer wall",
        "covered with patches of moss and lichen",
        "showing the effects of countless seasons",
        "that provide access to the main entrance",
        "with iron railings green with age" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " glistening with morning dew",
        " highlighted in the early golden light",
        " emerging from misty shadows",
        " darkened with overnight moisture",
        " catching the first rays of sun",
        " outlined against the lightening sky",
        " with frost patterns on the stone",
        " gleaming wetly in dawn's light",
        " shadowed by the building above",
        " touched by morning's gentle illumination"
        }));

    addTimeOfDayDescription("morning", ({
        " warming in the strengthening sunlight",
        " drying from the previous night's dew",
        " clearly visible in the bright light",
        " casting defined shadows",
        " heated by the climbing sun",
        " revealed in full detail",
        " attracting insects to sun-warmed stone",
        " showing wear patterns clearly",
        " contrasted against the building wall",
        " bright in the morning illumination"
        }));

    addTimeOfDayDescription("noon", ({
        " hot to the touch under direct sun",
        " creating heat shimmer above the stone",
        " almost too bright to look at directly",
        " radiating accumulated solar heat",
        " shadowless in the overhead light",
        " baking in the intense midday sun",
        " uncomfortable to touch without protection",
        " glaring white in full illumination",
        " releasing stored heat as visible waves",
        " stark and harsh in the brilliant light"
        }));

    addTimeOfDayDescription("afternoon", ({
        " casting lengthening shadows",
        " cooler as shadows creep across them",
        " textured by the declining sun angle",
        " warm but no longer scorching",
        " highlighted in golden afternoon light",
        " beginning to release the day's heat",
        " comfortable to walk upon again",
        " rich in color under angled sunlight",
        " creating interesting shadow patterns",
        " gradually cooling as evening approaches"
        }));

    addTimeOfDayDescription("evening", ({
        " bathed in warm golden light",
        " casting dramatic long shadows",
        " cooling rapidly in the evening air",
        " beautiful in the setting sun",
        " glowing amber in the declining light",
        " releasing the day's accumulated warmth",
        " peaceful in the gentle evening glow",
        " softly lit by the western sun",
        " comfortable underfoot once more",
        " tinged with sunset colors"
        }));

    addTimeOfDayDescription("dusk", ({
        " fading into gathering shadows",
        " barely visible in the dim light",
        " cooling quickly as darkness approaches",
        " outlined against the evening sky",
        " merging with the building's silhouette",
        " becoming less distinct in twilight",
        " felt more than seen in fading light",
        " disappearing into the gloom",
        " defined more by touch than sight",
        " shadowy in the dying light"
        }));

    addTimeOfDayDescription("night", ({
        " invisible in the darkness",
        " navigated by feel and memory",
        " cool and damp with night moisture",
        " treacherous without adequate light",
        " felt carefully step by step",
        " dangerous in complete darkness",
        " slippery with forming dew",
        " guided by the building wall",
        " requiring cautious movement",
        " shrouded in nighttime shadows"
        }));

    addTimeOfDayDescription("late night", ({
        " damp with heavy dew formation",
        " slick and potentially hazardous",
        " cold to the touch",
        " requiring extreme caution",
        " treacherous with accumulated moisture",
        " invisible without illumination",
        " guided only by handrail and wall",
        " challenging to navigate safely",
        " wet from condensing night air",
        " hazardous in the deep darkness"
        }));

    addTimeOfDayDescription("midnight", ({
        " slippery with maximum dew",
        " dangerously slick underfoot",
        " invisible in complete darkness",
        " cold and wet from night moisture",
        " requiring utmost caution",
        " treacherous without light",
        " guided only by touch",
        " hazardous even with care",
        " soaked with midnight condensation",
        " perilous in absolute darkness"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " treacherous with ice and snow",
        " slippery from frozen moisture",
        " dangerous with accumulated frost",
        " requiring careful winter navigation",
        " hazardous with seasonal ice",
        " snow-covered and slick",
        " made perilous by winter weather",
        " icy and extremely dangerous",
        " requiring winter footwear for safety",
        " transformed by snow and ice"
        }));

    addSeasonDescription("spring", ({
        " fresh-washed by spring rains",
        " green with new moss growth",
        " clean from winter's melting",
        " renewed by seasonal moisture",
        " brightened by spring cleaning rains",
        " softened by gentle spring weather",
        " refreshed by the changing season",
        " showing new life in the cracks",
        " cleared of winter's debris",
        " revitalized by spring's arrival"
        }));

    addSeasonDescription("summer", ({
        " baking hot in the summer sun",
        " uncomfortable during the heat of day",
        " requiring caution during peak heat",
        " scorching to bare feet or hands",
        " radiating intense summer heat",
        " almost too hot to touch at midday",
        " shimmering with heat waves",
        " best used during cooler hours",
        " dangerously hot during peak sun",
        " requiring protection from heat"
        }));

    addSeasonDescription("autumn", ({
        " slippery with fallen leaves",
        " covered with seasonal debris",
        " made treacherous by wet leaves",
        " hazardous with autumn foliage",
        " requiring careful leaf clearing",
        " beautiful but potentially dangerous",
        " obscured by fallen autumn color",
        " needing regular maintenance",
        " transformed by seasonal change",
        " challenging with leaf accumulation"
        }));

    addDescriptionTemplate("exterior steps ##Adjective## "
        "provide access to the building");
    addSomeLightDescriptionTemplate("exterior steps ##Adjective## "
        "follow the building's exterior");
    addNearDarkDescriptionTemplate("stone steps can be felt "
        "along the exterior wall");
    addLowLightDescriptionTemplate("weathered exterior steps "
        "connect to the building");
    addDimLightDescriptionTemplate("exterior steps ##Adjective## "
        "provide access along the building's face");

    addItemTemplate("The exterior steps bear the full brunt of weather "
        "and time, their surfaces worn smooth by rain, wind, and countless "
        "passages. Moss and lichen have colonized the cracks between stones, "
        "while the constant cycle of freeze and thaw has softened the sharp "
        "edges of the original construction. Iron railings show the green "
        "patina of age, and drainage channels direct water away from the "
        "building foundation.");
}
