//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cryomancer guild");
    InteriorType("frostbound keep");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The outer walls glisten with a thin sheen of hoarfrost, catching the pale morning light in shimmering silence"
        }));
    addTimeOfDayDescription("morning", ({
        ". Crystals of ice drift slowly through the air near the entrance, suspended by ancient cold magic"
        }));
    addTimeOfDayDescription("noon", ({
        ". Sunlight reflects sharply off the mirrored ice along its towers, casting blinding glints across the snow-covered ground"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The cold deepens slightly, and the faint hum of frozen enchantments pulses through the air"
        }));
    addTimeOfDayDescription("evening", ({
        ". Pale blue runes flicker to life along the foundation, bathing the area in a cold, otherworldly light"
        }));
    addTimeOfDayDescription("dusk", ({
        ". Frost creeps slowly down the outer walls, and the interior glows dimly through frozen panes of enchanted glass"
        }));
    addTimeOfDayDescription("night", ({
        " standing silent beneath the stars, a chill mist curling from beneath its sealed doors and glowing sigils shimmering faintly"
        }));
    addTimeOfDayDescription("late night", ({
        " with the surrounding air unnaturally still, and snowflakes forming perfect geometric shapes as they fall"
        }));
    addTimeOfDayDescription("midnight", ({
        " cloaked in absolute silence, broken only by the soft crackle of frost expanding across its walls"
        }));

    addSeasonDescription("winter", ({
        " standing tall and still, its structure seamlessly blending with the snow and ice of the season"
        }));
    addSeasonDescription("spring", ({
        " resisting the thaw, its icy walls glistening defiantly amidst the early bloom"
        }));
    addSeasonDescription("summer", ({
        " exuding a cold aura that chills the air around it, frost forming on nearby stones even in the heat"
        }));
    addSeasonDescription("autumn", ({
        " with drifting flakes of snow falling around it, as if untouched by the turning season"
        }));

    addSourceOfLight(6, "arcane frostlight", "night");

    addDescriptionTemplate("a frost-covered keep that houses the Cryomancer Guild");
    addNearDarkDescriptionTemplate("a tall, silent structure veiled in drifting snow");
    addLowLightDescriptionTemplate("a keep of shimmering ice and stone, faintly glowing with cold magic");
    addDimLightDescriptionTemplate("a crystalline structure of frost and frozen stone, etched with icy runes");
    addSomeLightDescriptionTemplate("a still, glacial keep surrounded by snow and swirling cold");
}