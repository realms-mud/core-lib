//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Contact Geometry");
    addSpecification("source", "monk");
    addSpecification("description",
        "Observe the small differences between a glancing touch "
        "and a settled impact. The mace teaches its geometry "
        "through the angle of the wrist and the turn of the hips.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":50
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "senior disciple",
        "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/taxing-contact.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Compact Blow":10,
        "Centerline Crush":10
    ]));
}
