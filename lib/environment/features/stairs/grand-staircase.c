//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("grand staircase");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("staircase");
    addAlias("stair");
    addAlias("grand");

    addAdjectives(({ "of polished marble with ornate balustrades",
        "that sweeps majestically between levels",
        "with elaborately carved stone railings",
        "decorated with intricate sculptural details",
        "that dominates the great hall",
        "with red carpet runners secured by brass rods",
        "featuring newel posts topped with carved lions",
        "that divides into twin curving flights" }));

    addDescriptionTemplate("a grand staircase ##Adjective## "
        "commands attention as the centerpiece of the hall");
    addSomeLightDescriptionTemplate("a grand staircase ##Adjective## "
        "flows between levels in magnificent splendor");
    addNearDarkDescriptionTemplate("a massive staircase can be sensed "
        "rising majestically in the darkness");
    addLowLightDescriptionTemplate("an impressive staircase "
        "with ornate details connects the levels");
    addDimLightDescriptionTemplate("a grand staircase ##Adjective## "
        "links floors with architectural grandeur");
    addSourceOfLight(2);

    addItemTemplate("The grand staircase represents the pinnacle of "
        "architectural achievement, with each element crafted to inspire "
        "awe and demonstrate wealth. Polished stone steps wide enough "
        "for multiple people flow beneath elaborately carved balustrades. "
        "Every detail speaks of master craftsmen and unlimited resources, "
        "from the sculptural newel posts to the intricate moldings that "
        "frame this monument to artistic ambition.");
}
