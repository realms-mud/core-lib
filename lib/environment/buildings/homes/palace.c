//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("palace");
    setFloorPlanType("palace");

    addAdjectives(({
        "magnificent", "royal", "opulent", "grand", "regal", "majestic"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## palace with soaring towers, massive wings, and "
        "elaborate architectural ornamentation"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the highest spires and golden "
        "weathervanes, gradually illuminating the palace from top to bottom",
        ". At dawn, the palace emerges from darkness like a vision, its many "
        "towers and domes capturing the rose-gold light of early morning"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the palace in all its splendor, from intricate "
        "carvings to gilded balconies that catch the sun like flame",
        ". The palace bustles with activity by mid-morning, with livried "
        "servants, court officials, and petitioners flowing through its gates"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the palace dominates the landscape, its white stone "
        "brilliant against the blue sky and its banners hanging still in the "
        "heat",
        ". The noon sun highlights the symmetry of the palace design, from "
        "central dome to the perfectly balanced wings that extend outward"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light brings a golden quality to the palace stones, "
        "softening the grandeur with warmth that belies its imposing presence",
        ". Shadows begin to add dimension to the ornate facades, highlighting "
        "the extraordinary craftsmanship in every carved surface and column"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the palace transforms as hundreds of lamps and "
        "chandeliers are lit within, gold light spilling from countless windows",
        ". The palace seems most alive at evening, when illuminated fountains "
        "play before the main entrance and music drifts from the state rooms"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the palace silhouette dominates the skyline, its many "
        "towers and ornate rooflines distinct against the darkening sky",
        ". The fading light kindles reflections in hundreds of windows, making "
        "the palace appear to be adorned with gems as night approaches"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the palace becomes a wonderland of light, with torches "
        "along the approaches and chandeliers visible through tall windows",
        ". Moonlight plays across the palace's grand facades, turning stone to "
        "silver and casting mysterious shadows among the architectural details"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with formal gardens bursting into carefully orchestrated bloom and "
        "fountains playing in the sunshine after winter's dormancy",
        " where ceremonial guards in bright spring uniforms stand at attention "
        "before gates thrown open for the season's first court celebrations"
        }));

    addSeasonDescription("summer", ({
        " with colorful pennants flying from every tower and awnings extended "
        "over terraces where courtiers gather in the shade",
        " surrounded by gardens at their peak splendor, each vista and "
        "arrangement designed to enhance the palace's majestic presence"
        }));

    addSeasonDescription("autumn", ({
        " with golden light matching the gilded details of the facade and formal "
        "gardens transitioning to autumnal splendor",
        " where the slanting seasonal light creates dramatic shadows that "
        "emphasize the depth of architectural details and carved ornamentation"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining every architectural flourish and icicles hanging "
        "like crystal decorations from elaborately carved eaves",
        " where despite the season, the palace remains busy with court life, "
        "smoke rising from countless chimneys that pierce the roofline"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "an enormous structure with multiple towers and wings visible against "
        "the sky"
    );
    addLowLightDescriptionTemplate(
        "a massive palace with numerous towers, wings, and what appear to be "
        "ornate architectural details"
    );
    addDimLightDescriptionTemplate(
        "a grand palace with soaring towers, extensive wings, and elaborate "
        "decorative elements along its facades"
    );
    addSomeLightDescriptionTemplate(
        "a magnificent royal palace with multiple towers and domes, massive "
        "wings extending from a central block, and intricate ornamentation "
        "covering every visible surface"
    );

    // Single item template
    addItemTemplate(
        "The palace stands as the ultimate expression of power and wealth, its "
        "enormous scale defying ordinary architecture. Built of the finest "
        "white stone, the structure features a central block topped by a massive "
        "dome, with symmetrical wings extending outward and towers rising at "
        "strategic points. Every surface is enhanced with ornamental details - "
        "carved stone, gilded accents, statuary, and decorative ironwork. Huge "
        "windows, many with ornate balconies, punctuate the facades, while "
        "grand staircases lead to imposing entrance portals. The surrounding "
        "grounds include formal gardens, reflecting pools, and ceremonial "
        "approaches designed to awe visitors before they even reach the doors."
    );

    addSourceOfLight(8);
}
