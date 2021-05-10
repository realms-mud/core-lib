//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/shock.c");

    addChild("/guilds/aeromancer/lightning/shock.c",
        "/guilds/aeromancer/lightning/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/shocking-lash.c");

    addChild("/guilds/aeromancer/lightning/shocking-lash.c",
        "/guilds/aeromancer/lightning/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/thunderclap.c");

    addChild("/guilds/aeromancer/lightning/thunderclap.c",
        "/guilds/aeromancer/lightning/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/shocking-mist.c");

    addChild("/guilds/aeromancer/lightning/shocking-mist.c",
        "/guilds/aeromancer/lightning/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/discharge.c");
    addResearchElement("/guilds/aeromancer/lightning/lightning-blades.c");
    addResearchElement("/guilds/aeromancer/lightning/lightning-bolt.c");

    addChild("/guilds/aeromancer/lightning/discharge.c",
        "/guilds/aeromancer/lightning/shock.c");
    addChild("/guilds/aeromancer/lightning/lightning-blades.c",
        "/guilds/aeromancer/lightning/root.c");
    addChild("/guilds/aeromancer/lightning/lightning-bolt.c",
        "/guilds/aeromancer/lightning/shock.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/boltmasters-reserve.c");

    addChild("/guilds/aeromancer/lightning/boltmasters-reserve.c",
        "/guilds/aeromancer/lightning/lightning-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/boltmasters-boon.c");
    addResearchElement("/guilds/aeromancer/lightning/electric-whip.c");

    addChild("/guilds/aeromancer/lightning/boltmasters-boon.c",
        "/guilds/aeromancer/lightning/lightning-bolt.c");
    addChild("/guilds/aeromancer/lightning/electric-whip.c",
        "/guilds/aeromancer/lightning/shocking-lash.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/electrostatics.c");

    addChild("/guilds/aeromancer/lightning/electrostatics.c",
        "/guilds/aeromancer/lightning/discharge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/shocking-wave.c");

    addChild("/guilds/aeromancer/lightning/shocking-wave.c",
        "/guilds/aeromancer/lightning/shocking-mist.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/static-discharge.c");

    addChild("/guilds/aeromancer/lightning/static-discharge.c",
        "/guilds/aeromancer/lightning/lightning-bolt.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/ionization.c");
    addResearchElement("/guilds/aeromancer/lightning/boltmasters-call.c");

    addChild("/guilds/aeromancer/lightning/ionization.c",
        "/guilds/aeromancer/lightning/electrostatics.c");
    addChild("/guilds/aeromancer/lightning/boltmasters-call.c",
        "/guilds/aeromancer/lightning/boltmasters-reserve.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/boltmasters-finess.c");

    addChild("/guilds/aeromancer/lightning/boltmasters-finess.c",
        "/guilds/aeromancer/lightning/boltmasters-boon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/enhanced-discharge.c");

    addChild("/guilds/aeromancer/lightning/enhanced-discharge.c",
        "/guilds/aeromancer/lightning/ionization.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/ball-lightning.c");

    addChild("/guilds/aeromancer/lightning/ball-lightning.c",
        "/guilds/aeromancer/lightning/static-discharge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/boltmasters-might.c");

    addChild("/guilds/aeromancer/lightning/boltmasters-might.c",
        "/guilds/aeromancer/lightning/boltmasters-call.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/electrostatic-induction.c");
    addResearchElement("/guilds/aeromancer/lightning/boltmasters-endurance.c");

    addChild("/guilds/aeromancer/lightning/electrostatic-induction.c",
        "/guilds/aeromancer/lightning/enhanced-discharge.c");
    addChild("/guilds/aeromancer/lightning/boltmasters-endurance.c",
        "/guilds/aeromancer/lightning/boltmasters-finess.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/raging-tempest.c");

    addChild("/guilds/aeromancer/lightning/raging-tempest.c",
        "/guilds/aeromancer/lightning/ball-lightning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/enhanced-conductivity.c");

    addChild("/guilds/aeromancer/lightning/enhanced-conductivity.c",
        "/guilds/aeromancer/lightning/electrostatic-induction.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/boltmasters-fury.c");

    addChild("/guilds/aeromancer/lightning/boltmasters-fury.c",
        "/guilds/aeromancer/lightning/boltmasters-might.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/boltmasters-strength.c");

    addChild("/guilds/aeromancer/lightning/boltmasters-strength.c",
        "/guilds/aeromancer/lightning/boltmasters-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/electrostatic-condenser.c");

    addChild("/guilds/aeromancer/lightning/electrostatic-condenser.c",
        "/guilds/aeromancer/lightning/enhanced-conductivity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/corona-discharge.c");

    addChild("/guilds/aeromancer/lightning/corona-discharge.c",
        "/guilds/aeromancer/lightning/electrostatic-condenser.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/plasma-eruption.c");

    addChild("/guilds/aeromancer/lightning/plasma-eruption.c",
        "/guilds/aeromancer/lightning/corona-discharge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/flux-condenser.c");

    addChild("/guilds/aeromancer/lightning/flux-condenser.c",
        "/guilds/aeromancer/lightning/plasma-eruption.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Lightning");
    Description("");
    Source("aeromancer");
    addResearchElement("/guilds/aeromancer/lightning/root.c");
    TreeRoot("/guilds/aeromancer/lightning/root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftySeventhLevel();
    SixtyThirdLevel();
}
