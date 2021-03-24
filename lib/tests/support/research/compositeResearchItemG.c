//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        persistedActiveResearchItem::reset(arg);
        addSpecification("name", "Gittern Attack!");
        addSpecification("scope", "self");
        addSpecification("research type", "granted");
        addSpecification("composite research",
            "lib/tests/support/research/compositeRoot.c");
        addSpecification("composite type", "instrumental rhythm");
        addSpecification("default composite description",
            "Arpeggio-wanking for fun.");

        addSpecification("limited by", ([
            "equipment":({ "instrument: plucked", "instrument: bowed" }),
        ]));

        addSpecification("bonus sonic attack", 15);
        addSpecification("duration", 4);
        addSpecification("use composite message", "##InitiatorName## ##Infinitive::riff##, '##CompositeSegment##'");
    }
}
