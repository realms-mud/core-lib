//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/athra.c");

    addChild("guilds/aegis-guard/forms/sword-actions/athra.c",
        "guilds/aegis-guard/forms/sword-actions/action-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/celeg.c");

    addChild("guilds/aegis-guard/forms/sword-actions/celeg.c",
        "guilds/aegis-guard/forms/sword-actions/action-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/lanc.c");

    addChild("guilds/aegis-guard/forms/sword-actions/lanc.c",
        "guilds/aegis-guard/forms/sword-actions/action-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/gleina.c");

    addChild("guilds/aegis-guard/forms/sword-actions/gleina.c",
        "guilds/aegis-guard/forms/sword-actions/action-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/gling.c");

    addChild("guilds/aegis-guard/forms/sword-actions/gling.c",
        "guilds/aegis-guard/forms/sword-actions/action-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/raeg.c");

    addChild("guilds/aegis-guard/forms/sword-actions/raeg.c",
        "guilds/aegis-guard/forms/sword-actions/lanc.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/dadben.c");

    addChild("guilds/aegis-guard/forms/sword-actions/dadben.c",
        "guilds/aegis-guard/forms/sword-actions/athra.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/gliri.c");

    addChild("guilds/aegis-guard/forms/sword-actions/gliri.c",
        "guilds/aegis-guard/forms/sword-actions/raeg.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/delu-an-gling.c");

    addChild("guilds/aegis-guard/forms/sword-actions/delu-an-gling.c",
        "guilds/aegis-guard/forms/sword-actions/gling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/hwinio.c");

    addChild("guilds/aegis-guard/forms/sword-actions/hwinio.c",
        "guilds/aegis-guard/forms/sword-actions/lanc.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/delu-an-dadben.c");
    addResearchElement("guilds/aegis-guard/forms/sword-actions/beraid.c");

    addChild("guilds/aegis-guard/forms/sword-actions/delu-an-dadben.c",
        "guilds/aegis-guard/forms/sword-actions/dadben.c");
    addChild("guilds/aegis-guard/forms/sword-actions/beraid.c",
        "guilds/aegis-guard/forms/sword-actions/gliri.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/delu-an-gliri.c");

    addChild("guilds/aegis-guard/forms/sword-actions/delu-an-gliri.c",
        "guilds/aegis-guard/forms/sword-actions/gliri.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/delu-an-beraid.c");

    addChild("guilds/aegis-guard/forms/sword-actions/delu-an-beraid.c",
        "guilds/aegis-guard/forms/sword-actions/beraid.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/braig-an-gling.c");

    addChild("guilds/aegis-guard/forms/sword-actions/braig-an-gling.c",
        "guilds/aegis-guard/forms/sword-actions/delu-an-gling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/naergo.c");
    addResearchElement("guilds/aegis-guard/forms/sword-actions/bauglo.c");

    addChild("guilds/aegis-guard/forms/sword-actions/naergo.c",
        "guilds/aegis-guard/forms/sword-actions/beraid.c");
    addChild("guilds/aegis-guard/forms/sword-actions/bauglo.c",
        "guilds/aegis-guard/forms/sword-actions/beraid.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/braig-an-dadben.c");

    addChild("guilds/aegis-guard/forms/sword-actions/braig-an-dadben.c",
        "guilds/aegis-guard/forms/sword-actions/delu-an-dadben.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/braig-an-gliri.c");

    addChild("guilds/aegis-guard/forms/sword-actions/braig-an-gliri.c",
        "guilds/aegis-guard/forms/sword-actions/delu-an-gliri.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/braig-an-beraid.c");

    addChild("guilds/aegis-guard/forms/sword-actions/braig-an-beraid.c",
        "guilds/aegis-guard/forms/sword-actions/delu-an-beraid.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/tur-glingal.c");

    addChild("guilds/aegis-guard/forms/sword-actions/tur-glingal.c",
        "guilds/aegis-guard/forms/sword-actions/braig-an-gling.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/tur-dadben.c");

    addChild("guilds/aegis-guard/forms/sword-actions/tur-dadben.c",
        "guilds/aegis-guard/forms/sword-actions/braig-an-dadben.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/tur-gliraen.c");

    addChild("guilds/aegis-guard/forms/sword-actions/tur-gliraen.c",
        "guilds/aegis-guard/forms/sword-actions/braig-an-gliri.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-actions/tur-beraid.c");

    addChild("guilds/aegis-guard/forms/sword-actions/tur-beraid.c",
        "guilds/aegis-guard/forms/sword-actions/braig-an-beraid.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Hur ai Megil");
        Description("");
        Source("Aegis Guard");
        addResearchElement(
            "guilds/aegis-guard/forms/sword-actions/action-root.c");
        TreeRoot(
            "guilds/aegis-guard/forms/sword-actions/action-root.c");

        SeventhLevel();
        NinthLevel();
        EleventhLevel();
        ThirteenthLevel();
        FourteenLevel();
        FifteenthLevel();
        SeventeenthLevel();
        NineteenthLevel();
        TwentiethLevel();
        TwentyFirstLevel();
        TwentyThirdLevel();
        TwentyFifthLevel();
        TwentySeventhLevel();
        TwentyNinthLevel();
        ThirtiethLevel();
        ThirtyFirstLevel();
        ThirtyThirdLevel();
        ThirtyFifthLevel();
        ThirtySeventhLevel();
        ThirtyNinthLevel();
        FortyFirstLevel();
        FortyThirdLevel();
    }
}
