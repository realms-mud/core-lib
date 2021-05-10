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

}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{

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

}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/ionization.c");

    addChild("/guilds/aeromancer/lightning/ionization.c",
        "/guilds/aeromancer/lightning/electrostatics.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{

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

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/aeromancer/lightning/electrostatic-induction.c");

    addChild("/guilds/aeromancer/lightning/electrostatic-induction.c",
        "/guilds/aeromancer/lightning/enhanced-discharge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{

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
