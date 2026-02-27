//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("notice board");
    addAlias("board");
    addAlias("message board");
    addAlias("town board");

    addAdjectives(({ "weathered", "cluttered", "wooden", "tall", "public",
        "well-read", "nail-studded", "crowded", "faded", "official" }));

    addDescriptionTemplate("a ##Adjective## notice board covered in postings");

    addItemTemplate(
        "The notice board is a broad plank of oak set on a stout post, its "
        "surface bristling with iron nails from which hang notices, decrees, "
        "and requests. Some are fresh parchment with crisp ink; others are "
        "yellowed and curling, their messages long since irrelevant. A few "
        "have been pinned over others in the eternal competition for space."
    );

    addSomeLightDescriptionTemplate(
        "a notice board stands prominently, its surface covered in postings"
    );
    addDimLightDescriptionTemplate(
        "a notice board is visible, its cluttered surface hard to read"
    );
    addLowLightDescriptionTemplate(
        "a broad flat shape on a post suggests a notice board"
    );
    addNearDarkDescriptionTemplate(
        "a flat shape on a post is barely visible in the darkness"
    );
}
