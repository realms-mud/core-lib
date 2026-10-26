//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Guarded Ward Breath");
    addSpecification("source", "monk");
    addSpecification("description",
        "Breathe as though tending an ember in cupped hands. The shield "
        "keeps the outer world at a distance while you coax warmth into "
        "the places where pain has interrupted your rhythm.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":5
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/ward-anatomy.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/recovery-habit.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Ward Mending":1
    ]));
}
