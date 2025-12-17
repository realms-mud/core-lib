//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/oneiromancer/psychic-siphon/mental-leech.c");

    addChild("/guilds/oneiromancer/psychic-siphon/mental-leech.c",
        "/guilds/oneiromancer/psychic-siphon/siphon-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/oneiromancer/psychic-siphon/drain-essence.c");

    addChild("/guilds/oneiromancer/psychic-siphon/drain-essence.c",
        "/guilds/oneiromancer/psychic-siphon/mental-leech.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/oneiromancer/psychic-siphon/improved-siphon.c");
    addResearchElement("/guilds/oneiromancer/psychic-siphon/life-tap.c");

    addChild("/guilds/oneiromancer/psychic-siphon/improved-siphon.c",
        "/guilds/oneiromancer/psychic-siphon/drain-essence.c");
    addChild("/guilds/oneiromancer/psychic-siphon/life-tap.c",
        "/guilds/oneiromancer/psychic-siphon/drain-essence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psychic-siphon/efficient-drain.c");

    addChild("/guilds/oneiromancer/psychic-siphon/efficient-drain.c",
        "/guilds/oneiromancer/psychic-siphon/improved-siphon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/oneiromancer/psychic-siphon/master-siphon.c");

    addChild("/guilds/oneiromancer/psychic-siphon/master-siphon.c",
        "/guilds/oneiromancer/psychic-siphon/efficient-drain.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Psychic Siphon");
    Description("This research tree provides knowledge of draining mental "
        "energy from enemies to restore the caster. These techniques allow "
        "the psion to sustain themselves in extended combat. Available only "
        "to psions and masters.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/psychic-siphon/siphon-root.c");
    TreeRoot("/guilds/oneiromancer/psychic-siphon/siphon-root.c");

    FirstLevel();
    FifthLevel();
    NinthLevel();
    ThirteenthLevel();
    SeventeenthLevel();
}
