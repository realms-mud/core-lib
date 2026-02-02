//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Wrath");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research grants your flame "
        "guardian the Blazing Wrath ability.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 25
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/divine-conflagration/searing-strikes.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c",
    }));
}
