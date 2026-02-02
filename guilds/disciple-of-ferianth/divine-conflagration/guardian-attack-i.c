//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Guardian Attack I");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research enhances the attack "
        "accuracy of your summoned flame guardian.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 7
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/divine-conflagration/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c",
    }));
}
