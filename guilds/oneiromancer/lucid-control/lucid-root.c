//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lucid Control");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides fundamental "
        "knowledge of maintaining conscious control while manipulating "
        "dream energy.");

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "adept", "mentalist", "psion", "master" })
        ]));

    addSpecification("research type", "tree root");
}
