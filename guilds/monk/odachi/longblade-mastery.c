//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Longblade Mastery");
    addSpecification("source", "monk");
    addSpecification("description",
        "The practice sword that once ruled your posture now "
        "follows it. From the placement of a toe to the last tremor "
        "of the tip, the odachi has become an unbroken intention.");

    addSpecification("limited by", ([
        "equipment":([
            "blueprint":"odachi",
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":63
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/odachi/longblade-composure.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/odachi/longblade-return-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("bonus two-handed sword", 6);
}
