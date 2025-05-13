//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Phaedra Hall");
    InteriorType("grand hall of knights, with banners of honor and the scent of polished steel");
    setFloorPlanType("fortified citadel of valor and strength");

    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn casts long shadows across the training grounds, where knights begin their daily drills, the clang of steel echoing through the air as the sun rises over the horizon"
        }));
    addTimeOfDayDescription("morning", ({
        ". The hall is bustling with activity, knights donning their armor and preparing for the day’s training, their faces determined and focused on their sacred duties"
        }));
    addTimeOfDayDescription("noon", ({
        ". The midday sun illuminates the towering banners of Phaedra, flanking the courtyard where knights spar and practice their combat techniques, the sounds of their swords ringing through the air"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The heat of the day is tempered by the steady rhythm of drills and training sessions. The air is thick with the energy of determination and the sharp focus of knights honing their skills"
        }));
    addTimeOfDayDescription("evening", ({
        ". As the sun sets, the hall quiets. The knights gather in the grand hall for a meal, the soft glow of candlelight flickering off their polished armor as they share stories of valor"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The hall is bathed in the golden glow of twilight, as knights gather to reflect on the day’s training and plan for upcoming missions, their eyes ever vigilant for the call to defend the realm"
        }));
    addTimeOfDayDescription("night", ({
        " when the guild hall is calm, the sounds of the day having faded. Torches line the walls, casting flickering shadows, as knights rest, preparing for the challenges that lie ahead"
        }));
    addTimeOfDayDescription("late night", ({
        " when only the distant sound of a knight’s armor can be heard, echoing through the silent halls as members of the Order meditate and reflect on their vows of service"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the hall is still, save for the occasional soft whisper of knights in prayer, reaffirming their commitment to honor, duty, and the protection of the innocent"
        }));

    addSeasonDescription("winter", ({
        " when the hall is protected from the harsh winds and snow outside, but the knights train with renewed vigor, preparing themselves for any challenge that may arise"
        }));
    addSeasonDescription("spring", ({
        " when the courtyard comes alive with the sounds of nature, and knights train in the sunlight, their swords flashing as they perfect their craft in preparation for the battles to come"
        }));
    addSeasonDescription("summer", ({
        " when the sun beats down on the training grounds, and knights push their limits under its intense light, their bodies and minds sharpened by the heat and pressure of their duty"
        }));
    addSeasonDescription("autumn", ({
        " when the cool breeze stirs the banners in the courtyard, and knights prepare for the coming seasons, sharpening their skills and forging their bonds of brotherhood before the next campaign"
        }));

    addSourceOfLight(6, "torches, lanterns, and divine light", "night");

    addDescriptionTemplate("a grand hall of knights, filled with banners of honor and symbols of valor, where knights train and vow to defend the realm");
    addNearDarkDescriptionTemplate("a fortified citadel, its towering walls and banners casting long shadows over the courtyard, a symbol of strength and courage");
    addLowLightDescriptionTemplate("a hall filled with the flickering light of candles and torches, its stone walls echoing with the sound of knights preparing for battle");
    addDimLightDescriptionTemplate("a grand citadel with walls lined with shields and weapons, where knights gather to discuss strategy and reinforce their sacred vows of loyalty and service");
    addSomeLightDescriptionTemplate("a hall where the light of honor and the strength of the knights shine, their banners standing proudly against the backdrop of their noble resolve");
}