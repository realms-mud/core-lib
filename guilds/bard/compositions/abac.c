//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeResearchTemplate.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "ABAC (4 eight bar sections)");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of how to create songs structured as four 8-bar sections, "
        "the first and third being musically identical.");

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
        (["verse 1": ({ "lyric", "instrumental rhythm" })]),
        (["chorus 1": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
        (["verse 2": ({ "lyric", "instrumental rhythm" })]),
        (["bridge": ({ "lyric", "instrumental rhythm" })]),
    }));
    addSpecification("event handler", "abacEvent");

    addSpecification("affected research", ([
        "Demoralizing Lyrics": 10,
        "Daedrun's Lament": 10,
    ]));
    addSpecification("affected research type", "percentage");
}
