//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Dominion");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides fundamental "
        "knowledge of exerting absolute dominion over the dream realm.");

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "master" })
        ]));

    addSpecification("research type", "tree root");
}
