//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/an-alag.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/an-alag.c",
        "/guilds/aegis-guard/forms/sword-combinations/combination-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/godramin.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/godramin.c",
        "/guilds/aegis-guard/forms/sword-combinations/combination-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/heleg-alag.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/heleg-alag.c",
        "/guilds/aegis-guard/forms/sword-combinations/godramin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/thel-hannas.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/thel-hannas.c",
        "/guilds/aegis-guard/forms/sword-combinations/combination-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/laeg-hannas.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/laeg-hannas.c",
        "/guilds/aegis-guard/forms/sword-combinations/thel-hannas.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/tad-godref.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/tad-godref.c",
        "/guilds/aegis-guard/forms/sword-combinations/godramin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/heleg-bronadui.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/heleg-bronadui.c",
        "/guilds/aegis-guard/forms/sword-combinations/heleg-alag.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/bronadui-hannas.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/bronadui-hannas.c",
        "/guilds/aegis-guard/forms/sword-combinations/thel-hannas.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/golwen-alag.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/golwen-alag.c",
        "/guilds/aegis-guard/forms/sword-combinations/an-alag.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/neledh-godref.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/neledh-godref.c",
        "/guilds/aegis-guard/forms/sword-combinations/tad-godref.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/heleg-golwen.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/heleg-golwen.c",
        "/guilds/aegis-guard/forms/sword-combinations/heleg-bronadui.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/tur-godref.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/tur-godref.c",
        "/guilds/aegis-guard/forms/sword-combinations/neledh-godref.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-combinations/heleg-godref.c");

    addChild("/guilds/aegis-guard/forms/sword-combinations/heleg-godref.c",
        "/guilds/aegis-guard/forms/sword-combinations/heleg-golwen.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Godrebh ai Megil");
    Description("");
    Source("Aegis Guard");
    addResearchElement(
        "/guilds/aegis-guard/forms/sword-combinations/combination-root.c");
    TreeRoot(
        "/guilds/aegis-guard/forms/sword-combinations/combination-root.c");

    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    FortyThirdLevel();
}
