//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/oneiromancer/mental-bastion/iron-will.c");

    addChild("/guilds/oneiromancer/mental-bastion/iron-will.c",
        "/guilds/oneiromancer/mental-bastion/bastion-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/oneiromancer/mental-bastion/thought-shield.c");
    addResearchElement("/guilds/oneiromancer/mental-bastion/mental-armor.c");

    addChild("/guilds/oneiromancer/mental-bastion/thought-shield.c",
        "/guilds/oneiromancer/mental-bastion/iron-will.c");
    addChild("/guilds/oneiromancer/mental-bastion/mental-armor.c",
        "/guilds/oneiromancer/mental-bastion/iron-will.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/oneiromancer/mental-bastion/psychic-barrier.c");

    addChild("/guilds/oneiromancer/mental-bastion/psychic-barrier.c",
        "/guilds/oneiromancer/mental-bastion/thought-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/mental-bastion/fortified-mind.c");
    addResearchElement("/guilds/oneiromancer/mental-bastion/resilient-psyche.c");

    addChild("/guilds/oneiromancer/mental-bastion/fortified-mind.c",
        "/guilds/oneiromancer/mental-bastion/psychic-barrier.c");
    addChild("/guilds/oneiromancer/mental-bastion/resilient-psyche.c",
        "/guilds/oneiromancer/mental-bastion/mental-armor.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/oneiromancer/mental-bastion/impenetrable-mind.c");

    addChild("/guilds/oneiromancer/mental-bastion/impenetrable-mind.c",
        "/guilds/oneiromancer/mental-bastion/fortified-mind.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Mental Bastion");
    Description("This research tree provides knowledge of fortifying the "
        "mind against attack. These techniques improve mental and magical "
        "resistance. Available only to mentalists and higher ranks.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/mental-bastion/bastion-root.c");
    TreeRoot("/guilds/oneiromancer/mental-bastion/bastion-root.c");

    FirstLevel();
    FifthLevel();
    NinthLevel();
    ThirteenthLevel();
    SeventeenthLevel();
}
