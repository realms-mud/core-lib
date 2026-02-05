//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/pyromancer/functions/heat.c");
    addResearchElement("/guilds/pyromancer/functions/flame.c");

    addChild("/guilds/pyromancer/functions/heat.c",
        "/guilds/pyromancer/functions/root.c");
    addChild("/guilds/pyromancer/functions/flame.c",
        "/guilds/pyromancer/functions/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/pyromancer/functions/combustion.c");

    addChild("/guilds/pyromancer/functions/combustion.c",
        "/guilds/pyromancer/functions/flame.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/pyromancer/functions/scorch.c");

    addChild("/guilds/pyromancer/functions/scorch.c",
        "/guilds/pyromancer/functions/flame.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/pyromancer/functions/inferno.c");

    addChild("/guilds/pyromancer/functions/inferno.c",
        "/guilds/pyromancer/functions/heat.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/pyromancer/functions/smoke.c");

    addChild("/guilds/pyromancer/functions/smoke.c",
        "/guilds/pyromancer/functions/combustion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/pyromancer/functions/searing.c");

    addChild("/guilds/pyromancer/functions/searing.c",
        "/guilds/pyromancer/functions/combustion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/pyromancer/functions/immolation.c");

    addChild("/guilds/pyromancer/functions/immolation.c",
        "/guilds/pyromancer/functions/searing.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/pyromancer/functions/conflagration.c");

    addChild("/guilds/pyromancer/functions/conflagration.c",
        "/guilds/pyromancer/functions/inferno.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/pyromancer/functions/magma.c");

    addChild("/guilds/pyromancer/functions/magma.c",
        "/guilds/pyromancer/functions/smoke.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/pyromancer/functions/hellfire.c");

    addChild("/guilds/pyromancer/functions/hellfire.c",
        "/guilds/pyromancer/functions/conflagration.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Spell Kinetics");
    Description("This research tree provides knowledge of the various damage "
        "types and propulsion mechanisms for constructed pyromancer spells.");
    Source("pyromancer");
    addResearchElement("/guilds/pyromancer/functions/root.c");
    TreeRoot("/guilds/pyromancer/functions/root.c");

    FirstLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
}
