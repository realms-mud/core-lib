//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeResearchTemplate.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Verse/Chorus/Bridge");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of how to create songs structured as a pair of verse/chorus "
        "sections, a bridge, and a chorus.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 7
        ]));
    addPrerequisite("/guilds/bard/compositions/abab.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 25);

    addSpecification("segments", ({
        (["verse 1": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 1": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["verse 2": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 2": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["bridge": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 3": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
    }));   
    addSpecification("event handler", "verseChorusBridgeEvent");
    addSpecification("affected research", ([
        "Counterspell Knell": 10,
        "Blast Beat": 10,
        "Blessing of Bhelac": 10,
        "Bhelac's Tune": 10,
        "Rhythm of Landros": 10,
    ]));
    addSpecification("affected research type", "percentage");
}
