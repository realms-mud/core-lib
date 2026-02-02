//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Guardian Attack III");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research greatly enhances the "
        "attack accuracy of your summoned flame guardian.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 31
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/divine-conflagration/guardian-attack-ii.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/disciple-of-ferianth/divine-conflagration/root.c",
    }));
}
