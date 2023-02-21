//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/laiga-utha.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/laiga-utha.c",
        "/guilds/aegis-guard/forms/sword-evading/evade-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/sa-pad.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/sa-pad.c",
        "/guilds/aegis-guard/forms/sword-evading/laiga-utha.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c",
        "/guilds/aegis-guard/forms/sword-evading/sa-pad.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/thar-legol.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/thar-legol.c",
        "/guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/seidia-dyr.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/seidia-dyr.c",
        "/guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/pirin-tir.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/legol-imrath.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/pirin-tir.c",
        "/guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c");
    addChild("/guilds/aegis-guard/forms/sword-evading/legol-imrath.c",
        "/guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/edluc.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/gwaedrhen.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/edluc.c",
        "/guilds/aegis-guard/forms/sword-evading/pirin-tir.c");
    addChild("/guilds/aegis-guard/forms/sword-evading/gwaedrhen.c",
        "/guilds/aegis-guard/forms/sword-evading/seidia-dyr.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/dagnir-rhinc.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/dagnir-rhinc.c",
        "/guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/pirin-maed-tir.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/pirin-maed-tir.c",
        "/guilds/aegis-guard/forms/sword-evading/pirin-tir.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/nista-ai-mab.c");

    addChild("/guilds/aegis-guard/forms/sword-evading/nista-ai-mab.c",
        "/guilds/aegis-guard/forms/sword-evading/pirin-tir.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Pelthaes ai Megil");
    Description("");
    Source("Aegis Guard");
    addResearchElement("/guilds/aegis-guard/forms/sword-evading/evade-root.c");
    TreeRoot("/guilds/aegis-guard/forms/sword-evading/evade-root.c");

    ThirdLevel();
    SeventhLevel();
    ThirteenthLevel();
    SixteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtiethLevel();
}
