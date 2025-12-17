//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psychic Siphon");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides fundamental "
        "knowledge of draining psychic energy from others.");

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "psion", "master" })
        ]));

    addSpecification("research type", "tree root");
}
