//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeResearchTemplate.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "ABAB (Verse/Chorus)");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of how to create songs structured as a pair of verse/chorus "
        "sections");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 3
        ]));
    addPrerequisite("/guilds/bard/compositions/aaa.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 25);

    addSpecification("segments", ({
        ([ "verse 1": ({ "lyric", "instrumental rhythm" }) ]),
        ([ "chorus 1": ({ "lyric", "chorus lyric", "instrumental rhythm" }) ]),
        ([ "verse 2": ({ "lyric", "instrumental rhythm" }) ]),
        ([ "chorus 2": ({ "lyric", "chorus lyric", "instrumental rhythm" }) ]),
    }));            

    addSpecification("event handler", "verseChorusEvent");

    addSpecification("affected research", ([
        "Inspiring Lyrics": 10,
        "Muse's Melody": 10,
        "Tune of the Muse": 10,
        "Daedrun's Fury": 10,
    ]));
    addSpecification("affected research type", "percentage");
}
