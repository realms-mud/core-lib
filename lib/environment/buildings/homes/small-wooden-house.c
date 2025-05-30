//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small wooden house");
    setFloorPlanType("house");

    addAdjectives(({
        "snug", "modest", "small", "simple", "compact", "humble"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## wooden house with a steep roof and a small stoop"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first rays of light touch the simple wooden walls, bringing "
        "warmth to the modest dwelling",
        ". At dawn, thin smoke rises from the small chimney, the only movement "
        "around the otherwise still structure"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sun reveals the rustic charm of the small house, light "
        "playing across the uneven wooden planks of its walls",
        ". The compact structure catches the morning light, its single window "
        "gleaming like an observant eye"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the small wooden house seems to shrink further into the "
        "shadow of its overhanging roof",
        ". The wooden walls warm in the noon sun, releasing the subtle scent of "
        "pine that lingers around the humble dwelling"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light highlights the simplicity of the structure - "
        "straightforward craftsmanship without pretension",
        ". Shadows lengthen around the small house as afternoon progresses, the "
        "wooden walls darkening to a rich amber hue"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, a warm glow appears in the single window, "
        "transforming the simple structure into a beacon of comfort",
        ". The small wooden house settles with occasional creaks and pops as "
        "the timbers cool with the coming of evening"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the wooden structure merges with the gathering shadows, "
        "only its outline still distinct against the darkening sky",
        ". The last light catches on the small metal chimney cap, a final "
        "gleam before the house surrenders to night"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the small house is reduced to a darker shadow among "
        "shadows, save for a square of golden light from its single window",
        ". Moonlight washes over the simple wooden walls, lending the humble "
        "dwelling an unexpected dignity"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with wild violets clustered around its foundation stones and new "
        "shoots pushing through the earth of the tiny garden",
        " where spring rain darkens the wooden walls in uneven patterns, "
        "revealing years of weathering and repair"
        }));

    addSeasonDescription("summer", ({
        " with its small window propped open and summer flowers growing in "
        "surprising abundance around the simple structure",
        " surrounded by tall grasses that sway in summer breezes, lending "
        "movement to the otherwise still scene"
        }));

    addSeasonDescription("autumn", ({
        " with a small woodpile neatly stacked against one wall and fallen "
        "leaves gathering around the stone foundation",
        " where the aged wooden walls blend perfectly with autumn's palette, the "
        "house becoming one with the season's golden tones"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising steadily from the small chimney and snow creating "
        "a perfect white cap upon its steep roof",
        " where icicles hang from the simple eaves, transforming the humble "
        "structure into something magical when they catch the light"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a small, boxy shape with what appears to be a peaked roof"
    );
    addLowLightDescriptionTemplate(
        "a small wooden structure with a single window and narrow chimney"
    );
    addDimLightDescriptionTemplate(
        "a modest wooden house with rough-hewn walls and a steep roof"
    );
    addSomeLightDescriptionTemplate(
        "a small wooden house with plank walls, a steep shingled roof, and a "
        "simple stoop before its single door"
    );

    // Single item template
    addItemTemplate(
        "The small wooden house is a model of practical simplicity, built of "
        "rough-hewn planks with visible adze marks still evident. Its steep "
        "roof is covered with wooden shingles, darkened by years of sun and "
        "rain. A single window with wooden shutters faces the path, while a "
        "simple plank door opens onto a modest stoop. The entire structure "
        "consists of just one room with perhaps a sleeping loft under the "
        "eaves. A narrow stone chimney rises from one side, promising warmth "
        "against winter's chill."
    );

    addSourceOfLight(2);
}
