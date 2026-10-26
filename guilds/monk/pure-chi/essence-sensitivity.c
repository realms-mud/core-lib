//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Essence Sensitivity");
    addSpecification("source", "monk");
    addSpecification("description",
        "Learn to feel the grain of chi as a carpenter feels the grain "
        "of wood. What once seemed shapeless reveals fine currents "
        "that yield willingly to a patient touch.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":4
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/chi-anatomy.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("bonus magical essence", 2);
}
