//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin room");

    addAdjectives(({
        "derelict chamber with walls crumbling into piles of broken stone",
        "abandoned room where a partially collapsed ceiling lets in rain and light",
        "ruined chamber where fragments of furniture hint at its former function",
        "decayed room with faded frescoes still visible on less damaged walls",
        "forgotten chamber where weeds push through cracks in the tiled floor",
        "deteriorating room where support beams sag dangerously overhead",
        "neglected chamber where wind has blown leaves into dusty corners",
        "shattered room where broken glass from windows crunches underfoot",
        "weathered chamber where water damage has warped what wooden elements remain",
        "broken room where the remnants of shelving cling precariously to one wall",
        "decaying chamber where centuries of leaking water have carved channels in stone",
        "skeletal room where only the stone framework hints at its original shape",
        "time-ravaged chamber where wildlife has made homes in the quietest corners",
        "crumbling room where the floor has subsided toward one damaged wall",
        "hollow chamber where echoes amplify the sounds of structural settling",
        "faded room where the outlines of missing furniture can be seen in the dust",
        "vacant chamber where nothing remains but debris and broken stonework",
        "silent room where the only movement is dust motes floating in light beams",
        "ghostly chamber with niches and alcoves now emptied of their treasures",
        "crumbling room where generations of spiders have woven webs across corners"
    }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a room shrouded in darkness where only the vaguest outlines of walls "
        "and openings can be discerned. The sound of small creatures scuttling "
        "across unseen surfaces occasionally breaks the oppressive silence"
    );

    addLowLightDescriptionTemplate(
        "a dimly visible chamber where shadows hide most details, though the "
        "scattered outlines of fallen stones and architectural fragments loom "
        "like strange sentinels in the murk"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where just enough light filters in to reveal "
        "the decay that has claimed what was once an enclosed interior space. "
        "Shadows gather in corners and crevices, obscuring potential hazards"
    );

    addSomeLightDescriptionTemplate(
        "a well-illuminated ##Adjective##. The light exposes every detail of the "
        "destruction - the structural failure, the weathering of exposed surfaces, "
        "and the slow reclamation by nature of what was once a carefully constructed "
        "space. Despite the ruin, hints of its original purpose and design remain"
    );
}
