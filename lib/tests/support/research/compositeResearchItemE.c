//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gittern bedazzlement");
    addSpecification("scope", "area");
    addSpecification("research type", "granted");
    addSpecification("composite research",
        "/lib/tests/support/research/compositeRoot.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "strings");
    addSpecification("default composite description",
        "Transition from chords G to Em");

    addSpecification("penalty to attack", 5);
    addSpecification("duration", 12);
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::shred##, '##CompositeSegment##'");
}
