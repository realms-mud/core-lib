//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Staff Fulcrum");
    addSpecification("source", "monk");
    addSpecification("description",
        "Let the hands discover how the staff's center "
        "changes as it turns. Each new fulcrum offers "
        "a different answer to the weight beyond your grip.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":5
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/impact-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Sweeping Arc":1
    ]));
}
