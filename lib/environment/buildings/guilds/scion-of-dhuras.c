//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Scions of Dhurath Guild Hall");
    InteriorType("a sturdy stone hall with magical sigils carved into its walls, designed for combat training and magical experimentation");
    setFloorPlanType("fortified guild hall, a place where martial warriors and spellcasters train side by side");

    addTimeOfDayDescription("dawn", ({
        ". The guild hall is silent, save for the occasional clang of a distant weapon being tested. The early morning light casts long shadows over the walls inscribed with magical runes"
        }));
    addTimeOfDayDescription("morning", ({
        ". The clang of weapons fills the air as warriors practice their magic-infused strikes. The guild members can be seen sparring with glowing weapons, their magic crackling with each blow"
        }));
    addTimeOfDayDescription("noon", ({
        ". The hall is alive with the sound of combat as Scions train fiercely, their weapons glowing with magical energy. Some meditate, focusing their magical powers, while others engage in sparring matches"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The hall is quiet but for the sounds of weapons striking shields and the occasional chant as warriors prepare for upcoming battles. Magic-infused weapons rest on racks, crackling with latent energy"
        }));
    addTimeOfDayDescription("evening", ({
        ". The hall is filled with the sound of chanting and the rhythmic strike of weapons. Warriors and mages alike are drawn to the forge, where new magical weapons are being crafted and imbued"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The sun sets behind the guild hall, casting long shadows across the training grounds. The last few sparring matches are ending as members prepare for the night's rest"
        }));
    addTimeOfDayDescription("night", ({
        " when the guild hall is lit only by the soft glow of enchanted weapons resting in the armory. Some members continue their meditations, channeling magic through their weapons in preparation for future battles"
        }));
    addTimeOfDayDescription("late night", ({
        " when the hall is quiet, save for the faint crackle of arcane energy in the air as the Scions perfect their magical weapons. The distant hum of enchanted steel resonates in the silence"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is still. Only a few members remain in the forge, their weapons glowing faintly with the residual magical energy they’ve infused"
        }));

    addSeasonDescription("winter", ({
        " when the cold outside is matched only by the heated forges inside the hall. The warriors gather around roaring fires to practice their magic and train their muscles, preparing for the harsh season ahead"
        }));
    addSeasonDescription("spring", ({
        " when the guild hall’s training grounds are filled with the energy of warriors preparing for new battles. The air is thick with the sound of weapons and the hum of magic as the warriors refine their skills"
        }));
    addSeasonDescription("summer", ({
        " when the heat from the forge is matched by the intensity of combat training. The air crackles with magic, and the sound of enchanted blades cutting through the air fills the guild hall"
        }));
    addSeasonDescription("autumn", ({
        " when the leaves outside fall in a swirl of color, much like the bursts of magic that accompany the Scions' strikes. The guild hall is alive with training and preparation as the warriors anticipate the coming conflicts"
        }));

    addSourceOfLight(5, "forges, enchanted lanterns, and arcane energy", "night");

    addDescriptionTemplate("a stone hall with enchanted weapons on display, magical sigils carved into the walls, and the sounds of combat and arcane magic filling the air");
    addNearDarkDescriptionTemplate("a silhouette of a sturdy stone building, glowing faintly with the energy of magical weapons resting within");
    addLowLightDescriptionTemplate("a stone hall lit by the soft glow of enchanted weapons, with magical runes glowing on the walls and the faint echo of training in the distance");
    addDimLightDescriptionTemplate("a fortress-like guild hall, filled with the hum of magic-infused steel and the sounds of combat training");
    addSomeLightDescriptionTemplate("a grand hall filled with the sounds of weapons clashing, magical runes lighting the walls and illuminating the warriors as they prepare for battle");
}