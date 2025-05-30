//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("prison");
    setFloorPlanType("prison");

    addAdjectives(({
        "grim", "forbidding", "stone", "medieval", "imposing", "dark"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## limestone prison with heavy iron bars across narrow "
        "windows and a massive oak door reinforced with iron bands"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day reveals damp stone walls and casts long shadows "
        "from the iron bars",
        ". At dawn, the prison stands cold and silent, the occasional moan echoing "
        "from within"
        }));

    addTimeOfDayDescription("morning", ({
        ". Guards can be seen patrolling the perimeter, their keys jangling at "
        "their belts",
        ". Morning reveals the grime and wear on the prison's exterior, years of "
        "neglect evident in every stone"
        }));

    addTimeOfDayDescription("noon", ({
        ". The sun beats down on the limestone walls, but little warmth penetrates "
        "the thick stone to those inside",
        ". At midday, the prison seems to absorb the light, its shadows darker by "
        "contrast with the bright surroundings"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun casts stark shadows from the iron bars across the "
        "weathered stone",
        ". The prison stands as a somber reminder of justice and punishment in the "
        "afternoon light"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, torches are lit near the entrance, their flickering "
        "light barely penetrating the gloom inside",
        ". The prison takes on an even more forbidding appearance as shadows deepen "
        "around its walls"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the prison's silhouette looms ominously against the darkening "
        "sky",
        ". The last light fades from the day, and the prison becomes a dark "
        "monolith, broken only by the occasional torch glow"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the prison is a place of shadows and whispers, with only a few "
        "torches illuminating the guard posts",
        ". Moonlight glints off the iron bars, and the occasional cry can be heard "
        "from within the thick walls"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with moss growing between the stones and small wildflowers somehow "
        "finding purchase at its base",
        " as rain streaks the limestone walls, washing away winter's grime but "
        "never its reputation"
        }));

    addSeasonDescription("summer", ({
        " with heat radiating from the sun-baked stone, making the interior even "
        "more stifling",
        " as buzzing flies gather at the narrow window slits, drawn by the rank "
        "odors from within"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves collecting against its base, the chill wind carrying "
        "the sounds of chains and despair",
        " as the cooler air brings both relief and dread to those imprisoned "
        "behind the thick walls"
        }));

    addSeasonDescription("winter", ({
        " with frost rimming the iron bars and snow gathering in crevices of the "
        "weathered stone",
        " as bitter cold penetrates the walls, making the prison a place of "
        "misery and suffering"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive dark structure with tiny pinpoints of torchlight visible through "
        "slits in the walls"
    );
    addLowLightDescriptionTemplate(
        "a foreboding stone building with barred windows and torch brackets "
        "flanking a heavy door"
    );
    addDimLightDescriptionTemplate(
        "a grim limestone prison with iron-barred windows and imposing walls "
        "designed to keep people in"
    );
    addSomeLightDescriptionTemplate(
        "a medieval prison of rough-cut limestone blocks with narrow, barred "
        "windows and an iron-bound oak door"
    );

    // Single item template
    addItemTemplate(
        "The prison is a grim structure of weathered limestone with walls three "
        "feet thick and few windows, all heavily barred. A massive oak door "
        "reinforced with iron bands guards the entrance, and torch brackets flank "
        "the doorway. The building exudes an air of misery and confinement, "
        "designed to break the spirit as much as to contain the body."
    );

    addSourceOfLight(5);
}
