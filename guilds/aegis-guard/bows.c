//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/beria-an-cu.c");

    addChild("guilds/aegis-guard/forms/bow/beria-an-cu.c",
        "guilds/aegis-guard/forms/bow/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/caro-tithen.c");

    addChild("guilds/aegis-guard/forms/bow/caro-tithen.c",
        "guilds/aegis-guard/forms/bow/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/peleth-eithad.c");

    addChild("guilds/aegis-guard/forms/bow/peleth-eithad.c",
        "guilds/aegis-guard/forms/bow/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/adleg.c");

    addChild("guilds/aegis-guard/forms/bow/adleg.c",
        "guilds/aegis-guard/forms/bow/peleth-eithad.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-ai-ambar.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-ai-angolo.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-ai-glauro.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-ai-guruthos.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-ai-heleg.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-ai-lhutha.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-ai-naurtho.c");

    addChild("guilds/aegis-guard/forms/bow/pilin-ai-ambar.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-ai-angolo.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-ai-glauro.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-ai-guruthos.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-ai-heleg.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-ai-lhutha.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-ai-naurtho.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/edwen-idh.c");

    addChild("guilds/aegis-guard/forms/bow/edwen-idh.c",
        "guilds/aegis-guard/forms/bow/adleg.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{

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

}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{

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
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Rad ai Fain Cu");
        Description("");
        Source("Aegis Guard");
        addResearchElement("guilds/aegis-guard/forms/bow/root.c");
        TreeRoot("guilds/aegis-guard/forms/bow/root.c");

        FirstLevel();
        SecondLevel();
        ThirdLevel();
        FourthLevel();
        FifthLevel();
        SixthLevel();
        SeventhLevel();
        EighthLevel();
        NinthLevel();
        TenthLevel();
        TwelfthLevel();
        ThirteenthLevel();
        FourteenLevel();
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
    }
}
