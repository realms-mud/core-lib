//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pier");

    addAdjectives(({ "long", "weathered", "wooden", "bustling", "salt-stained" }));
    addDescriptionTemplate("a ##Adjective## pier stretching far out over the water");

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light glimmers on the water, painting the pier in soft "
        "pastels as fishermen ready their boats",
        ". At dawn, gulls circle overhead, their cries echoing across the "
        "quiet planks",
        ". The pier is slick with dew, and the air is crisp with the scent of "
        "salt and seaweed",
        ". Early risers stroll along the pier, enjoying the peaceful start to "
        "the day",
        ". Gentle waves lap against the pilings, the only sound in the still "
        "morning air"
        }));

    addTimeOfDayDescription("morning", ({
        ". The pier bustles with activity as boats come and go, ropes creaking "
        "and voices calling",
        ". Sunlight sparkles on the water, casting shifting patterns across "
        "the wooden planks",
        ". Vendors set up stalls at the pier's entrance, offering fresh catch "
        "and baked goods",
        ". Children run along the pier, their laughter mingling with the calls "
        "of seabirds",
        ". The scent of brine and tar is strong as workers repair nets and "
        "prepare for the day's work"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the pier is alive with the shouts of sailors and the "
        "clatter of cargo being loaded",
        ". The sun beats down, warming the planks and sending heat shimmering "
        "off the water",
        ". Fishermen haul in their catches, scales glinting in the bright "
        "light",
        ". Vendors hawk their wares to a crowd of townsfolk and travelers",
        ". The pier is crowded, the air filled with the mingled scents of "
        "seafood and spices"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon brings a steady breeze, fluttering pennants and "
        "cooling the pier",
        ". Shadows lengthen as the sun dips, and the activity begins to slow",
        ". Seabirds swoop low, searching for scraps left by the day's catch",
        ". The water glows with the golden light of late afternoon",
        ". Dockhands finish their work, stacking crates and coiling ropes"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, lanterns are lit along the pier, casting pools of "
        "warm light",
        ". The last boats return, their sails outlined against the setting sun",
        ". Couples stroll along the pier, enjoying the cool breeze and fading "
        "light",
        ". The water reflects the colors of the sunset, painting the pier in "
        "hues of orange and pink",
        ". Vendors pack up their stalls, and the pier grows quiet"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the pier is bathed in the last light of day, shadows "
        "stretching long across the planks",
        ". The air cools quickly, and mist begins to rise from the water",
        ". Lanterns flicker to life, their reflections dancing on the waves",
        ". The pier is nearly empty, save for a few late fishermen",
        ". The distant sound of a bell marks the end of the day's work"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the pier is quiet, the only sounds the gentle lapping of "
        "waves and the creak of wood",
        ". Lanterns cast dim pools of light, barely illuminating the far end",
        ". The air is cool and damp, carrying the scent of salt and seaweed",
        ". Shadows move as the tide shifts, and the pier feels almost "
        "deserted",
        ". Occasionally, a lone figure passes, footsteps echoing on the planks"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with seabirds returning to nest and the air fresh with the scent of "
        "new growth",
        " where spring rains leave the planks slick and shining, and wildflowers "
        "bloom along the shore",
        " as fishermen celebrate the return of migratory fish to the bay",
        " with the water teeming with life and the pier bustling with renewed "
        "activity",
        " as gentle breezes carry the promise of warmer days ahead"
        }));

    addSeasonDescription("summer", ({
        " with the sun high overhead, warming the planks and drawing crowds to "
        "the water's edge",
        " where children leap from the pier into the cool, clear water below",
        " as boats come and go in a steady stream, their sails bright against "
        "the sky",
        " with vendors selling cold drinks and fresh fruit to passersby",
        " as the air hums with laughter, music, and the sounds of summer"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves collecting in the corners and the air turning "
        "crisp",
        " where fishermen prepare for the last big catches before winter",
        " as the water grows choppy and the sky fills with migrating birds",
        " with the scent of woodsmoke drifting from nearby fires",
        " as the crowds thin and the pier grows quieter with each passing day"
        }));

    addSeasonDescription("winter", ({
        " with frost riming the planks and the water below dark and still",
        " where only the hardiest fishermen brave the cold winds",
        " as ice forms along the edges and the pier stands nearly deserted",
        " with the sound of waves muffled by snow and the air biting cold",
        " as lanterns glow warmly against the long winter nights"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "the silhouette of a long wooden pier stretching out over the water"
    );
    addLowLightDescriptionTemplate(
        "the outline of a weathered pier, its posts and planks barely visible"
    );
    addDimLightDescriptionTemplate(
        "a long wooden pier with creaking planks and weathered posts jutting "
        "from the water"
    );
    addSomeLightDescriptionTemplate(
        "a weathered wooden pier stretching far out over the water, gulls "
        "perched along its railings"
    );

    // Single item template
    addItemTemplate(
        "The pier is a long, weathered structure of wooden planks and posts, "
        "stretching far out over the water. Gulls perch along the railings, "
        "and the scent of salt and seaweed drifts on the breeze. Boats are "
        "moored along its length, and lanterns hang from iron hooks, ready to "
        "be lit as night falls. The pier is a hub of activity by day and a "
        "place of quiet reflection by night."
    );
}
