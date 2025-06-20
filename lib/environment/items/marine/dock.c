//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dock");

    addAdjectives(({ "broad", "busy", "wooden", "weathered", "harbor" }));
    addDescriptionTemplate("a ##Adjective## dock lined with mooring posts and crates");

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The dock is quiet in the pale light, with only the soft splash of "
        "water against the pilings",
        ". At dawn, fishermen ready their boats, their breath visible in the "
        "cool air",
        ". The dock is slick with dew, and the scent of salt is sharp and clean",
        ". Early morning fog drifts across the water, shrouding the dock in "
        "mist",
        ". Gulls wheel overhead, their cries echoing in the stillness"
        }));

    addTimeOfDayDescription("morning", ({
        ". The dock bustles with activity as boats are loaded and nets mended",
        ". Sunlight glints off the water, and the dock is alive with voices",
        ". Vendors set up stalls, offering fresh fish and supplies",
        ". Children chase each other along the planks, dodging workers and "
        "crates",
        ". The air is filled with the mingled scents of brine, tar, and fresh "
        "catch"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the dock is crowded with sailors, merchants, and townsfolk",
        ". The sun beats down, warming the planks and sending heat shimmering "
        "off the water",
        ". Boats come and go, their sails bright against the blue sky",
        ". Vendors hawk their wares to a lively crowd",
        ". The dock is a hub of commerce, the air filled with shouts and "
        "laughter"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon brings a steady breeze, fluttering pennants and "
        "cooling the dock",
        ". Shadows lengthen as the sun dips, and the activity begins to slow",
        ". Seabirds swoop low, searching for scraps left by the day's catch",
        ". The water glows with the golden light of late afternoon",
        ". Dockhands finish their work, stacking crates and coiling ropes"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, lanterns are lit along the dock, casting pools of "
        "warm light",
        ". The last boats return, their sails outlined against the setting sun",
        ". Couples stroll along the dock, enjoying the cool breeze and fading "
        "light",
        ". The water reflects the colors of the sunset, painting the dock in "
        "hues of orange and pink",
        ". Vendors pack up their stalls, and the dock grows quiet"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the dock is bathed in the last light of day, shadows "
        "stretching long across the planks",
        ". The air cools quickly, and mist begins to rise from the water",
        ". Lanterns flicker to life, their reflections dancing on the waves",
        ". The dock is nearly empty, save for a few late fishermen",
        ". The distant sound of a bell marks the end of the day's work"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the dock is quiet, the only sounds the gentle lapping of "
        "waves and the creak of wood",
        ". Lanterns cast dim pools of light, barely illuminating the far end",
        ". The air is cool and damp, carrying the scent of salt and seaweed",
        ". Shadows move as the tide shifts, and the dock feels almost deserted",
        ". Occasionally, a lone figure passes, footsteps echoing on the planks"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with seabirds returning to nest and the air fresh with the scent of "
        "new growth",
        " where spring rains leave the planks slick and shining, and wildflowers "
        "bloom along the shore",
        " as fishermen celebrate the return of migratory fish to the bay",
        " with the water teeming with life and the dock bustling with renewed "
        "activity",
        " as gentle breezes carry the promise of warmer days ahead"
        }));

    addSeasonDescription("summer", ({
        " with the sun high overhead, warming the planks and drawing crowds to "
        "the water's edge",
        " where children leap from the dock into the cool, clear water below",
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
        " as the crowds thin and the dock grows quieter with each passing day"
        }));

    addSeasonDescription("winter", ({
        " with frost riming the planks and the water below dark and still",
        " where only the hardiest fishermen brave the cold winds",
        " as ice forms along the edges and the dock stands nearly deserted",
        " with the sound of waves muffled by snow and the air biting cold",
        " as lanterns glow warmly against the long winter nights"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "the silhouette of a wooden dock extending over the water"
    );
    addLowLightDescriptionTemplate(
        "the outline of a weathered dock, its posts and planks barely visible"
    );
    addDimLightDescriptionTemplate(
        "a wooden dock with creaking planks and weathered posts jutting from "
        "the water"
    );
    addSomeLightDescriptionTemplate(
        "a weathered wooden dock extending over the water, boats bobbing at "
        "its sides"
    );

    // Single item template
    addItemTemplate(
        "The dock is a sturdy wooden platform extending over the water, its "
        "planks weathered by years of sun, wind, and salt. Thick ropes secure "
        "boats to heavy posts, and the scent of brine lingers in the air. "
        "Barnacles cling to the pilings below, and the gentle lapping of "
        "waves is ever-present. The dock is a hub of commerce and travel by "
        "day, and a place of quiet solitude by night."
    );
}
