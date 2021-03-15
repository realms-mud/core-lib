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
        addSpecification("name", "Lyric of doom");
        addSpecification("source", "blarg");
        addSpecification("composite research",
            "lib/tests/support/research/compositeRoot.c");
        addSpecification("composite type", "lyric");
        addSpecification("default composite description",
            "Doom, doom... the broom explodified the room.");

        addSpecification("description", "This is limited active research");
        addSpecification("usage summary", "This lyrically blargifies stuff.");
        addSpecification("scope", "area");
        addSpecification("research type", "granted");
        addSpecification("research cost", 1);
        addSpecification("penalty to intelligence", 2);
        addSpecification("duration", 12);
        addSpecification("use composite message", "##InitiatorName## ##Infinitive::squeal##, '##CompositeSegment##'");
    }
}
