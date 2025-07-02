//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bridge steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("bridge");

    addAdjectives(({ "that provide access to the bridge's elevated span",
        "carved into the bridge's supporting arches",
        "with handholds carved into the stonework",
        "that connect to the bridge's walkway",
        "built into the massive stone abutments",
        "showing wear from travelers and guards",
        "that wind around the bridge's supporting pillars",
        "designed for both access and defense" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " gleaming with river mist and dew",
        " emerging from morning fog",
        " wet from overnight condensation",
        " highlighted by early sun",
        " touched by golden dawn light",
        " slippery with morning moisture",
        " outlined against the lightening water",
        " glistening in the first light",
        " misty from the water below",
        " fresh with morning dampness"
        }));

    addTimeOfDayDescription("morning", ({
        " drying in the strengthening sun",
        " warming as the day brightens",
        " clear of morning mist",
        " comfortable in morning light",
        " revealing their sturdy construction",
        " busy with morning travelers",
        " pleasant in the moderate warmth",
        " visible in full morning clarity",
        " welcoming to bridge crossers",
        " practical in good daylight"
        }));

    addTimeOfDayDescription("noon", ({
        " hot from direct overhead sun",
        " uncomfortable to touch at midday",
        " radiating heat above the water",
        " seeking whatever shade exists",
        " blazing in the intense sunlight",
        " too hot for prolonged contact",
        " shimmering with accumulated heat",
        " requiring caution during peak sun",
        " scorching in the brilliant light",
        " harsh and glaring at noon"
        }));

    addTimeOfDayDescription("afternoon", ({
        " casting shadows toward the water",
        " cooler as the sun moves west",
        " comfortable once again",
        " highlighted by angled light",
        " showing their weathered texture",
        " pleasant for afternoon crossing",
        " textured by declining sunlight",
        " warming without being scorching",
        " golden in the afternoon glow",
        " inviting for bridge access"
        }));

    addTimeOfDayDescription("evening", ({
        " beautiful in the setting sun",
        " glowing with evening light",
        " peaceful above the darkening water",
        " highlighted against the sunset",
        " romantic in the golden hour",
        " cooling in the evening breeze",
        " scenic in the declining light",
        " restful after the day's heat",
        " lovely in the evening glow",
        " serene above the flowing water"
        }));

    addTimeOfDayDescription("dusk", ({
        " fading into evening shadows",
        " becoming indistinct in twilight",
        " merging with the bridge structure",
        " outlined against the darkening sky",
        " challenging to see clearly",
        " requiring careful navigation",
        " disappearing into gathering gloom",
        " felt more than seen",
        " shadowy above the water",
        " difficult to distinguish in dim light"
        }));

    addTimeOfDayDescription("night", ({
        " invisible in the darkness",
        " dangerous without proper lighting",
        " treacherous above the water",
        " navigated by touch and memory",
        " requiring extreme caution",
        " hazardous in complete darkness",
        " guided by the bridge structure",
        " perilous without illumination",
        " challenging even for locals",
        " risky above the flowing water"
        }));

    addTimeOfDayDescription("late night", ({
        " slippery with heavy dew",
        " damp from river moisture",
        " treacherous with condensation",
        " wet from the water below",
        " slick and potentially dangerous",
        " hazardous with accumulated moisture",
        " requiring utmost caution",
        " soaked by night humidity",
        " perilous in the deep darkness",
        " challenging even with care"
        }));

    addTimeOfDayDescription("midnight", ({
        " soaked with midnight dew",
        " dangerously slippery",
        " invisible and treacherous",
        " wet from river humidity",
        " extremely hazardous",
        " requiring careful step-by-step progress",
        " slick with condensed moisture",
        " perilous above the dark water",
        " treacherous without light",
        " dangerous even for the experienced"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " icy and extremely dangerous",
        " treacherous with winter ice",
        " slippery from frozen spray",
        " hazardous with accumulated frost",
        " made perilous by river ice",
        " dangerous with seasonal freezing",
        " requiring winter safety measures",
        " slick with frozen moisture",
        " transformed by winter weather",
        " challenging in cold conditions"
        }));

    addSeasonDescription("spring", ({
        " refreshed by spring rains",
        " clean from seasonal washing",
        " busy with renewed river traffic",
        " pleasant in mild spring weather",
        " renewed by seasonal flooding",
        " fresh from winter's passing",
        " comfortable in moderate temperatures",
        " brightened by spring cleaning",
        " revitalized by the changing season",
        " welcoming with spring's arrival"
        }));

    addSeasonDescription("summer", ({
        " scorching in the summer heat",
        " uncomfortably hot during the day",
        " best used during cooler hours",
        " requiring protection from sun",
        " blazing hot at midday",
        " radiating intense summer heat",
        " challenging during peak temperatures",
        " dangerous without sun protection",
        " uncomfortable in direct sunlight",
        " requiring early or late use"
        }));

    addSeasonDescription("autumn", ({
        " slippery with fallen leaves",
        " hazardous with seasonal debris",
        " requiring careful leaf removal",
        " beautiful but potentially dangerous",
        " challenging with autumn foliage",
        " made treacherous by wet leaves",
        " needing regular maintenance",
        " transformed by seasonal color",
        " obscured by fallen autumn leaves",
        " requiring extra caution"
        }));

    addDescriptionTemplate("bridge steps ##Adjective## "
        "provide access to the elevated crossing");
    addSomeLightDescriptionTemplate("bridge steps ##Adjective## "
        "connect to the bridge's span");
    addNearDarkDescriptionTemplate("stone steps can be felt "
        "leading to the bridge structure");
    addLowLightDescriptionTemplate("sturdy bridge steps "
        "provide access to the crossing");
    addDimLightDescriptionTemplate("bridge steps ##Adjective## "
        "connect to the elevated roadway");
    addSourceOfLight(1);

    addItemTemplate("The bridge steps are integrated into the bridge's "
        "supporting structure, carved from the same massive stones that "
        "form the abutments and piers. Each step is wide and stable, "
        "designed to handle the traffic of merchants, soldiers, and "
        "common travelers accessing the elevated crossing. The construction "
        "serves dual purposes - providing necessary access while forming "
        "part of the bridge's defensive capabilities.");
}
