//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Disruption Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "Hostile magic announces itself in the weave before it reaches "
        "your flesh. Learn to untangle those foreign currents and turn "
        "their passage into a lesson in the shield's deeper structure.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":34
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/deflecting-palm.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/intent-reading.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Mana Shield":4,
        "Deflecting Palm":2,
        "Interrupting Thread":3,
        "Ward Counterpulse":3,
        "Stillpoint Rebuke":3
    ]));

    addSpecification("related research", ({
        "/guilds/monk/mana-shield/interrupting-thread.c",
        "/guilds/monk/mana-shield/ward-counterpulse.c"
    }));
}
