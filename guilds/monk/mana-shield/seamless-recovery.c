//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Seamless Recovery");
    addSpecification("source", "monk");
    addSpecification("description",
        "There is no longer a seam between vigilance and repose. Breath "
        "flows through both, and the shield follows it without a falter, "
        "even as your attention turns from shelter to renewal.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":62
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/renewing-rhythm.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/inner-refuge.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Vigilant Renewal":10,
        "Shelter of Intent":8
    ]));
}
