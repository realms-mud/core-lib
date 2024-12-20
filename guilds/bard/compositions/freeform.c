//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeResearchTemplate.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Freeform");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of how to create songs structured in a free-form manner - "
        "meaning that the only rule is that there are no rules.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 21
        ]));
    addPrerequisite("/guilds/bard/compositions/abacbaa.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 100);

    addSpecification("segments", ({
        (["section": ({ "lyric", "chorus lyric", "instrumental rhythm",
            "instrumental solo" })]),
    }));  

    addSpecification("affected research", ([
        "Elegy of Energy": 10,
        "Enchanting Ostinato": 10,
        "Tune of Temerity": 10,
        "Sanguine Solo": 10,
        "Raena's Lament": 10,
    ]));
    addSpecification("affected research type", "percentage");
    addSpecification("event handler", "freeformEvent");
}
