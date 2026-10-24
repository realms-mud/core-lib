//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Recovery Cycle");
    addSpecification("source", "monk");
    addSpecification("description",
        "Trace the interval between absorbed blows. Opens "
        "stamina-to-spell-point conversion while warded and strengthens "
        "restorative techniques without altering their resource costs.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":3
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "initiate",
            "student",
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/ward-anatomy.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Ward Mending":2,
        "Breath Conversion":3,
        "Measured Renewal":3,
        "Vigilant Renewal":3,
        "Sheltering Touch":2
    ]));

    addSpecification("related research", ({
        "/guilds/monk/mana-shield/breath-conversion.c",
        "/guilds/monk/mana-shield/recovery-habit.c"
    }));
}
