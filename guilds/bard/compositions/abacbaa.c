//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeResearchTemplate.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "ABACBAA (Chorus/Verse/Chorus/Bridge)");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of how to create songs structured as a chorus, an "
        "instrumental, a verse, pre-chorus, chorus, a bridge, a verse "
        "breakdown, a chorus, and an outro.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 15
        ]));
    addPrerequisite("guilds/bard/compositions/ababcb.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);
    addSpecification("stamina point cost", 75);

    addSpecification("segments", ({ 
        (["chorus 1": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["instrumental": ({ "instrumental solo" })]),
        (["verse 1": ({ "lyric", "instrumental rhythm" })]),
        (["pre-chorus": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["chorus 2": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["bridge": ({ "lyric", "instrumental rhythm" })]),
        (["breakdown": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 3": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["outro": ({ "instrumental rhythm", "instrumental solo" })]),
    }));   

    addSpecification("event handler", "abacbaaEvent");
    addSpecification("affected research", ([
        "Dueler's Dance": 10,
        "Archer's Jig": 10,
        "Axeman's Song": 10,
        "Maceman's Melody": 10,
        "Swordmaster's Serenade": 10,
    ]));
    addSpecification("affected research type", "percentage");
}
