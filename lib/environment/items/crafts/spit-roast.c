//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("spit roast");
    addAlias("spit");
    addAlias("roasting spit");
    addAlias("turning spit");

    addAdjectives(({ "iron", "long", "greasy", "heavy", "blackened",
        "turning", "well-used", "dripping", "functional", "simple" }));

    addDescriptionTemplate("a ##Adjective## spit roast set over a cooking fire");

    addItemTemplate(
        "The spit roast is a long iron rod set on forked supports over a "
        "bed of coals, with a handle at one end for turning. Drippings "
        "fall into the fire with a hiss, sending up fragrant smoke. A "
        "catch pan beneath collects grease for basting. The iron is "
        "blackened and permanently greasy."
    );

    addSomeLightDescriptionTemplate(
        "a spit roast turns over glowing coals, drippings hissing in the "
        "fire"
    );
    addDimLightDescriptionTemplate(
        "an iron spit is visible over glowing coals, something turning "
        "on it"
    );
    addLowLightDescriptionTemplate(
        "a long shape spans a bed of glowing coals"
    );
    addNearDarkDescriptionTemplate(
        "the hiss of drippings and the smell of roasting meat fill the air"
    );
}
