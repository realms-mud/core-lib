//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeResearchTemplate.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Verse/Pre-Chorus/Chorus");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of how to create songs structured as a pair of verse/chorus "
        "sections");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 5
        ]));
    addPrerequisite("guilds/bard/compositions/abab.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 25);

    addSpecification("segments", ({
        (["verse 1": ({ "lyric", "instrumental rhythm" })]),
        (["pre-chorus": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 1": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["verse 2": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 2": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
    }));   

    addSpecification("event handler", "versePreChorusEvent");

    addSpecification("affected research", ([
        "Snare of the Soldier": 10,
        "Percussive Blast": 10,
        "Drums of Doom": 10,
        "Drums of Dedication": 10,
        "Beat of the Broken": 10,
        "Mystic Rhythms": 10,
    ]));
    addSpecification("affected research type", "percentage");
}
