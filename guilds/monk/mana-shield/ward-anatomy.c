//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ward Anatomy");
    addSpecification("source", "monk");
    addSpecification("description",
        "Study how Mindful Ward diverts damage into spell points. Opens "
        "guarded recovery and watchful defenses without changing the ward's "
        "absorption ratio or reservation, and strengthens the recovery and "
        "countering techniques that follow.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":2
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
    addPrerequisite("/guilds/monk/discipline/initiates-discipline.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/mindful-ward.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Ward Mending":3,
        "Breath Conversion":1,
        "Measured Renewal":1,
        "Vigilant Renewal":1,
        "Deflecting Palm":1,
        "Interrupting Thread":1,
        "Stillpoint Rebuke":1
    ]));

    addSpecification("related research", ({
        "/guilds/monk/mana-shield/ward-mending.c",
        "/guilds/monk/mana-shield/sentry-focus.c"
    }));
}
