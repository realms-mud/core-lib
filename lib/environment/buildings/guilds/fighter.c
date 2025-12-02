//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fighter guild hall");
    InteriorType("training fortress");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The first light casts long shadows across the courtyard, where the sound of swords clashing begins to echo from the training grounds"
        }));
    addTimeOfDayDescription("morning", ({
        ". The air is filled with the rhythmic thudding of wooden practice weapons, and the clash of steel as fighters hone their skills"
        }));
    addTimeOfDayDescription("noon", ({
        ". The courtyard is alive with activity: sparring matches, shouting instructors, and warriors practicing their stances under the midday sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The heat of the day brings a haze over the training yard, with warriors pushing through drills, sweat dripping from their faces"
        }));
    addTimeOfDayDescription("evening", ({
        ". The last rays of the sun fade from the stone walls, while torches are lit around the courtyard, casting flickering light on the practicing fighters"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The training grounds grow quieter, but the sound of distant combat drills still echoes through the cooling air"
        }));
    addTimeOfDayDescription("night", ({
        " under the cover of darkness, the hall stands firm and quiet, with only the faint glow of lanterns illuminating the practice dummies and sparring areas"
        }));
    addTimeOfDayDescription("late night", ({
        " with the sound of footfalls and whispers as the few remaining warriors conduct their late-night training, honing their bodies and minds"
        }));
    addTimeOfDayDescription("midnight", ({
        " silent except for the occasional sound of iron striking iron, as the guild remains vigilant even in the dead of night"
        }));

    addSeasonDescription("winter", ({
        " the courtyard blanketed by a thin layer of snow, the chill in the air sharpening the focus of each warrior who trains in the cold"
        }));
    addSeasonDescription("spring", ({
        " with the sound of practice weapons clashing under clear skies, and flowers beginning to bloom around the perimeter of the guild hall"
        }));
    addSeasonDescription("summer", ({
        " with the heat of the day stifling but not stopping the relentless training sessions, sweat pouring off of fighters as they drill under the sun"
        }));
    addSeasonDescription("autumn", ({
        " with the ground covered in a carpet of fallen leaves, adding a soft crunch underfoot as warriors march across the training yard"
        }));

    addSourceOfLight(6, "torchlight and braziers", "night");

    addDescriptionTemplate("a stone hall where warriors are forged in the heat of combat and disciplined training");
    addNearDarkDescriptionTemplate("a towering stone hall with iron-studded doors, faint light flickering from within");
    addLowLightDescriptionTemplate("a broad hall lined with shields and weapons, the glow of lanterns casting shadows across the walls");
    addDimLightDescriptionTemplate("a combat hall filled with the scent of leather and iron, with wooden practice dummies and shields hanging from the walls");
    addSomeLightDescriptionTemplate("a fortress of combat and training, alive with the sounds of warriors honing their strength and skill");
}