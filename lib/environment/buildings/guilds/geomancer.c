//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Geomancer Guild Hall");
    InteriorType("geomancer hall");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The rising sun casts a soft glow on the stonework of the guild hall, and the air is thick with the scent of moss and earth"
        }));
    addTimeOfDayDescription("morning", ({
        ". The guild hall hums with energy as geomancers begin their morning rituals, their magic shaping stone and earth with practiced ease"
        }));
    addTimeOfDayDescription("noon", ({
        ". The midday sun shines brightly through large open windows, illuminating the mineral-rich walls, where runes glow faintly in the light"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The earth beneath the guild hall seems to pulse with power as geomancers delve deep into the study of stones and crystals"
        }));
    addTimeOfDayDescription("evening", ({
        ". The stone floors are cool underfoot as the setting sun casts long shadows across the guild hall, and the sound of flowing earth magic echoes from the chambers"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The guild hall grows quieter as dusk falls, with the faint glow of earthstone lanterns illuminating the natural formations within"
        }));
    addTimeOfDayDescription("night", ({
        " the guild hall is bathed in the soft glow of glowing stones embedded in the walls, the earth alive with the pulse of geomantic energy"
        }));
    addTimeOfDayDescription("late night", ({
        " silent and still, with only the faint hum of deep earth magic filling the air, as geomancers meditate in the dim light"
        }));
    addTimeOfDayDescription("midnight", ({
        " under the pale light of glowing earthstones, the guild hall feels timeless, the stone walls vibrating ever so slightly with ancient power"
        }));

    addSeasonDescription("winter", ({
        " with the chill of the earth resonating through the stone walls, the ground outside hardened by frost, yet the guild remains warm with the heat of earth magic"
        }));
    addSeasonDescription("spring", ({
        " with vibrant moss and lichen growing along the stone walls, and flowers blooming in small garden spaces inside the guild"
        }));
    addSeasonDescription("summer", ({
        " the warmth of the earth can be felt radiating from the stone floors, and the guild hall is alive with the sound of geomancers honing their craft"
        }));
    addSeasonDescription("autumn", ({
        " with the earth outside rich with fallen leaves and the scent of rich, damp soil, as geomancers work to strengthen their ties to the earth"
        }));

    addSourceOfLight(5, "glowing earthstones and lanterns", "night");

    addDescriptionTemplate("a majestic guild hall carved from stone, alive with the power of earth magic");
    addNearDarkDescriptionTemplate("an ancient hall of stone, its deep shadows broken only by glowing veins of crystal and earthstone lanterns");
    addLowLightDescriptionTemplate("a cavernous hall filled with the hum of geomantic energy, where the walls pulse faintly with earth magic");
    addDimLightDescriptionTemplate("a stone hall, the air thick with the scent of moss and the warmth of the earth, as geomancers study ancient runes");
    addSomeLightDescriptionTemplate("a powerful guild hall of geomancers, where stone and earth come alive in the hands of skilled practitioners");
}