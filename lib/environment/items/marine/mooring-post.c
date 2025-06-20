//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mooring post");
    addAlias("post");
    addAlias("mooring");

    addAdjectives(({ "sturdy", "wooden", "weathered", "upright", "dockside" }));
    addDescriptionTemplate("a ##Adjective## mooring post set at the dock's edge");

    addTimeOfDayDescription("dawn", ({
        ". The mooring post is slick with dew, ropes coiled neatly at its base",
        ". At dawn, the post casts a long shadow across the dock",
        ". Gulls perch atop the post, calling out over the quiet water",
        ". The post stands silent as fishermen ready their boats nearby",
        ". Gentle waves lap against the dock, rocking the post slightly"
        }));
    addTimeOfDayDescription("morning", ({
        ". The mooring post is busy with sailors tying off their boats",
        ". Sunlight glints off the wet wood and iron rings of the post",
        ". Ropes are looped and knotted, securing vessels for the day",
        ". Children play near the post, dodging the busy dockhands",
        ". The scent of brine and tar lingers around the mooring post"
        }));
    addTimeOfDayDescription("noon", ({
        ". The post is warm in the midday sun, ropes drying in the heat",
        ". Boats come and go, lines quickly tied and untied",
        ". Vendors rest in the post's shade, watching the harbor",
        ". The post is surrounded by bustling activity and shouted greetings",
        ". The air is filled with the sounds of commerce and creaking wood"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The post is splashed by the rising tide, ropes damp and heavy",
        ". Shadows lengthen as the sun dips, and the dock grows quieter",
        ". Seabirds rest on the post, preening in the afternoon light",
        ". The post stands firm as boats are readied for evening departure",
        ". The water glows golden, reflecting off the post's wet surface"
        }));
    addTimeOfDayDescription("evening", ({
        ". Lanterns are hung from the post, casting a warm glow on the dock",
        ". The post is quiet, most boats having returned for the night",
        ". The air cools, and the post is slick with evening mist",
        ". The post's shadow stretches long across the empty dock",
        ". Only a few late workers remain, securing lines to the post"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The post is bathed in the last light of day, ropes coiled in shadow",
        ". The air cools quickly, and mist rises around the mooring post",
        ". Lanterns flicker to life, illuminating the post and its ropes",
        ". The post stands alone as the dock empties for the night",
        ". The distant sound of a bell marks the end of the day's work"
        }));
    addTimeOfDayDescription("night", ({
        ". The post is shrouded in darkness, only faintly lit by lanterns",
        ". The air is cool and damp, and the post is slick with dew",
        ". Shadows move as the tide shifts, and the post stands silent",
        ". Occasionally, a lone figure ties off a late-arriving boat",
        ". The post creaks softly as the water laps against the dock"
        }));

    addSeasonDescription("spring", ({
        " with new ropes and fresh paint marking the start of the season",
        " where seabirds nest nearby, their calls filling the air",
        " as the post is surrounded by blooming wildflowers along the dock",
        " with the scent of fresh growth mingling with salt and tar",
        " as gentle breezes carry the promise of warmer days"
        }));
    addSeasonDescription("summer", ({
        " with the sun warming the wood and ropes drying quickly",
        " where children play nearby, splashing in the water",
        " as the post is busy with boats coming and going all day",
        " with the air humming with laughter and the sounds of summer",
        " as the post stands firm through the busiest season"
        }));
    addSeasonDescription("autumn", ({
        " with fallen leaves collecting at its base",
        " where the post is battered by choppy water and cool winds",
        " as the dock grows quieter and the post sees fewer boats",
        " with the scent of woodsmoke drifting from nearby fires",
        " as the post stands sentinel through the changing season"
        }));
    addSeasonDescription("winter", ({
        " with frost riming the wood and ropes stiff with cold",
        " where only the hardiest sailors tie off their boats",
        " as ice forms along the dock and the post stands nearly unused",
        " with the sound of waves muffled by snow and the air biting cold",
        " as lanterns glow warmly against the long winter nights"
        }));

    addNearDarkDescriptionTemplate(
        "the silhouette of a mooring post stands at the edge of the dock"
    );
    addLowLightDescriptionTemplate(
        "the outline of a weathered mooring post, ropes coiled at its base"
    );
    addDimLightDescriptionTemplate(
        "a sturdy mooring post with iron rings and thick ropes tied around it"
    );
    addSomeLightDescriptionTemplate(
        "a weathered mooring post stands at the dock's edge, ropes securing "
        "boats nearby"
    );
    addItemTemplate(
        "The mooring post is a thick, weathered timber set firmly into the dock. "
        "Iron rings and thick ropes are looped around it, securing boats of all "
        "sizes. The wood is scarred by years of use, and the post stands as a "
        "silent witness to the comings and goings of the harbor. "
    );
}
