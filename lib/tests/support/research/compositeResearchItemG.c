//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gittern Attack!");
    addSpecification("scope", "self");
    addSpecification("research type", "granted");
    addSpecification("composite research",
        "/lib/tests/support/research/compositeRoot.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "strings");
    addSpecification("default composite description",
        "Arpeggio-wanking for fun.");

    addSpecification("limited by", ([
        "equipment":({ "instrument: plucked", "instrument: bowed" }),
    ]));

    addSpecification("bonus sonic attack", 15);
    addSpecification("duration", 4);
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::riff##, '##CompositeSegment##'");
}
