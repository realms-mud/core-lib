//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/auth.c");
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/sereg.c");
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/guruthos.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/auth.c",
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
    addChild("guilds/aegis-guard/forms/sword-mythic/sereg.c",
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
    addChild("guilds/aegis-guard/forms/sword-mythic/guruthos.c",
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/braig-celair.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/braig-celair.c",
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/tur-celair.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/tur-celair.c",
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/delu-anwar.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/delu-anwar.c",
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/lhutha.c");
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/angolo.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/lhutha.c",
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
    addChild("guilds/aegis-guard/forms/sword-mythic/angolo.c",
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/braig-edlothia.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/braig-edlothia.c",
        "guilds/aegis-guard/forms/sword-mythic/braig-celair.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/tur-edlothia.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/tur-edlothia.c",
        "guilds/aegis-guard/forms/sword-mythic/tur-celair.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/delu-celair.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/delu-celair.c",
        "guilds/aegis-guard/forms/sword-mythic/delu-anwar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/braig-manadh.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/braig-manadh.c",
        "guilds/aegis-guard/forms/sword-mythic/braig-edlothia.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/tur-manadh.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/tur-manadh.c",
        "guilds/aegis-guard/forms/sword-mythic/tur-edlothia.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/delu-edlothia.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/delu-edlothia.c",
        "guilds/aegis-guard/forms/sword-mythic/delu-celair.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/braig-dagnir.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/braig-dagnir.c",
        "guilds/aegis-guard/forms/sword-mythic/braig-manadh.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/tur-dagnir.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/tur-dagnir.c",
        "guilds/aegis-guard/forms/sword-mythic/tur-manadh.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/delu-eiliant.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/delu-eiliant.c",
        "guilds/aegis-guard/forms/sword-mythic/delu-edlothia.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/delu-manadh.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/delu-manadh.c",
        "guilds/aegis-guard/forms/sword-mythic/delu-eiliant.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-mythic/delu-dagnir.c");

    addChild("guilds/aegis-guard/forms/sword-mythic/delu-dagnir.c",
        "guilds/aegis-guard/forms/sword-mythic/delu-manadh.c");
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Arnen ai Megil");
    Description("");
    Source("Aegis Guard");
    addResearchElement(
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");
    TreeRoot(
        "guilds/aegis-guard/forms/sword-mythic/mythic-root.c");

    FifteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftyThirdLevel();
    FiftyFifthLevel();
    SixtyFifthLevel();
    SeventyFifthLevel();
}
