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
        "Reset vigilance without interrupting restoration. Vigilant Renewal "
        "recovers ten seconds sooner and Shelter of Intent eight seconds "
        "sooner.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
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
