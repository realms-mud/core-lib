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
    addResearchElement("guilds/aegis-guard/forms/bow/bregol-adleg.c");

    addChild("guilds/aegis-guard/forms/bow/peleth-eithad.c",
        "guilds/aegis-guard/forms/bow/root.c");
    addChild("guilds/aegis-guard/forms/bow/bregol-adleg.c",
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
    addResearchElement("guilds/aegis-guard/forms/bow/bregol-pilin.c");

    addChild("guilds/aegis-guard/forms/bow/bregol-pilin.c",
        "guilds/aegis-guard/forms/bow/bregol-adleg.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/bregol-gwaelphilin.c");
    addResearchElement("guilds/aegis-guard/forms/bow/angol-ai-cu.c");

    addChild("guilds/aegis-guard/forms/bow/bregol-gwaelphilin.c",
        "guilds/aegis-guard/forms/bow/bregol-adleg.c");
    addChild("guilds/aegis-guard/forms/bow/angol-ai-cu.c",
        "guilds/aegis-guard/forms/bow/bregol-adleg.c");
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
private void FifteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/alag-pilin.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-anwar.c");

    addChild("guilds/aegis-guard/forms/bow/alag-pilin.c",
        "guilds/aegis-guard/forms/bow/bregol-pilin.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-anwar.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/lhegren-gwaelphilin.c");

    addChild("guilds/aegis-guard/forms/bow/lhegren-gwaelphilin.c",
        "guilds/aegis-guard/forms/bow/bregol-gwaelphilin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/cu-ai-celair.c");

    addChild("guilds/aegis-guard/forms/bow/cu-ai-celair.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/gwaelphilin-celair.c");

    addChild("guilds/aegis-guard/forms/bow/gwaelphilin-celair.c",
        "guilds/aegis-guard/forms/bow/angol-ai-cu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/megor-pilin.c");

    addChild("guilds/aegis-guard/forms/bow/megor-pilin.c",
        "guilds/aegis-guard/forms/bow/alag-pilin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/dagnir-gwaelphilin.c");

    addChild("guilds/aegis-guard/forms/bow/dagnir-gwaelphilin.c",
        "guilds/aegis-guard/forms/bow/lhegren-gwaelphilin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/lhegren-pilin.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-celair.c");

    addChild("guilds/aegis-guard/forms/bow/lhegren-pilin.c",
        "guilds/aegis-guard/forms/bow/megor-pilin.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-celair.c",
        "guilds/aegis-guard/forms/bow/pilin-anwar.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/gwaelphilin-edlothia.c");
    addResearchElement("guilds/aegis-guard/forms/bow/cu-ai-edlothia.c");

    addChild("guilds/aegis-guard/forms/bow/gwaelphilin-edlothia.c",
        "guilds/aegis-guard/forms/bow/gwaelphilin-celair.c");
    addChild("guilds/aegis-guard/forms/bow/cu-ai-edlothia.c",
        "guilds/aegis-guard/forms/bow/cu-ai-celair.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/goeol-pilin.c");

    addChild("guilds/aegis-guard/forms/bow/goeol-pilin.c",
        "guilds/aegis-guard/forms/bow/lhegren-pilin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/maethor-gwaelphilin.c");

    addChild("guilds/aegis-guard/forms/bow/maethor-gwaelphilin.c",
        "guilds/aegis-guard/forms/bow/dagnir-gwaelphilin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/dagnir-pilin.c");

    addChild("guilds/aegis-guard/forms/bow/dagnir-pilin.c",
        "guilds/aegis-guard/forms/bow/goeol-pilin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/gwaelphilin-manadh.c");
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-edlothia.c");

    addChild("guilds/aegis-guard/forms/bow/gwaelphilin-manadh.c",
        "guilds/aegis-guard/forms/bow/gwaelphilin-edlothia.c");
    addChild("guilds/aegis-guard/forms/bow/pilin-edlothia.c",
        "guilds/aegis-guard/forms/bow/pilin-celair.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/maethor-pilin.c");
    addResearchElement("guilds/aegis-guard/forms/bow/cu-ai-manadh.c");

    addChild("guilds/aegis-guard/forms/bow/maethor-pilin.c",
        "guilds/aegis-guard/forms/bow/dagnir-pilin.c");
    addChild("guilds/aegis-guard/forms/bow/cu-ai-manadh.c",
        "guilds/aegis-guard/forms/bow/cu-ai-edlothia.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/gwaelphilin-dagnir.c");

    addChild("guilds/aegis-guard/forms/bow/gwaelphilin-dagnir.c",
        "guilds/aegis-guard/forms/bow/gwaelphilin-manadh.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-eiliant.c");

    addChild("guilds/aegis-guard/forms/bow/pilin-eiliant.c",
        "guilds/aegis-guard/forms/bow/pilin-edlothia.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/cu-ai-dagnir.c");

    addChild("guilds/aegis-guard/forms/bow/cu-ai-dagnir.c",
        "guilds/aegis-guard/forms/bow/cu-ai-manadh.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-manadh.c");

    addChild("guilds/aegis-guard/forms/bow/pilin-manadh.c",
        "guilds/aegis-guard/forms/bow/pilin-eiliant.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/bow/pilin-dagnir.c");

    addChild("guilds/aegis-guard/forms/bow/pilin-dagnir.c",
        "guilds/aegis-guard/forms/bow/pilin-manadh.c");
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
        FifteenthLevel();
        SixteenthLevel();
        SeventeenthLevel();
        NineteenthLevel();
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
        FortyThirdLevel();
        FortyFifthLevel();
        FortySeventhLevel();
        FiftyFifthLevel();
        SixtyFifthLevel();
    }
}
