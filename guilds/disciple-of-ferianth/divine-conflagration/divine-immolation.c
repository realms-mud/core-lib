//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Immolation");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research grants your flame "
        "guardian the Divine Immolation ability - a devastating attack "
        "that channels Ferianth's holy fire.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 37
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/divine-conflagration/blazing-wrath.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c",
    }));
}
