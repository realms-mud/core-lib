//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grounded Footwork");
    addSpecification("source", "monk");
    addSpecification("description",
        "Return the feet beneath the weapon instead of reaching "
        "after it. A grounded stance leaves the body ready "
        "when the weight of the exchange comes back toward you.");

    addSpecification("limited by", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":4
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/impact-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");

    addSpecification("bonus defense", 1);
}
