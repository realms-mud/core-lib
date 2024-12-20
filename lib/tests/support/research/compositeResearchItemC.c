//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Singy blast");
    addSpecification("source", "blarg");
    addSpecification("composite research", 
        "/lib/tests/support/research/compositeRoot.c");
    addSpecification("composite type", "lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "Sing me a singy blast");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: plucked" }) ]));

    addSpecification("description", "This is limited active research");
    addSpecification("usage summary", "This lyrically blargifies stuff.");
    addSpecification("scope", "area");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);

    addSpecification("penalty to strength", 2);
    addSpecification("duration", 30);

    addSpecification("event handler", "usedResearchEvent");
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::yowl##, '##CompositeSegment##'");
}
