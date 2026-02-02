//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Guardian Fortitude I");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research enhances the vitality "
        "of your summoned flame guardian.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 3
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/divine-conflagration/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c",
    }));
}
