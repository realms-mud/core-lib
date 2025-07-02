//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hollow");
    addAdjectives(({ "secluded", "sheltered", "damp", "cool", "lush", "hidden",
        "quiet", "shadowy" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " pooled with lingering mist",
        " shadowed while rim catches light",
        " outlined in golden dawn",
        " mysterious in vapor",
        " cool with accumulated moisture",
        " hidden in morning fog",
        " quiet in dawn stillness",
        " sheltered from early wind",
        " damp with overnight dew",
        " secluded in morning peace"
        }));

    addTimeOfDayDescription("morning", ({
        " gradually penetrated by sunlight",
        " echoing with birdsong",
        " revealed with dew-laden vegetation",
        " cool in morning shelter",
        " lush in morning moisture",
        " hidden in natural amphitheater",
        " quiet in morning calm",
        " sheltered from morning breeze",
        " damp with morning freshness",
        " secluded in gentle light"
        }));

    addTimeOfDayDescription("noon", ({
        " sheltered from wind",
        " cooler than surrounding land",
        " humid in natural shelter",
        " lush in protected growth",
        " hidden in depression depths",
        " quiet in midday stillness",
        " damp despite noon sun",
        " secluded in natural basin",
        " shadowy in deeper sections",
        " cool in protected microclimate"
        }));

    addTimeOfDayDescription("afternoon", ({
        " shadowed earlier than surroundings",
        " moist with accumulated humidity",
        " lush with different vegetation",
        " hidden in natural protection",
        " quiet in afternoon peace",
        " cool in sheltered basin",
        " damp with retained moisture",
        " secluded from afternoon heat",
        " shadowy in declining light",
        " sheltered from afternoon sun"
        }));

    addTimeOfDayDescription("evening", ({
        " dark while rim catches light",
        " misty in cooling air",
        " hidden in early darkness",
        " quiet in evening shelter",
        " cool with condensing moisture",
        " damp in evening air",
        " secluded in gathering shadow",
        " shadowy in deep depression",
        " sheltered from evening wind",
        " lush in evening moisture"
        }));

    addTimeOfDayDescription("dusk", ({
        " shrouded in early night",
        " outlined briefly against sky",
        " hidden in gathering gloom",
        " quiet in dusk stillness",
        " cool in settling air",
        " damp with evening mist",
        " secluded in twilight shadow",
        " shadowy in deepening dark",
        " sheltered from dusk wind",
        " mysterious in fading light"
        }));

    addTimeOfDayDescription("night", ({
        " pooled with deeper darkness",
        " misty across lowest points",
        " hidden in night shadow",
        " quiet with dampened sounds",
        " cool with settled air",
        " damp with night moisture",
        " secluded in night depths",
        " shadowy in complete darkness",
        " sheltered from night wind",
        " lush in night humidity"
        }));

    addTimeOfDayDescription("late night", ({
        " enclosed beneath night sky",
        " protected for nocturnal hunters",
        " hidden in intimate darkness",
        " quiet in sheltered vegetation",
        " cool with heavy air",
        " damp with accumulated moisture",
        " secluded in night peace",
        " shadowy in deep night",
        " sheltered from night elements",
        " lush in night protection"
        }));

    addTimeOfDayDescription("midnight", ({
        " void in deeper black",
        " quiet with muffled sounds",
        " hidden in complete darkness",
        " cool with midnight air",
        " damp with maximum moisture",
        " secluded in midnight peace",
        " shadowy in absolute dark",
        " sheltered from midnight wind",
        " lush in midnight humidity",
        " mysterious in cosmic shadow"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " frosted longer than exposed areas",
        " snow-filled in deeper collection",
        " hidden beneath white surface",
        " cool with winter protection",
        " quiet in winter stillness",
        " sheltered from winter wind",
        " damp despite freezing",
        " secluded in winter peace",
        " shadowy in winter light",
        " lush beneath snow cover"
        }));

    addSeasonDescription("spring", ({
        " pooled with snowmelt",
        " lush with early protection",
        " hidden in spring growth",
        " cool with spring shelter",
        " quiet with spring life",
        " sheltered from spring storms",
        " damp with spring moisture",
        " secluded in spring renewal",
        " shadowy in spring foliage",
        " protected from late frosts"
        }));

    addSeasonDescription("summer", ({
        " cooler than surrounding terrain",
        " lush in sheltered conditions",
        " hidden in dense growth",
        " cool in summer protection",
        " quiet in summer stillness",
        " sheltered from summer heat",
        " damp in summer humidity",
        " secluded in summer growth",
        " shadowy in summer foliage",
        " oasis-like in summer"
        }));

    addSeasonDescription("autumn", ({
        " drifted with collected leaves",
        " mild longer than rim",
        " hidden in autumn mulch",
        " cool with autumn air",
        " quiet in autumn peace",
        " sheltered from autumn wind",
        " damp with autumn moisture",
        " secluded in autumn beauty",
        " shadowy in autumn light",
        " lush despite seasonal change"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## hollow forming a natural "
        "depression with sheltered conditions");

    addItemTemplate("The hollow forms a natural depression in the landscape "
        "where the ground dips to create a sheltered basin. This protected "
        "environment often supports vegetation different from the surrounding "
        "terrain, with cooler temperatures and higher humidity creating a "
        "distinct microclimate. Water may collect in the lowest points during "
        "wet seasons, while the sloping sides provide shelter from wind and "
        "weather. The hollow's enclosed nature makes it feel separate from "
        "the surrounding landscape, a hidden pocket of different conditions.");
}
