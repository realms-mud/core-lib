//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeResearchTemplate.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Simple Ballad");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of how to create songs structured as simple 32-bar ballads.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 5
        ]));
    addPrerequisite("/guilds/bard/compositions/aaa.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 35);

    addSpecification("segments", ({
        (["intro": ({ "instrumental rhythm", "instrumental solo" })]),
        (["verse 1": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 1": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["verse 2": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 2": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["outro": ({ "instrumental rhythm", "instrumental solo" })]),
    }));   

    addSpecification("event handler", "simpleBalladEvent");

    addSpecification("affected research", ([
        "Lay of Landros": 10,
        "Song for Aelin": 10,
        "Ballad of Mynstra": 10,
    ]));
    addSpecification("affected research type", "percentage");
}
