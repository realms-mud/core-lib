//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Mage Guild Hall");
    InteriorType("arcane library and mystic sanctum");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn illuminates the tower's grand archways, casting a warm glow on the enchanted bookshelves that line the walls, their contents alive with arcane energy"
        }));
    addTimeOfDayDescription("morning", ({
        ". The guild hall is filled with the sounds of scholars pouring over ancient texts, with the occasional flicker of magic as spells are tested in the practice chambers"
        }));
    addTimeOfDayDescription("noon", ({
        ". Sunlight pours through large enchanted windows, bathing the guild hall in a soft glow as mages gather in the lecture halls, learning from masters of the arcane arts"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The air is thick with magic as the mages refine their craft, practicing elemental spells in the courtyard or transmuting objects in the labs"
        }));
    addTimeOfDayDescription("evening", ({
        ". The hall grows quieter as the sun sets, the flicker of candlelight and the occasional arcane spark providing the only illumination as mages work late into the night"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The magical glow of orbs and enchanted lamps fills the hall, casting flickering shadows across the towering shelves of arcane books, while students engage in whispered discussions about forbidden knowledge"
        }));
    addTimeOfDayDescription("night", ({
        " when the guild hall hums with quiet energy, arcane sigils lighting up the walls as mages and scholars study their tomes and experiment with spells, the faint glow of their magic casting eerie shadows"
        }));
    addTimeOfDayDescription("late night", ({
        " the halls are eerily quiet, with only the faint sound of a quill on parchment and the occasional hum of magical power breaking the silence"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is at its most peaceful, the stars visible through the tall, enchanted windows, and the soft glow of floating orbs illuminating the arcane study rooms"
        }));

    addSeasonDescription("winter", ({
        " the tower stands stark against the cold, the stone walls radiating a warmth that comes not from the hearth, but from the potent magical energies at the heart of the guild"
        }));
    addSeasonDescription("spring", ({
        " with the scent of blooming magical flowers drifting through the halls, and apprentices busy with their studies in the warm light of enchanted orbs"
        }));
    addSeasonDescription("summer", ({
        " when the guild hall is alive with magical energy, the heat of summer adding to the fervor of research, and the courtyard filled with practitioners casting spells in the sun"
        }));
    addSeasonDescription("autumn", ({
        " with the halls filled with the rustling of old scrolls and the scent of incense, as mages prepare for their annual arcane symposium"
        }));

    addSourceOfLight(6, "floating orbs of light and enchanted candles", "night");

    addDescriptionTemplate("a grand, ancient guild hall filled with tomes of arcane knowledge, the air thick with magical energy");
    addNearDarkDescriptionTemplate("a towering structure, its silhouette illuminated by the soft glow of magical orbs, with faint arcane symbols pulsing on the walls");
    addLowLightDescriptionTemplate("a quiet hall with shelves of arcane books, the air humming with the faint energy of magic as mages work and study");
    addDimLightDescriptionTemplate("an imposing tower filled with magical artifacts, with the glow of enchanted lights casting long shadows across its vast chambers");
    addSomeLightDescriptionTemplate("a sprawling magical library and tower, alive with the glow of floating lights and arcane power, where mages delve into their studies");
}