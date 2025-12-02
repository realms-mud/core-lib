//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bollard");
    addAlias("mooring bollard");
    addAlias("iron post");

    addAdjectives(({ "iron", "short", "sturdy", "dockside", "mooring" }));
    addDescriptionTemplate("a ##Adjective## bollard set into the dock for mooring lines");

    addTimeOfDayDescription("dawn", ({
        ". The bollard is slick with dew, iron gleaming in the early light",
        ". At dawn, ropes are looped around the bollard as boats arrive",
        ". The bollard casts a long shadow across the dock",
        ". Gulls perch nearby, watching the quiet harbor",
        ". The air is crisp, and the bollard is cool to the touch"
        }));
    addTimeOfDayDescription("morning", ({
        ". The bollard is busy with sailors tying off their lines",
        ". Sunlight glints off the iron, highlighting rust and wear",
        ". Ropes are coiled neatly, ready for the day's work",
        ". The bollard stands firm as boats jostle for space",
        ". The scent of brine and tar lingers around the bollard"
        }));
    addTimeOfDayDescription("noon", ({
        ". The bollard is warm in the midday sun, ropes drying quickly",
        ". Boats come and go, lines quickly tied and untied",
        ". Vendors rest in the bollard's shade, watching the harbor",
        ". The bollard is surrounded by bustling activity and shouted greetings",
        ". The air is filled with the sounds of commerce and creaking wood"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The bollard is splashed by the rising tide, ropes damp and heavy",
        ". Shadows lengthen as the sun dips, and the dock grows quieter",
        ". Seabirds rest nearby, preening in the afternoon light",
        ". The bollard stands firm as boats are readied for evening departure",
        ". The water glows golden, reflecting off the bollard's iron surface"
        }));
    addTimeOfDayDescription("evening", ({
        ". Lanterns are hung near the bollard, casting a warm glow on the dock",
        ". The bollard is quiet, most boats having returned for the night",
        ". The air cools, and the bollard is slick with evening mist",
        ". The bollard's shadow stretches long across the empty dock",
        ". Only a few late workers remain, securing lines to the bollard"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The bollard is bathed in the last light of day, ropes coiled in shadow",
        ". The air cools quickly, and mist rises around the bollard",
        ". Lanterns flicker to life, illuminating the bollard and its ropes",
        ". The bollard stands alone as the dock empties for the night",
        ". The distant sound of a bell marks the end of the day's work"
        }));
    addTimeOfDayDescription("night", ({
        ". The bollard is shrouded in darkness, only faintly lit by lanterns",
        ". The air is cool and damp, and the bollard is slick with dew",
        ". Shadows move as the tide shifts, and the bollard stands silent",
        ". Occasionally, a lone figure ties off a late-arriving boat",
        ". The bollard creaks softly as the water laps against the dock"
        }));

    addSeasonDescription("spring", ({
        " with new ropes and fresh paint marking the start of the season",
        " where seabirds nest nearby, their calls filling the air",
        " as the bollard is surrounded by blooming wildflowers along the dock",
        " with the scent of fresh growth mingling with salt and tar",
        " as gentle breezes carry the promise of warmer days"
        }));
    addSeasonDescription("summer", ({
        " with the sun warming the iron and ropes drying quickly",
        " where children play nearby, splashing in the water",
        " as the bollard is busy with boats coming and going all day",
        " with the air humming with laughter and the sounds of summer",
        " as the bollard stands firm through the busiest season"
        }));
    addSeasonDescription("autumn", ({
        " with fallen leaves collecting at its base",
        " where the bollard is battered by choppy water and cool winds",
        " as the dock grows quieter and the bollard sees fewer boats",
        " with the scent of woodsmoke drifting from nearby fires",
        " as the bollard stands sentinel through the changing season"
        }));
    addSeasonDescription("winter", ({
        " with frost riming the iron and ropes stiff with cold",
        " where only the hardiest sailors tie off their boats",
        " as ice forms along the dock and the bollard stands nearly unused",
        " with the sound of waves muffled by snow and the air biting cold",
        " as lanterns glow warmly against the long winter nights"
        }));

    addNearDarkDescriptionTemplate(
        "the silhouette of a mooring bollard stands at the edge of the dock"
    );
    addLowLightDescriptionTemplate(
        "the outline of a weathered bollard, ropes coiled at its base"
    );
    addDimLightDescriptionTemplate(
        "a sturdy iron bollard with thick ropes tied around it"
    );
    addSomeLightDescriptionTemplate(
        "a weathered iron bollard stands at the dock's edge, ropes securing "
        "boats nearby"
    );
    addItemTemplate(
        "The bollard is a heavy iron post set firmly into the dock. Thick ropes "
        "are looped around it, securing boats of all sizes. The iron is scarred "
        "by years of use, and the bollard stands as a silent witness to the "
        "comings and goings of the harbor."
    );
}
