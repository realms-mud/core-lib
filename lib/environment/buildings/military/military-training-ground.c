//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("military training ground");
    setFloorPlanType("military");

    addAdjectives(({
        "busy", "open", "hard-packed", "martial", "active", "disciplined"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## military training ground with practice equipment and "
        "marked areas for different combat exercises"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day finds the training ground already active, "
        "recruits running in formation around its perimeter",
        ". At dawn, instructors call out drills and formations, their voices "
        "sharp in the cool morning air"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sees the training ground at its busiest, with sword practice, "
        "archery, and hand-to-hand combat lessons occurring simultaneously",
        ". The sound of wooden practice weapons clacking together fills the "
        "air as soldiers hone their skills under watchful eyes"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the training ground briefly quiets as soldiers take their "
        "meal, some resting in what shade they can find",
        ". The sun beats down on equipment arranged around the field - straw "
        "dummies, weapon racks, archery targets, and wrestling rings"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon brings specialized training, with veteran soldiers "
        "demonstrating techniques to attentive recruits",
        ". Dust rises from the hard-packed earth as fighters practice footwork "
        "and positioning in various combat scenarios"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the training shifts to endurance exercises, "
        "soldiers moving through drills despite the day's accumulated fatigue",
        ". The training ground gradually empties as units are dismissed, weapons "
        "and equipment returned to the nearby armory"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, only the most dedicated remain, practicing forms and "
        "movements in the fading light",
        ". Servants and junior recruits move across the field, collecting "
        "equipment and preparing the ground for tomorrow's training"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the training ground stands empty and silent, the packed "
        "earth holding the day's countless footprints until morning",
        ". Moonlight reveals the outlines of training equipment left in place - "
        "silent sentinels waiting for tomorrow's activities"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with new recruits being drilled in basic formations and mud making "
        "footing treacherous in certain areas",
        " where spring tournaments are being prepared for, colorful targets and "
        "markers adding temporary brightness to the utilitarian space"
        }));

    addSeasonDescription("summer", ({
        " with training starting earlier to avoid the worst heat and water "
        "barrels positioned strategically around the field",
        " where dust clouds rise with every movement, the summer dryness turning "
        "the hard-packed earth into powder under constant use"
        }));

    addSeasonDescription("autumn", ({
        " with more intensive training as campaign season ends and veterans "
        "have time to instruct newer recruits",
        " where the cooler weather allows for longer sessions of heavy armor "
        "drills and endurance training"
        }));

    addSeasonDescription("winter", ({
        " with training focused on close combat techniques that can be practiced "
        "in limited space and despite cold conditions",
        " where braziers burn at the field's edges, providing momentary warmth "
        "for soldiers rotating through outdoor exercise"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large open area with various shapes suggesting equipment and "
        "practice structures"
    );
    addLowLightDescriptionTemplate(
        "an open field with what appears to be military training equipment and "
        "marked practice areas"
    );
    addDimLightDescriptionTemplate(
        "a military training ground with weapon racks, practice dummies, and "
        "areas marked for different combat exercises"
    );
    addSomeLightDescriptionTemplate(
        "a busy military training field with archery butts, sword practice "
        "rings, wrestling areas, and obstacle courses arranged in organized "
        "sections"
    );

    // Single item template
    addItemTemplate(
        "The military training ground is a large, open area with hard-packed "
        "earth from constant use. The field is organized into sections for "
        "different training purposes - archery butts at the far end, practice "
        "rings marked with rope or chalk for sword and hand-to-hand combat, "
        "and obstacles for agility training. Equipment surrounds the perimeter: "
        "racks of wooden practice weapons, straw-filled dummies in various "
        "states of repair, and weighted training implements for building "
        "strength. The entire area speaks of disciplined purpose - a place "
        "where the art of war is systematically taught and honed."
    );
}
