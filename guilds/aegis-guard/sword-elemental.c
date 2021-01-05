//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/ambar.c");
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/gwaeren.c");
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/lhorn.c");
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/naurtho.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/ambar.c",
        "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");
    addChild("guilds/aegis-guard/forms/sword-elemental/gwaeren.c",
        "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");
    addChild("guilds/aegis-guard/forms/sword-elemental/lhorn.c",
        "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");
    addChild("guilds/aegis-guard/forms/sword-elemental/naurtho.c",
        "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/geilo.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/geilo.c",
        "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/angol-anwar.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/angol-anwar.c",
        "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");

}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/heleg-celair.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/heleg-celair.c",
        "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/faen-celair.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/faen-celair.c",
        "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/angol-celair.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/angol-celair.c",
        "guilds/aegis-guard/forms/sword-elemental/angol-anwar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/heleg-edlothia.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/heleg-edlothia.c",
        "guilds/aegis-guard/forms/sword-elemental/heleg-celair.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/faen-edlothia.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/faen-edlothia.c",
        "guilds/aegis-guard/forms/sword-elemental/faen-celair.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/angol-edlothia.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/angol-edlothia.c",
        "guilds/aegis-guard/forms/sword-elemental/angol-celair.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/heleg-manadh.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/heleg-manadh.c",
        "guilds/aegis-guard/forms/sword-elemental/heleg-edlothia.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/faen-manadh.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/faen-manadh.c",
        "guilds/aegis-guard/forms/sword-elemental/faen-edlothia.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/angol-eiliant.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/angol-eiliant.c",
        "guilds/aegis-guard/forms/sword-elemental/angol-edlothia.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/heleg-dagnir.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/heleg-dagnir.c",
        "guilds/aegis-guard/forms/sword-elemental/heleg-manadh.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/faen-dagnir.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/faen-dagnir.c",
        "guilds/aegis-guard/forms/sword-elemental/faen-manadh.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/angol-manadh.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/angol-manadh.c",
        "guilds/aegis-guard/forms/sword-elemental/angol-eiliant.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-elemental/angol-dagnir.c");

    addChild("guilds/aegis-guard/forms/sword-elemental/angol-dagnir.c",
        "guilds/aegis-guard/forms/sword-elemental/angol-manadh.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Manadh ai Megil");
        Description("");
        Source("Aegis Guard");
        addResearchElement(
            "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");
        TreeRoot(
            "guilds/aegis-guard/forms/sword-elemental/elemental-root.c");

        EleventhLevel();
        ThirteenthLevel();
        FifteenthLevel();
        SixteenthLevel();
        SeventeenthLevel();
        NineteenthLevel();
        TwentiethLevel();
        TwentyThirdLevel();
        TwentyFifthLevel();
        TwentySeventhLevel();
        TwentyNinthLevel();
        ThirtiethLevel();
        ThirtyFirstLevel();
        ThirtyFifthLevel();
        ThirtySeventhLevel();
        ThirtyNinthLevel();
        FortyFifthLevel();
        FortySeventhLevel();
        FortyNinthLevel();
        FiftyFifthLevel();
        SixtyFifthLevel();
    }
}
