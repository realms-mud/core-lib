//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gladiator ring");
    setFloorPlanType("gladiator ring");

    addAdjectives(({ "circular", "imposing", "blood-stained", "roaring",
        "savage" }));

    // Basic description template
    addDescriptionTemplate("##Adjective## wooden arena surrounded by tiered "
        "seating for spectators of gladiatorial combat");

    // Add time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The early morning light filters through gaps in the wooden "
        "structure, creating shafts of golden light across the sandy arena",
        ". Dew glistens on the wooden barriers as the rising sun casts long "
        "shadows across the empty arena floor",
        ". The arena stands silent in the dawn light, a stark contrast to the "
        "roaring crowds that will fill it later in the day"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light illuminates the sand of the combat area, revealing "
        "dark stains from previous bouts that no amount of raking can hide",
        ". Preparations are underway as attendants rake the sand and inspect "
        "the barriers in the growing morning light",
        ". The wooden structure creaks slightly as it warms in the morning sun, "
        "the sound echoing in the still-empty arena"
        }));

    addTimeOfDayDescription("noon", ({
        ". Under the harsh midday sun, the arena is fully illuminated, the "
        "sand reflecting blinding light up toward the spectator stands",
        ". Heat radiates from the sand floor as the midday sun beats down, "
        "creating a furnace-like atmosphere in the combat area",
        ". At noon, the entire ring is bathed in bright light, leaving no "
        "shadows for combatants to use to tactical advantage"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun casts lengthening shadows across the arena floor, "
        "offering slight relief to combatants in the western sections",
        ". Spectators in the eastern stands shield their eyes from the glare "
        "of the setting sun reflecting off weapons and armor in the ring",
        ". The worn wooden barriers show years of abuse in the harsh "
        "afternoon light, splattered with countless battles' aftermath"
        }));

    addTimeOfDayDescription("evening", ({
        ". Torches are lit around the arena as daylight fades, casting "
        "flickering shadows that dance across the bloodied sand",
        ". The evening's bouts take on a more primal quality as torchlight "
        "casts dramatic shadows across combatants' faces",
        ". As evening falls, the wooden structure seems to absorb the day's "
        "violence, creaking and settling with an almost organic quality"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the arena takes on an ethereal quality as torch smoke "
        "mingles with the fading light, creating a misty battlefield",
        ". The ring becomes a world unto itself at dusk, the outside world "
        "fading away as torches illuminate only the combat at hand",
        ". Shadows lengthen across the sand as dusk falls, the barrier "
        "between spectator and gladiator blurring in the dim light"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the arena is transformed by firelight, the sand "
        "glowing amber under blazing torches mounted on every post",
        ". Stars visible above the open arena contrast with the torchlit "
        "violence below, heaven and hell separated by wooden barriers",
        ". The night bouts carry a special intensity, the darkness beyond "
        "the torchlight hiding the faces of all but the closest spectators"
        }));

    // Add seasonal variations
    addSeasonDescription("spring", ({
        " with patches of new grass attempting to reclaim the edges of the "
        "arena where sand meets earth",
        " where spring rains have dampened the sand, making footing "
        "treacherous and movement more labored for combatants",
        " with colorful banners of competing gladiatorial schools fluttering "
        "in the spring breeze above the spectator stands"
        }));

    addSeasonDescription("summer", ({
        " where heat rises visibly from the sand, adding another opponent to "
        "any who must fight during the scorching midday",
        " with canvas awnings stretched over sections of the stands to "
        "shelter wealthy patrons from the merciless summer sun",
        " while spectators fan themselves in the stifling heat, the combat "
        "below made all the more brutal by the oppressive temperatures"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves occasionally drifting onto the arena sand, adding "
        "splashes of color to the bloodstained ground",
        " where the cooler air brings larger crowds eager to witness the "
        "spectacle before winter forces many bouts indoors",
        " as the wooden structure creaks and groans against autumn winds, "
        "the sound sometimes punctuating crucial moments in combat below"
        }));

    addSeasonDescription("winter", ({
        " with braziers placed around the arena's edge to ward off the bitter "
        "cold for both combatants and spectators",
        " where steam rises from the bodies of gladiators as sweat meets "
        "frigid air, creating an otherworldly mist around each fighter",
        " with spectators huddled under furs and blankets, their breath "
        "visible in the cold as they cheer for blood and glory"
        }));

    // Add lighting condition descriptions
    addNearDarkDescriptionTemplate("the looming shape of a circular arena, "
        "the wooden barriers barely visible in the darkness");

    addLowLightDescriptionTemplate("a wooden gladiatorial ring with shadowy "
        "figures moving about, preparing the arena for upcoming combat");

    addDimLightDescriptionTemplate("a large circular combat arena surrounded "
        "by tiered wooden seating for spectators");

    addSomeLightDescriptionTemplate("a well-constructed gladiatorial ring with "
        "a sand-covered floor and barriers to protect the spectators");

    // Single item template
    addItemTemplate("The sand-covered floor bears dark stains of countless "
        "combats, while wooden barriers topped with metal spikes separate "
        "combatants from the roaring crowd in the surrounding stands");
}
